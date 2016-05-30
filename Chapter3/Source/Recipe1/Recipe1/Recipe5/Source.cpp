
// Initialise the node with a value and pointers
// to left child
// and right child

#include <string>

using namespace std;
struct node
{
	string key_value;
	node *left;
	node *right;
};

class Binary_Tree
{
public:
	Binary_Tree();
	~Binary_Tree();

	void insert(string key);
	node *search(string key);
	void destroy_tree();

private:
	void destroy_tree(node *leaf);
	void insert(string key, node *leaf);
	node *search(string key, node *leaf);

	node *root;
};

Binary_Tree::Binary_Tree()
{
	root = NULL;
}

Binary_Tree::~Binary_Tree()
{
	destroy_tree();
}

void Binary_Tree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void Binary_Tree::insert(string key, node *leaf)
{
	if (key< leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;  
			leaf->left->right = NULL;  
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL; 
			leaf->right->right = NULL;
		}
	}
}

node *Binary_Tree::search(string key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void Binary_Tree::insert(string key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}
node *Binary_Tree::search(string key)
{
	return search(key, root);
}

void Binary_Tree::destroy_tree()
{
	destroy_tree(root);
}

int main()
{
	return 0;
}