#ifndef __TREENODE__
#define __TREENODE__

typedef struct _TreeNode
{
	int value;
	struct _TreeNode *left;
	struct _TreeNode *right;
} TreeNode;

TreeNode *buildTree(TreeNode *root, int value);

//инфиксный обход дерева (1)
void inorderTravTree(TreeNode *root);

//префиксный обход дерева (2)
void preorderTravTree(TreeNode *root);

//постфиксный обход дерева (3)
void postorderTravTree(TreeNode *root);

//обход дерева в ширину (4)
void acrossTravTree(TreeNode *root);

//вычисление высоты дерева (5)
int treeHeight(TreeNode *root);

//вычисление количества элементов на заданном уровне дерева (6)
//считаем, что корень дерева - нулевой уровень
int countOfNodes(TreeNode *node, int level, int currLevel);

//поиск вершины дерева по ключу (7)
TreeNode *searchTreeNode(TreeNode *root, int value);

//печать пути от корня до заданной вершины (8)
void printTrace(TreeNode *root, int value);

//освобождение памяти
void deleteTree(TreeNode *root);

#endif