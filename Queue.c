#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <stdbool.h>
typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = NULL;
	q->rear = NULL;
}

void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (q->front == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}

}

void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//检测队列是否为空
	if (q->front->next == NULL)
	{
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		QNode* head = q->front->next;
		free(q->front);
		q->front = head;
	}
}

QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//检测队列是否为空

	return q->front->data;//返回队头指针指向的数据
}

QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));//检测队列是否为空

	return q->rear->data;//返回队尾指针指向的数据
}

bool QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}

int QueueSize(Queue* q)
{
	assert(q);

	QNode* cur = q->front;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}