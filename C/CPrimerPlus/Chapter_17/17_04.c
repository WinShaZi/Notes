
//queue.h
//*******************************************************************************************

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
#define MAXQUEUE 10

typedef struct item
{
	long arrive;
	int processtime;
} Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	Node * front;
	Node * rear;
	int items;
} Queue;

InitializeQueue(Queue * pq);
bool QueueIsFull(const Queue * pq);
bool QueueIsEmpty(const Queue * pq);
int QueueItemCount(const Queue * pq);
bool EnQueue(Item item, Queue * pq);
bool DeQueue(Item * pitem, Queue * pq);
EmptyTheQueue(Queue * pq);
#endif

//*******************************************************************************************

//queue.c
//*******************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

static CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}

InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
	Node * pnew = NULL;

	if (QueueIsFull(pq))
		return false;
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->items++;

	return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt = NULL;

	if (QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->rear = NULL;

	return true;
}
EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

//*******************************************************************************************

//mall.c
//*******************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;
	return cust;
}

int main()
{
	Queue line1, line2;
	Item temp1, temp2;
	int hours1, hours2;
	int perhour1, perhour2;
	long cycle1, cyclelimit1, cycle2, cyclelimit2;
	long turnaways1 = 0;
	long turnaways2 = 0;
	long customers1 = 0;
	long customers2 = 0;
	long served1 = 0;
	long served2 = 0;
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	double min_per_cust1, min_per_cust2;
	long line_wait1 = 0;
	long line_wait2 = 0;
	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));
	puts("Case Study:Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours for queue1 :");
	scanf("%d", &hours1);
	cyclelimit1 = (long)MIN_PER_HR * hours1;
	puts("Enter the number of simulation hours for queue2 :");
	scanf("%d", &hours2);
	cyclelimit2 = (long)MIN_PER_HR * hours2;
	puts("Enter the average number of customers per hour for queue1 :");
	scanf("%d", &perhour1);
	min_per_cust1 = MIN_PER_HR / perhour1;
	puts("Enter the average number of customers per hour for queue2 :");
	scanf("%d", &perhour2);
	min_per_cust2 = MIN_PER_HR / perhour2;

	for (cycle1 = 0; cycle1 < cyclelimit1; cycle1++)
	{
		if (newcustomer(min_per_cust1))
		{
			if (QueueIsFull(&line1))
				turnaways1++;
			else
			{
				customers1++;
				temp1 = customertime(cycle1);
				EnQueue(temp1, &line1);
			}
		}
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp1, &line1);
			wait_time1 = temp1.processtime;
			line_wait1 += cycle1 - temp1.arrive;
			served1++;
		}
		if (wait_time1 > 0)
			wait_time1--;
		sum_line1 += QueueItemCount(&line1);
	}
	for (cycle2 = 0; cycle2 < cyclelimit2; cycle2++)
	{
		if (newcustomer(min_per_cust2))
		{
			if (QueueIsFull(&line2))
				turnaways2++;
			else
			{
				customers2++;
				temp2 = customertime(cycle2);
				EnQueue(temp2, &line2);
			}
		}
		if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp2, &line2);
			wait_time2 = temp2.processtime;
			line_wait2 += cycle2 - temp2.arrive;
			served2++;
		}
		if (wait_time2 > 0)
			wait_time2--;
		sum_line2 += QueueItemCount(&line2);
	}

	if (customers1 > 0)
	{
		printf("customers accepted for queue1 : %ld\n", customers1);
		printf("  customers served for queue1 : %ld\n", served1);
		printf("    turnaways for queue1:%ld\n", turnaways1);
		printf("average wait time for queue1 : %.2f minutes\n", (double)line_wait1 / served1);
	}
	else
		puts("No cunstomers for queue1!");
	EmptyTheQueue(&line1);
	if (customers2 > 0)
	{
		printf("customers accepted for queue2 : %ld\n", customers2);
		printf("  customers served for queue2 : %ld\n", served2);
		printf("    turnaways for queue2 : %ld\n", turnaways2);
		printf("average wait time for queue2 : %.2f minutes\n", (double)line_wait2 / served2);
	}
	else
		puts("No cunstomers for queue2!");
	EmptyTheQueue(&line2);
	puts("Bye!");

	system("pause");
	return 0;
}

//*******************************************************************************************