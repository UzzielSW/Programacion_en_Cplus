// The nodes are displayed with inorder, preorder,
// and postorder algorithms.
//
// The search function determines if the
// value 3 is in the tree.

// The deleteNode function is used to remove 2 of them.
#include <iostream>
#include <stdlib.h>
#include "IntBinaryTree.h"
using namespace std;

//**************************************************
// This version of insert inserts a number into
// a given subtree of the main binary search tree.
//**************************************************
void IntBinaryTree::insert(TreeNode *&tree, int num)
{
	// If the tree is empty, make a new node and make it
	// the root of the tree.
	if (!tree)
	{
		tree = new TreeNode(num);
		return;
	}

	// If num is already in tree: return.
	if (tree->value == num)
		return;

	// The tree is not empty: insert the new node into the
	// left or right subtree.
	if (num < tree->value)
		insert(tree->left, num);
	else
		insert(tree->right, num);
}

void IntBinaryTree::displayTree(TreeNode *tree, int cont = 0)
{
	if (tree == NULL)
		return;
	else
	{
		displayTree(tree->right, cont + 1);
		for (int i = 0; i < cont; i++)
			cout << "   ";
		cout << tree->value << endl;
		displayTree(tree->left, cont + 1);
	}
}

//***************************************************
// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.
//***************************************************
void IntBinaryTree::destroySubtree(TreeNode *&tree)
{
	if (tree != NULL)
	{
		destroySubtree(tree->left);
		destroySubtree(tree->right);
		cout << "\n delete Nodo " << tree->value << "...";
		tree = NULL;
		// Delete the node at the root.
		delete tree;
	}
}

//***************************************************
// searchNode determines if a value is present in
// the tree. If so, the function returns true.
// Otherwise, it returns false.
//***************************************************
bool IntBinaryTree::search(int num)
{
	TreeNode *tree = root;

	while (tree)
	{
		if (tree->value == num)
			return true;
		else if (num < tree->value)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return false;
}

//********************************************
// remove deletes the node in the given tree
// that has a value member the same as num.
//********************************************
void IntBinaryTree::remove(TreeNode *&tree, int num)
{
	if (tree == NULL)
		return;
	if (num < tree->value)
		remove(tree->left, num);
	else if (num > tree->value)
		remove(tree->right, num);
	// We have found the node to delete.
	else
		makeDeletion(tree);
}

//***********************************************************
// makeDeletion takes a reference to a tree whose root
// is to be deleted. If the tree has a single child,
// the tree is replaced by the single child after the
// removal of its root node. If the tree has two children
// the left subtree of the deleted node is attached at
// an appropriate point in the right subtree, and then
// the right subtree replaces the original tree.
//***********************************************************
void IntBinaryTree::makeDeletion(TreeNode *&tree)
{
	// Used to hold node that will be deleted.
	TreeNode *nodeToDelete = tree;

	// Used to locate the point where the left subtree is attached.
	TreeNode *attachPoint;

	// Replace tree with its left subtree.
	if (tree->right == NULL)
		tree = tree->left;
	// Replace tree with its right subtree.
	else if (tree->left == NULL)
		tree = tree->right;
	// The node has two children
	else
	{
		// Move to right subtree.
		attachPoint = tree->right;

		// Locate the smallest node in the right subtree
		// by moving as far to the left as possible.
		while (attachPoint->left != NULL)
		{
			attachPoint = attachPoint->left;
		}

		// Attach the left subtree of the original tree
		// as the left subtree of the smallest node
		// in the right subtree.
		attachPoint->left = tree->left;
		// Replace the original tree with its right subtree.
		tree = tree->right;
	}

	// Delete root of original tree
	delete nodeToDelete;
}

//*********************************************************
// This function displays the values stored in a tree *
// in inorder. *
//*********************************************************
void IntBinaryTree::displayInOrder(TreeNode *tree)
{
	if (tree)
	{
		displayInOrder(tree->left);
		cout << tree->value << " ";
		displayInOrder(tree->right);
	}
}

//*********************************************************
// This function displays the values stored in a tree *
// in inorder. *
//*********************************************************
void IntBinaryTree::displayPreOrder(TreeNode *tree)
{
	if (tree)
	{
		cout << tree->value << " ";
		displayPreOrder(tree->left);
		displayPreOrder(tree->right);
	}
}

//*********************************************************
// This function displays the values stored in a tree *
// in postorder. *
//*********************************************************
void IntBinaryTree::displayPostOrder(TreeNode *tree)
{
	if (tree)
	{
		displayPostOrder(tree->left);
		displayPostOrder(tree->right);
		cout << tree->value << " ";
	}
}

int main()
{
	IntBinaryTree tree;

	cout << "Inserting the numbers 5 8 3 12 9...";
	tree.insert(8);
	tree.insert(3);
	tree.insert(1);
	tree.insert(6);
	tree.insert(4);
	tree.insert(7);
	tree.insert(10);
	tree.insert(14);
	tree.insert(13);

	cout << "\nShow Tree:\n\n";
	tree.showTree();

	cout << "\n\nInorder traversal: ";
	tree.showInOrder();

	cout << "\n\nPreorder traversal: ";
	tree.showPreOrder();

	cout << "\n\nPostorder traversal: ";
	tree.showPostOrder();

	cout << "\n\nSearch 13 in tree...\n";
	if (tree.search(13))
		cout << " 13 is found in the tree.\n";
	else
		cout << " 13 was not found in the tree.\n";

	cout << "\n Deleting 8...\n";
	tree.remove(8);

	cout << " Deleting 7...\n";
	tree.remove(7);

	cout << " Now, here are the nodes: ";
	tree.showInOrder();

	cout << "\n\n Delete binary tree:\n";
	tree.~IntBinaryTree();
	return 0;
}
