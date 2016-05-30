/* Decision Making AI*/


#include <iostream>
#include <ctime>


using namespace std;

class TreeNodes
{
public:
	//tree node functions
	TreeNodes(int nodeID/*, string QA*/);
	TreeNodes();

	virtual ~TreeNodes();

	int m_NodeID;

	TreeNodes* PrimaryBranch;
	TreeNodes* SecondaryBranch;
};


//contrctor
TreeNodes::TreeNodes()
{
	PrimaryBranch = NULL;
	SecondaryBranch = NULL;

	m_NodeID = 0;
}

//deconstructor
TreeNodes::~TreeNodes()
{ }

//Step 3! Also step 7 hah!
TreeNodes::TreeNodes(int nodeID/*, string NQA*/)
{
	//create tree node with a specific node ID
	m_NodeID = nodeID;

	//reset nodes/make sure! that they are null. I wont have any funny business #s -_-
	PrimaryBranch = NULL;
	SecondaryBranch = NULL;
}

//the decision tree class
class DecisionTree
{
public:
	//functions
	void RemoveNode(TreeNodes* node);
	void DisplayTree(TreeNodes* CurrentNode);
	void Output();
	void Query();
	void QueryTree(TreeNodes* rootNode);
	void PrimaryNode(int ExistingNodeID, int NewNodeID);
	void SecondaryNode(int ExistingNodeID, int NewNodeID);
	void CreateRootNode(int NodeID);
	void MakeDecision(TreeNodes* node);

	bool SearchPrimaryNode(TreeNodes* CurrentNode, int ExistingNodeID, int NewNodeID);
	bool SearchSecondaryNode(TreeNodes* CurrentNode, int ExistingNodeID, int NewNodeID);

	TreeNodes* m_RootNode;

	DecisionTree();

	virtual ~DecisionTree();
};

int random(int upperLimit);

//for random variables that will effect decisions/node values/weights
int random(int upperLimit)
{
	int randNum = rand() % upperLimit;
	return randNum;
}

//constructor
//Step 1!
DecisionTree::DecisionTree()
{
	//set root node to null on tree creation
	//beginning of tree creation
	m_RootNode = NULL;
}

//destructor
//Final Step in a sense
DecisionTree::~DecisionTree()
{
	RemoveNode(m_RootNode);
}

//Step 2!
void DecisionTree::CreateRootNode(int NodeID)
{
	//create root node with specific ID
	// In MO, you may want to use thestatic creation of IDs like with entities. depends on how many nodes you plan to have
	//or have instantaneously created nodes/changing nodes
	m_RootNode = new TreeNodes(NodeID);
}

//Step 5.1!~
void DecisionTree::PrimaryNode(int ExistingNodeID, int NewNodeID)
{
	//check to make sure you have a root node. can't add another node without a root node
	if (m_RootNode == NULL)
	{
		cout << "ERROR - No Root Node";
		return;
	}

	if (SearchPrimaryNode(m_RootNode, ExistingNodeID, NewNodeID))
	{
		cout << "Added Node Type1 With ID " << NewNodeID << " onto Branch Level " << ExistingNodeID << endl;
	}
	else
	{
		//check
		cout << "Node: " << ExistingNodeID << " Not Found.";
	}
}

