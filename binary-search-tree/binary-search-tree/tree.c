#include "tree.h"
#include "queue.h"
#include <malloc.h>
#include <stdio.h>

TreeNode *buildTree(TreeNode *root, int value)
{
	if (!root) {
		root = malloc(sizeof(TreeNode));
		root->value = value;
		root->left = NULL;
		root->right = NULL;
	}
	else if (value < root->value)
		root->left = buildTree(root->left, value);
	else
		root->right = buildTree(root->right, value);

	return root;
}

void inorderTravTree(TreeNode *root)
{
	if (root) //если в дереве есть элементы
	{
		inorderTravTree(root->left);
		printf("%d ", root->value);
		inorderTravTree(root->right);
	}
}

void preorderTravTree(TreeNode *root)
{
	if (root)
	{
		printf("%d ", root->value);
		preorderTravTree(root->left);
		preorderTravTree(root->right);
	}
}

void postorderTravTree(TreeNode *root)
{
	if (root)
	{
		postorderTravTree(root->left);
		postorderTravTree(root->right);
		printf("%d ", root->value);
	}
}

void acrossTravTree(TreeNode *root)
{
	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	pushTail(queue, root);

	while(queue->head)
	{
		TreeNode *currentNode = popHead(queue);
		printf("%d ", currentNode->value);
		if (currentNode->left)
			pushTail(queue, currentNode->left);
		if (currentNode->right)
			pushTail(queue, currentNode->right);
	}
}

int treeHeight(TreeNode *root)
{
	if (!root) return 0;
	int leftSubtreeHeight = 0, rightSubtreeHeight = 0;

	if (root->left) leftSubtreeHeight = treeHeight(root->left);
	if (root->right) rightSubtreeHeight = treeHeight(root->right);

	if (leftSubtreeHeight > rightSubtreeHeight)
	{
		return leftSubtreeHeight + 1;
	}
	else
	{
		return rightSubtreeHeight + 1;
	}
}

int countOfNodes(TreeNode *node, int level, int currentLevel)
{
	if (level == currentLevel) return 1;
	int left = 0;
	int right = 0;
	if (node->left)
		left = countOfNodes(node->left, level, currentLevel + 1);
	
	if (node->right)
		right = countOfNodes(node->right, level,  currentLevel + 1);

	return left + right;
}

TreeNode *searchTreeNode(TreeNode *root, int value)
{
	TreeNode *currentNode = root;
	while (currentNode)
	{
		if (value == currentNode->value)
			return currentNode;
		if (value < currentNode->value)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	return NULL;
}

void printTrace(TreeNode *root, int value)
{
	if (searchTreeNode(root, value))
	{
		TreeNode *currentNode = root;
		while (currentNode->value != value)
		{
			printf("%d ", currentNode->value);

			if (value < currentNode->value)
				currentNode = currentNode->left;
			else
				currentNode = currentNode->right;		
		}
		printf("%d ", currentNode->value);
	}
	else
	{
		printf("%s %d %s", "number", value, "not found");
	}
}

void deleteTree(TreeNode *root) {
	if (root) {
		deleteTree((root)->left);
		deleteTree((root)->right);
		free(root);
	}
}