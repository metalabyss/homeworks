#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "tree.h"

/*Домашнее задание от 10.12.2015 */

void main()
{
	FILE *input, *numbers;
	fopen_s(&input, "input.txt", "r");
	fopen_s(&numbers, "numbers.txt", "r");

	if (!input)
	{
		printf_s("File doesn't exist\n");
		return;
	}
	
	TreeNode *node = NULL; //no nodes
	int value;

	//инициализация дерева
	while(!feof(input))
	{
		fscanf_s(input, "%d\n", &value);
		node = buildTree(node, value);
	}
	
	printf("inorder: ");
	inorderTravTree(node);

	printf("\nprefix: ");
	preorderTravTree(node);

	printf("\npostfix: ");
	postorderTravTree(node);

	printf("\nacross: ");
	acrossTravTree(node);

	printf("\n%s %d\n", "Tree height:", treeHeight(node));

	int i;
	for (i = 0; i < treeHeight(node); i++)
	{
		printf("%s %d %s %d\n", "count of nodes at", i, "level:", countOfNodes(node, i, 0));
	}
	
	//поиск и пути
	while (!feof(numbers))
	{
		fscanf_s(numbers, "%d\n", &value);
		printTrace(node, value);
		printf("\n");
	}

	//последние штрихи
	fclose(input);
	fclose(numbers);
	deleteTree(node);
}