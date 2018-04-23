#include <stdlib.h>
#include <assert.h>
#include "queue.h"


struct node
{
    struct node *next;
    int value;
};


static struct node *make_node(int value)
{
    struct node *n = malloc(sizeof *n);
    n->next = NULL;
    n->value = value;
    return n;
}


struct queue
{
    struct node *front;
    struct node *rear;
};


queue *queue_empty(void)
{
    queue *q = malloc(sizeof *q);
    q->front = NULL;
    q->rear = NULL;
    return q;
}


void queue_enqueue(queue *q, int val)
{
    assert(q != NULL);
    
    struct node *n = make_node(val);
    if (q->rear)
    {
        q->rear->next = n;
        q->rear = n;
    } else {
        q->rear = q->front = n;
    }
}


bool queue_is_empty(queue *q)
{
    assert(q != NULL);
    
    return q->front == NULL;
}


int queue_front(queue *q)
{
    assert(q != NULL);
    assert(q->front != NULL);
    return q->front->value;
}


void queue_dequeue(queue *q)
{
    assert(q != NULL);
    assert(q->front != NULL);

    struct node *n = q->front;
    q->front = n->next;
    free(n);
    if (!q->front)
        q->rear = NULL;
}


void queue_kill(queue *q)
{
    while (!queue_is_empty(q))
    {
        queue_dequeue(q);
    }
    free(q);
}
