#ifndef QUEUE_H
#define QUEUE_H


#include <stdbool.h>


/**
 * An opaque queue data type. 
 */
typedef struct queue queue;


/**
 * Create an empty queue.
 *
 * Free allocated resources by calling queue_kill().
 *
 * \return A dynamically allocated empty queue.
 */
queue *queue_empty(void);


/**
 * Enqueue val onto q.
 *
 * \param [in,out] q The queue.
 * \param [in] val The value.
 */
void queue_enqueue(queue *q, int val);


/**
 * Check if the queue is empty.
 * 
 * \param [in] The queue.
 * \return True if the queue is empty.
 */
bool queue_is_empty(queue *q);


/**
 * Return the value at the front of the queue.
 *
 * The queue must not be empty.
 *
 * \param [in] q The queue.
 * \return The value at the front of the queue.
 */
int queue_front(queue *q);


/**
 * Remove the value at the front of the queue.
 *
 * The queue must not be empty.
 *
 * \param [in,out] q The queue.
 */
void queue_dequeue(queue *q);


/**
 * Free resources allocated for a queue by queue_empty().
 *
 * The queue must not be used again after the return.
 *
 * \param [in] q The queue.
 */
void queue_kill(queue *q);


#endif
