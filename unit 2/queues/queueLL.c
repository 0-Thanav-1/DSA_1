#include <stdio.h>
#include <stdlib.h>
typedef struct qnode
{
	int data;
	struct qnode *next;
} NODE;

typedef struct queue
{
		NODE *front, *rear;
} QUEUE;

QUEUE *createqueue()
{
	QUEUE *temp = (QUEUE *)malloc(sizeof(QUEUE));
	if (temp != NULL)
	{
		temp->front = temp->rear = NULL;
	}
	return (temp);
}
void enqueue(QUEUE *ptr, int ele)
{
	NODE *temp = (NODE *)malloc(sizeof(NODE));
	temp->data = ele;
	temp->next = NULL;
	if (ptr->front == NULL && ptr->rear == NULL)
	{
		ptr->front = ptr->rear = temp;
		return;
	}
	ptr->rear->next = temp;
	ptr->rear = temp;
}
void display(QUEUE *ptr)
{
	if (ptr->front == NULL && ptr->rear == NULL)
	{
		printf("empty");
	}
	else
	{
		NODE *cur = ptr->front;
		while (cur != NULL)
		{
			printf("%d\t", cur->data);
			cur = cur->next;
		}
	}
}
int dequeue(QUEUE *ptr)
{
	if (ptr->front == NULL && ptr->rear == NULL)
	{
		return 0;
	}
	else
	{
		NODE *first = ptr->front;
		if (first->next == NULL)
		{
            int x = first->data;
			ptr->front = first->next;
			free(first);
			ptr->front = ptr->rear = NULL;
			return (x);
		}
        int x = first->data;
		ptr->front = first->next;
		free(first);
		return (x);
	}
}

int main()
{
	QUEUE *ptr = createqueue();
	int ch, ele, x;
	while (1)
	{
		printf("\n1.Enqueue\n 2.Dequeue\n 3.display\n4.exit\n");
		printf("Enter the choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the elemnet\n");
			scanf("%d", &ele);
			enqueue(ptr, ele);
			break;
		case 2:
			x = dequeue(ptr);
			if (x == 0)
				printf("empty list\n");
			else
				printf("deleted element is:%d\n", x);
			break;
		case 3:
			display(ptr);
			break;
		case 4: exit(0);
		}
	}
}