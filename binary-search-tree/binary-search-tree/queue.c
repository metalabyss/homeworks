#include "queue.h"
#include <stdlib.h>

void pushTail(Queue *queue, TreeNode *treeNode)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->treeNode = treeNode;

	//если очередь не пуста
	if (queue->tail)
	{
		queue->tail->next = newNode;
	}
	else
	{
		queue->head = newNode;
	}

	queue->tail = newNode;
}

TreeNode *popHead(Queue *queue)
{
	Node *tmp = queue->head;
	TreeNode *treeNode = tmp->treeNode;
	queue->head = queue->head->next;
	free(tmp);

	if (!queue->head) queue->tail = NULL;

	return treeNode;
}

int peekHead(Queue *queue)
{
	return queue->head->treeNode->value;
}