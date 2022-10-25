/* 
 * Developed by R. E. Bryant, 2017
 * Extended to store strings, 2018
 * 
 * Extended by Jacob Sharp, 2022
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations using a singly-linked list to represent the set of queue elements
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
  Attempt to insert element at head of queue
  
  q: points to a queue
  s: points to the string to be stored
  
  Returns:  true if successful
            false if queue is NULL or could not allocate space
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
  list_ele_t *newHead;
  newHead = malloc(sizeof(list_ele_t));
  if (newHead == NULL) // handle no space
  {
    printf("Space could not be allocated. Insertion not completed.");
    return false;
  }
  
  // deep copy string TODO:NEEDS WORK
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
    queue->tail = newHead;
  }
  newHead->next = queue->head;
  queue->head = newHead;
  queue->size += 1;

  return true;
}


/*
  Attempt to insert element at tail of queue

  q: points to a queue
  s: points to the string to be stored

  Returns:  true if successful
            false if queue is NULL or could not allocate space
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
  list_ele_t *newHead;
  newHead = malloc(sizeof(list_ele_t));
  if (newHead == NULL) // handle no space
  {
    printf("Space could not be allocated. Insertion not completed.");
    return false;
  }
  
  // deep copy string TODO: NEEDS WORK
  int length = 1; // add 1 for null-terminator
  char* charArray;
  charArray = malloc(sizeof(char) * length);
  for (int i = 0; i < length; i++)
  {
    *(charArray + i) = *(string + i);
  }

  // set structure values
  if (queue->size == 0) { queue->head == newHead; } // empty
  else { queue->tail->next = newHead; }
  newHead->next = NULL;
  queue->tail = newHead;
  queue->size += 1;

  return true;
}

/*
  Attempt to remove element from head of queue

  Returns:  true if successful
            false if queue is NULL or empty
*/
bool q_remove_head(queue_t *queue, char *string, size_t bufsize)
{
  // handle invalid pointers
  if (queue == NULL)
  {
    printf("Queue pointer does not point to an address. Deletion not completed.");
    return false;
  }
  if (string == NULL)
  {
    printf("String pointer does not point to an address. Deletion not completed.");
    return false;
  }

  // handle empty queue
  if (queue->size == 0)
  {
    printf("Queue is empty.");
    return false;
  }

  // free old head

  // change head
  queue->head = queue->head->next;

  /*
    If sp is non-NULL and an element is removed, copy the removed string to *sp
    (up to a maximum of bufsize-1 characters, plus a null terminator.)
    The space used by the list element and the string should be freed.
  */
  
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
 */
void q_reverse(queue_t *queue)
{
  /* You need to write the code for this function 
  
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
  */
}

