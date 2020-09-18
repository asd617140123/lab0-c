#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (q == NULL)
        return NULL;
    q->head = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *tmp = q->head;
    while (q->head) {
        q->head = tmp->next;
        free(tmp);
        tmp = q->head;
    }
    free(q);
    q->size = 0;
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    int tmplen = strlen(s);
    /* TODO: What should you do if the q is NULL? */
    if (!q)
        goto fail;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        goto fail;
    newh->value = malloc(strlen(s));
    if (!newh->value)
        goto fail;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    // value_len = strlen(s);
    // if(!newh->value)
    //    goto fail;
    // if(strlen(s) > sizeof(newh->value))
    //    goto fail;
    strncpy(newh->value, s, tmplen);
    newh->next = q->head;
    q->head = newh;
    q->size++;
    return true;
fail:
    return false;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    list_ele_t *newh;
    int tmp_len = strlen(s);
    /* TODO: What should you do if the q is NULL? */
    if (!q)
        goto fail;
    newh = malloc(sizeof(list_ele_t));
    if (!newh)
        goto fail;
    newh->value = malloc(strlen(s));
    if (!newh->value)
        goto fail;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    // value_len = strlen(s);
    strncpy(newh->value, s, tmp_len);
    if (q->head)
        q->tail = q->head;
    newh->next = q->tail;
    q->head = newh;
    q->size++;
    return true;
fail:
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    // char* val = malloc()
    list_ele_t *tmp = q->head;

    // tmp->value = malloc(strlen(q->head->value));
    // char* empty = "\0";
    // if(!tmp)
    //    goto fail;
    // if(!q)
    //    goto fail;
    q->head = q->head->next;
    if (!sp)
        goto fail;
    strncpy(sp, tmp->value, bufsize);
    // strcat(sp,empty);
    free(tmp);
    return true;
fail:
    return false;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */

    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
    list_ele_t *front = q->head;
    list_ele_t *back = q->head;
    list_ele_t *tmp = front->next;

    while (tmp) {
        // tmp = back->next;
        front = tmp;
        tmp->next = back;
        back = front;
        tmp = back->next;
    }
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
