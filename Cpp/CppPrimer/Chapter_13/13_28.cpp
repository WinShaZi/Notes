/*

class TreeNode
{
public:
	TreeNode() : count(new size_t(1)), left(nullptr), right(nullptr) { }
	TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
	TreeNode & operator=(const TreeNode &tn);
	~TreeNode()
	{
		if (0 == --*count)
		{
			delete count;
			delete left;
			delete right;
		}
	}
private:
	string value;
	size_t *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree() : root(new TreeNode) { }
	BinStrTree(const BinStrTree &bst) : root(bst.root) { }
	BinStrTree & operator=(const BinStrTree &bst);
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};

BinStrTree & BinStrTree::operator= (const BinStrTree &bst)
{
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
	
    return *this;
}

*/