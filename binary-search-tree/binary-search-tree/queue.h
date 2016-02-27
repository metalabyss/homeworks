#include "tree.h"

typedef struct _Node
{
	TreeNode *treeNode;
	struct _Node *next;

} Node;

typedef struct _Queue
{
	Node *tail;
	Node *head;
} Queue;

//добавить в хвост
void pushTail(Queue *queue, TreeNode *treeNode);

//столкнуть с вершины
TreeNode *popHead(Queue *queue);

//посмотреть, что сверху
int peekHead(Queue *queue);