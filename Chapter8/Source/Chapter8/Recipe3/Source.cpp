/* Binary Space Partition Tree*/


#include <vector>
#include <istream>
#include <ostream>
#include <assert.h>


// 
// struct sTreeAdaptor
// {
//     eBspRelation Classify( 
//         const T_PlaneDiv& plane, 
//         const T_elementType& elem ) const;
//
//     void Split( 
//         const T_PlaneDiv& plane, 
//         const T_elementType& elem, 
//         T_elementType* pFront,
//         T_elementType* pBack ) const;
// 
//     void ChooseHyperplane( 
//         std::vector<T_elementType>& toProcess, 
//         T_PlaneDiv* pPlane ) const;
// };


// Returned by the Classify method of the tree adaptor.
enum eBspRelation
{
	BSP_FRONT_SURFACE,
	BSP_BACK_SURFACE,
	BSP_SPLIT,
	BSP_COPLANAR
};


// This is a non-brep tree.  Used just for classification of
// polygons.  No leaves.
template< class T_elementType, class T_PlaneDiv, class T_Adaptor >
class cBSPTreePart
{
	// Other objects need to see what a node looks like.
public:
	struct sNode
	{
		typedef std::vector< T_elementType > elemVec;

		sNode* m_pFrontSurface;
		sNode* m_pBackSurface;

		elemVec m_values;
		T_PlaneDiv m_plane;

		sNode(elemVec& toProcess, const T_Adaptor& adap)
			: m_pFrontSurface(NULL)
			, m_pBackSurface(NULL)
		{
			// Setup
			elemVec frontVec, backVec;
			frontVec.reserve(toProcess.size());
			backVec.reserve(toProcess.size());

			// Choose which node we're going to use.
			adap.ChooseHyperplane(toProcess, &m_plane);

			// Iterate across the rest of the polygons
			elemVec::iterator iter = toProcess.begin();
			for (; iter != toProcess.end(); ++iter)
			{
				T_elementType front, back;
				switch (adap.Classify(m_plane, *iter))
				{
				case BSP_FRONT_SURFACE:
					frontVec.push_back(*iter);
					break;
				case BSP_BACK_SURFACE:
					backVec.push_back(*iter);
					break;
				case BSP_COPLANAR:
					m_values.push_back(*iter);
					break;
				case BSP_SPLIT:
					adap.Split(m_plane, *iter, &front, &back);
					frontVec.push_back(front);
					backVec.push_back(back);
					break;
				default: break;
				}
			}

			// Now recurse if necessary
			if (!frontVec.empty())
				m_pFrontSurface = new sNode(frontVec, adap);
			if (!backVec.empty())
				m_pBackSurface = new sNode(backVec, adap);
		}

		sNode(std::istream& in)
		{
			// First char is the child state 
			// (0x1 means front child, 0x2 means back child)
			int childState;
			in >> childState;

			// Next is the hyperplane for the node
			in >> m_plane;

			// Next is the number of elements in the node
			unsigned int nElem;
			in >> nElem;
			m_values.reserve(nElem);

			while (nElem--)
			{
				T_elementType elem;
				in >> elem;
				m_values.push_back(elem);
			}

			// recurse if we have children.
			if (childState & 0x1)
				m_pFrontSurface = new sNode(in);
			else
				m_pFrontSurface = NULL;
			if (childState & 0x2)
				m_pBackSurface = new sNode(in);
			else
				m_pBackSurface = NULL;
		}

		void Write(std::ostream& out)
		{
			// What is our child state?
			int childState = 0;
			if (m_pFrontSurface) childState += 1;
			if (m_pBackSurface) childState += 2;

			// write it out
			out << childState << " ";

			// Write out hp
			out << m_plane << " ";

			// now take care of the contents
			unsigned int nElem = m_values.size();
			out << nElem << " ";
			while (nElem--)
				out << m_values[nElem] << " ";

			// Finally deal with the children
			if (m_pFrontSurface)
				m_pFrontSurface->Write(out);
			if (m_pBackSurface)
				m_pBackSurface->Write(out);
		}

		~sNode()
		{
			delete m_pFrontSurface;
			delete m_pBackSurface;
		}
	};
protected:

	sNode* m_pRoot;
	T_Adaptor m_adap;

	std::vector< T_elementType > m_toBuild;

public:

	cBSPTreePart(T_Adaptor& adaptor = T_Adaptor())
		: m_adap(adaptor)
		, m_pRoot(NULL)
	{}

	sNode* GetRoot(){ return m_pRoot; }

	void AddElement(const T_elementType& elem)
	{
		bool bTreeAlreadyBuilt = (m_pRoot != NULL);
		assert(!bTreeAlreadyBuilt);

		m_toBuild.push_back(elem);
	}

	void BuildTree()
	{
		assert(m_toBuild.size());
		m_pRoot = new sNode(m_toBuild, m_adap);
	}

	void Read(std::istream& in)
	{
		// Shouldn't read in over a tree.
		assert(!m_pRoot);

		m_pRoot = new sNode(in);
	}

	void Write(std::ostream& out)
	{
		// Shouldn't write out a null tree
		assert(m_pRoot);

		m_pRoot->Write(out);
	}
};

int main()
{
	return 0;
}