//Step 6.1!~ search and add new node to current node
bool DecisionTree::SearchPrimaryNode(TreeNodes *CurrentNode, int ExistingNodeID, int NewNodeID)
{
	//if there is a node
	if (CurrentNode->m_NodeID == ExistingNodeID)
	{
		//create the node
		if (CurrentNode->PrimaryBranch == NULL)
		{
			CurrentNode->PrimaryBranch = new TreeNodes(NewNodeID);
		}
		else
		{
			CurrentNode->PrimaryBranch = new TreeNodes(NewNodeID);
		}
		return true;
	}
	else
	{
		//try branch if it exists
		//for a third, add another one of these too!
		if (CurrentNode->PrimaryBranch != NULL)
		{
			if (SearchPrimaryNode(CurrentNode->PrimaryBranch, ExistingNodeID, NewNodeID))
			{
				return true;
			}
			else
			{
				//try second branch if it exists
				if (CurrentNode->SecondaryBranch != NULL)
				{
					return(SearchSecondaryNode(CurrentNode->SecondaryBranch, ExistingNodeID, NewNodeID));
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
}

//Step 5.2!~    does same thing as node 1.  if you wanted to have more decisions, 
//create a node 3 which would be the same as this maybe with small differences
void DecisionTree::SecondaryNode(int ExistingNodeID, int NewNodeID)
{
	if (m_RootNode == NULL)
	{
		cout << "ERROR - No Root Node";
	}

	if (SearchSecondaryNode(m_RootNode, ExistingNodeID, NewNodeID))
	{
		cout << "Added Node Type2 With ID " << NewNodeID << " onto Branch Level " << ExistingNodeID << endl;
	}
	else
	{
		cout << "Node: " << ExistingNodeID << " Not Found.";
	}
}

//Step 6.2!~ search and add new node to current node
//as stated earlier, make one for 3rd node if there was meant to be one
bool DecisionTree::SearchSecondaryNode(TreeNodes *CurrentNode, int ExistingNodeID, int NewNodeID)
{
	if (CurrentNode->m_NodeID == ExistingNodeID)
	{
		//create the node
		if (CurrentNode->SecondaryBranch == NULL)
		{
			CurrentNode->SecondaryBranch = new TreeNodes(NewNodeID);
		}
		else
		{
			CurrentNode->SecondaryBranch = new TreeNodes(NewNodeID);
		}
		return true;
	}
	else
	{
		//try branch if it exists
		if (CurrentNode->PrimaryBranch != NULL)
		{
			if (SearchSecondaryNode(CurrentNode->PrimaryBranch, ExistingNodeID, NewNodeID))
			{
				return true;
			}
			else
			{
				//try second branch if it exists
				if (CurrentNode->SecondaryBranch != NULL)
				{
					return(SearchSecondaryNode(CurrentNode->SecondaryBranch, ExistingNodeID, NewNodeID));
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
}

//Step 11
void DecisionTree::QueryTree(TreeNodes* CurrentNode)
{
	if (CurrentNode->PrimaryBranch == NULL)
	{
		//if both branches are null, tree is at a decision outcome state
		if (CurrentNode->SecondaryBranch == NULL)
		{
			//output decision 'question'
			///////////////////////////////////////////////////////////////////////////////////////
		}
		else
		{
			cout << "Missing Branch 1";
		}
		return;
	}
	if (CurrentNode->SecondaryBranch == NULL)
	{
		cout << "Missing Branch 2";
		return;
	}

	//otherwise test decisions at current node
	MakeDecision(CurrentNode);
}

//Step 10
void DecisionTree::Query()
{
	QueryTree(m_RootNode);
}

////////////////////////////////////////////////////////////
//debate decisions   create new function for decision logic

// cout << node->stringforquestion;

//Step 12
void DecisionTree::MakeDecision(TreeNodes *node)
{
	//should I declare variables here or inside of decisions.h
	int PHealth;
	int MHealth;
	int PStrength;
	int MStrength;
	int DistanceFBase;
	int DistanceFMonster;

	////sets random!
	srand(time(NULL));

	//randomly create the numbers for health, strength and distance for each variable
	PHealth = random(60);
	MHealth = random(60);
	PStrength = random(50);
	MStrength = random(50);
	DistanceFBase = random(75);
	DistanceFMonster = random(75);

	//the decision to be made string example: Player health: Monster Health:  player health is lower/higher
	cout << "Player Health: " << PHealth << endl;
	cout << "Monster Health: " << MHealth << endl;
	cout << "Player Strength: " << PStrength << endl;
	cout << "Monster Strength: " << MStrength << endl;
	cout << "Distance Player is From Base: " << DistanceFBase << endl;
	cout << "Disntace Player is From Monster: " << DistanceFMonster << endl;

	
	if (PHealth > MHealth)
	{
		std::cout << "Player health is greater than monser health";
		//Do some logic here
	}
	else
	{
		std::cout << "Monster health is greater than player health";
		//Do some logic here
	}

	if (PStrength > MStrength)
	{
		//Do some logic here
	}
	else
	{
	}

	//recursive question for next branch. Player distance from base/monster. 
	if (DistanceFBase > DistanceFMonster)
	{
	}
	else
	{
	}

}


void DecisionTree::Output()
{
	//take repsective node
	DisplayTree(m_RootNode);
}

//Step 9
void DecisionTree::DisplayTree(TreeNodes* CurrentNode)
{
	//if it doesn't exist, don't display of course
	if (CurrentNode == NULL)
	{
		return;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////
	//need to make a string to display for each branch
	cout << "Node ID " << CurrentNode->m_NodeID << "Decision Display: " << endl;

	//go down branch 1
	DisplayTree(CurrentNode->PrimaryBranch);

	//go down branch 2
	DisplayTree(CurrentNode->SecondaryBranch);
}


void DecisionTree::RemoveNode(TreeNodes *node)
{
	
	if (node != NULL)
	{
		if (node->PrimaryBranch != NULL)
		{
			RemoveNode(node->PrimaryBranch);
		}

		if (node->SecondaryBranch != NULL)
		{
			RemoveNode(node->SecondaryBranch);
		}

		cout << "Deleting Node" << node->m_NodeID << endl;

		//delete node from memory
		delete node;
		//reset node
		node = NULL;
	}
}


int main()
{
	//create the new decision tree object
	DecisionTree* NewTree = new DecisionTree();

	//add root node   the very first 'Question' or decision to be made
	//is monster health greater than player health?
	NewTree->CreateRootNode(1);

	//add nodes depending on decisions
	//2nd decision to be made
	//is monster strength greater than player strength?
	NewTree->PrimaryNode(1, 2);

	//3rd decision
	//is the monster closer than home base?
	NewTree->SecondaryNode(1, 3);

	//depending on the weights of all three decisions, will return certain node result
	//results!
	//Run, Attack, 
	NewTree->PrimaryNode(2, 4);
	NewTree->SecondaryNode(2, 5);
	NewTree->PrimaryNode(3, 6);
	NewTree->SecondaryNode(3, 7);

	
	NewTree->Output();

	//ask/answer question decision making process
	NewTree->Query();

	cout << "Decision Made. Press Any Key To Quit." << endl;

	int a;
	cin >> a;

	//release memory!
	delete NewTree;

	//return random value
	//return 1;


}