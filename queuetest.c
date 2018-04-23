/*
 * Obligatorisk Uppgift 1 (5dv160)
 * Author: David Töyrä
 * Date:2017-07-22
 *
 * A testprogram for a queuedatatype, does six tests based
 * on axioms described in the book Datatyper och Algoritmer(Lars-erik Janlert, Torbjörn Wikström. 2000.)
 *
 */
 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"


/*
 * Axiom 1,tests if a queue is empty when it is created.
 */
bool test_queueisEmpty(void)
{
	
	queue *test = queue_empty();
	queue_setMemHandler(test, free);
	/*Test if an empty queue is empty.*/
	if(queue_isEmpty(test)==false)
	{
		printf("queue_isEmpty failed!\nAn empty queue returned false.\n");
		queue_free(test);
		return false;
	}
	queue_free(test);
	printf("Test 1 Succeded!\n");
	return true;
}

/*
 * Axiom 2, test if a queue that has a value in it is not empty.
 */
bool test_queueEnqueue(void)
{
	queue *test = queue_empty();
	queue_setMemHandler(test, free);
	
	int *number=malloc(sizeof(int));
	int x = 5;
	*number = x;

	queue_enqueue(test, number);
	/*Tests if queue is empty after element has been inserted.*/
	if(queue_isEmpty(test)==true)
	{
		printf("Test 2 failed!\nQueue had a value but returned true.");
		queue_free(test);
		return false;
	}
	
	printf("Test 2 succeded!\n");
	queue_free(test);
	return true;
}

/*
 * Axiom 3, queue should be empty if a value has been dequed.
 */
 bool test_queueDeqeue(void)
 {
	queue *test=queue_empty();
	queue_setMemHandler(test, free);
	int x = 2;
	int *number = malloc(sizeof(int));
	*number=x;
	queue_enqueue(test, number);
	queue_dequeue(test);
	
	/*Tests if deqeue removes an element*/
	if(queue_isEmpty(test)==false)
	{
		printf("queue_dequeue failed!\nQueue had one value and it was not removed after dequeue.");
		queue_free(test);
		return false;
	}
	
	printf("Test 3 succeded!\n");
	queue_free(test);
	return true;
	
 }
 
 /*
  * Axiom 4.
  * Check that two non empty queues are the same if one is deqeued after having
  * been enqueued with a value v and the second queue having been enqueued a valued v after
  * deqeuing it.
  */
  bool test_queueFrontValue(void)
  {
	  /* Create two queues*/
	  queue *que1 = queue_empty();
	  queue_setMemHandler(que1, free);
	  queue *que2 = queue_empty();
	  queue_setMemHandler(que2, free);
	  
	  /* Adds a start value to each queue so that they are not empty */
	  int startValue1 = 100;
	  int startValue2 = 32;
	  int *startVal1 = malloc(sizeof(int));
	  int *startVal2 = malloc(sizeof(int));
	  *startVal1 = startValue1;
	  *startVal2 = startValue2;
	  queue_enqueue(que1, startVal1);
	  queue_enqueue(que2, startVal2);
	  
	  int val = 5;
	  int *val1 = malloc(sizeof(int));
	  int *val2 = malloc(sizeof(int));
	  *val1 = val;
	  *val2 = val;
	  
	  /*Enques val to que1 and then deques que1*/
	  queue_enqueue(que1, val1);
	  queue_dequeue(que1);
	  
	  /*Deques que2 and then enques val to que2*/
	  queue_dequeue(que2);
	  queue_enqueue(que2, val2);
	  if(queue_isEmpty(que1) || queue_isEmpty(que2))
	  {
		  printf("Test 4 failed!\n Queues cannot be empty");
		  queue_free(que1);
		  queue_free(que2);
		  return false;
	  }
	  
	  if( *(int*) queue_front(que1) != *(int*) queue_front(que2))
	  {
		  printf("Test 4 failed!\nqueue_front did not return same values for both queues\n");
		  queue_free(que1);
		  queue_free(que2);
		  return false;
	  }
	
	  printf("Test 4 succeded!\n");
	  queue_free(que1);
	  queue_free(que2);
	  return true;
  }
  
  /*
   * Axiom 5, enques a value to an empty queue and checks if front returns that value.
   */
   bool test_queueFront(void)
   {
	   queue *test = queue_empty();
	   queue_setMemHandler(test, free);
	   
	   int x = 5;
	   int *number = malloc(sizeof(int));
	   *number = x;
	   
	   queue_enqueue(test, number);
	   if(queue_front(test)!=number)
	   {
		   printf("Test 5 failed!\nqueue_front did not return the correct value\n");
		   queue_free(test);
		   return false;
	   }
	   
	   printf("Test 5 succeded!\n");
	   queue_free(test);
	   return true;
   }
   
   /*
    * Axiom 6, checks if front is equal in two queues where one had recently enqueued.
    */
	bool test_queueFrontOnTwoQueues(void)
	{
		queue *testQue1 = queue_empty();
		queue_setMemHandler(testQue1, free);
		
		queue *testQue2 = queue_empty();
		queue_setMemHandler(testQue2, free);
		
		int startValue = 17;
		int *startVal1 = malloc(sizeof(int));
		int *startVal2 = malloc(sizeof(int));
		int testValue = 5;
		int *testVal = malloc(sizeof(int));
		*startVal1 = startValue;
		*startVal2 = startValue;
		*testVal = testValue;
		
		queue_enqueue(testQue1, startVal1);
		queue_enqueue(testQue2, startVal2);
		queue_enqueue(testQue1, testVal);
		
		if(queue_isEmpty(testQue1) || queue_isEmpty(testQue2))
		{
			printf("Test 6 failed!\nQueues cannot be empty.");
			queue_free(testQue1);
			queue_free(testQue2);
			return false;
		}
		
		if( *(int*) queue_front(testQue1) != *(int*) queue_front(testQue2))
		{
			printf("Test 6 failed!\nDifferent values in queue fronts.");
			queue_free(testQue1);
			queue_free(testQue2);
			return false;
		}
		
			printf("Test 6 succeded!\n");
			queue_free(testQue1);
			queue_free(testQue2);
			return true;
	}


int main()
{

	bool test = test_queueisEmpty();
	if(test!=true)
		return 0;
	test = test_queueEnqueue();
	if(test!=true)
		return 0;
	test = test_queueDeqeue();
	if(test!= true)
		return 0;
	test = test_queueFrontValue();
	if(test!=true)
		return 0;
	test = test_queueFront();
	if(!test)
		return 0;
	test = test_queueFrontOnTwoQueues();
	if(!test)
		return 0;
		
	printf("All tests passed!");
	
	return 0;		
}
