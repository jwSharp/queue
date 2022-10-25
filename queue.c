/* 
 * Developed by R. E. Bryant, 2017
 * Extended to store strings, 2018
 * 
 * Extended by Jacob Sharp, 2022
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "harness.h"
#include "queue.h"


/*
  Create empty queue

  Returns:  pointer to a queue
            NULL if could not allocate space
*/
queue_t* q_new()
{
    queue_t *queue =  malloc(sizeof(queue_t));
    if (queue == NULL) // handle no space
    {
      printf("Space could not be allocated. Queue not created.");
      return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

/* 
  Free all storage used by queue
*/
void q_free(queue_t *queue)
{
    /* How about freeing the list elements and the strings? */
    
    // free queue structure
    free(queue);
}

/*
  Attempt to insert element at head of queue.
  
  q: points to a queue
  s: points to the string to be stored
  
  Returns:  true if successful
            false if q is NULL or could not allocate space
 */
bool q_insert_head(queue_t *queue, char *string)
{
    // handle invalid pointers
    if (queue == NULL)
    {
      printf("Queue pointer does not point to an address. Insertion not completed.");
      return false;
    }
    if (string == NULL)
    {
      printf("String pointer does not point to an address. Insertion not completed.");
      return false;
    }

    // create new element
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) // handle no space
    {
      printf("Space could not be allocated. Insertion not completed.");
      return false;
    }
    
    // deep copy string NEEDS WORK
    int length = 1; // add 1 for null-terminator
    char* charArray;
    charArray = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++)
    {
      *(charArray + i) = *(string + i);
    }

    // set structure values
    if (queue->head == NULL)
    {
      queue->tail = newh;
    }
    newh->next = queue->head;
    queue->head = newh;
    queue->size += 1;

    return true;
}


/*
  Attempt to insert element at tail of queue

  q: points to a queue
  s: points to the string to be stored

  Returns:  true if successful
            false if q is NULL or could not allocate space
 */
bool q_insert_tail(queue_t *queue, char *string)
{
    // handle invalid pointers
    if (queue == NULL)
    {
      printf("Queue pointer does not point to an address. Insertion not completed.");
      return false;
    }
    if (string == NULL)
    {
      printf("String pointer does not point to an address. Insertion not completed.");
      return false;
    }

    // create new element
    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) // handle no space
    {
      printf("Space could not be allocated. Insertion not completed.");
      return false;
    }
    
    // deep copy string NEEDS WORK
    int length = 1; // add 1 for null-terminator
    char* charArray;
    charArray = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++)
    {
      *(charArray + i) = *(string + i);
    }

    // set structure values
    if (queue->head == NULL) // empty queue
    {
      queue->head == newh;
      
    }
    else
    {
      queue->tail->next = newh;
    }
    newh->next = NULL;
    queue->tail = newh;
    queue->size += 1;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *queue, char *string, size_t bufsize)
{
    /* You need to fix up this code. */
    queue->head = queue->head->next;
    return true;
}

/*
  Returns:  number of elements in queue
            0 if q is NULL or empty
 */
int q_size(queue_t *queue)
{
  if (queue == NULL)
  {
    printf("Queue pointer does not point to an address. Insertion not completed.");
    return 0;
  }
  return queue->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *queue)
{
    /* You need to write the code for this function */
}

