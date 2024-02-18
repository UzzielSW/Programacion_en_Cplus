#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

class IntBinaryTree
{
private:
	// The TreeNode class is used to build the tree.
	class TreeNode
	{
		friend class IntBinaryTree;
		int value;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int value, TreeNode *left = NULL, TreeNode *right = NULL)
		{
			this->value = value;
			this->left = left;
			this->right = right;
		}
	};

	TreeNode *root; // Pointer to the root of the tree

	// Various helper member functions.
	void insert(TreeNode *&, int);
	void displayTree(TreeNode *, int);
	void displayPreOrder(TreeNode *);
	void displayInOrder(TreeNode *);
	void displayPostOrder(TreeNode *);
	void remove(TreeNode *&, int);
	void makeDeletion(TreeNode *&);
	void destroySubtree(TreeNode *&);

public:
	// These member functions are the public interface.
	IntBinaryTree() { root = NULL; } // Constructor
	~IntBinaryTree()
	{
		destroySubtree(root);
	} // Destructor

	void insert(int num)
	{
		insert(root, num);
	}

	bool search(int);

	void remove(int num)
	{
		remove(root, num);
	}

	void showInOrder()
	{
		displayInOrder(root);
	}

	void showPreOrder()
	{
		displayPreOrder(root);
	}

	void showPostOrder()
	{
		displayPostOrder(root);
	}

	void showTree()
	{
		displayTree(root, 0);
	}
};

#endif