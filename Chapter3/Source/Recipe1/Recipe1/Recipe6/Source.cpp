#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct vertex
{
	typedef pair<int, vertex*> ve;
	vector<ve> adj; //cost of edge, destination vertex
	string name;
	vertex(string s)
	{
		name = s;
	}
};

class graph
{
public:
	typedef map<string, vertex *> vmap;
	vmap work;
	void addvertex(const string&);
	void addedge(const string& from, const string& to, double cost);
};

void graph::addvertex(const string &name)
{
	vmap::iterator itr = work.begin();
	itr = work.find(name);
	if (itr == work.end())
	{
		vertex *v;
		v = new vertex(name);
		work[name] = v;
		return;
	}
	cout << "\nVertex already exists!";
}

void graph::addedge(const string& from, const string& to, double cost)
{
	vertex *f = (work.find(from)->second);
	vertex *t = (work.find(to)->second);
	pair<int, vertex *> edge = make_pair(cost, t);
	f->adj.push_back(edge);
}

int main()
{
	return 0;
}