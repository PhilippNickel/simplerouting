/*
 * taken from
 * https://de.wikibooks.org/wiki/Algorithmen_und_Datenstrukturen_in_C/
 * _Warteschlange
 */

#include "queue.h"
#include <stddef.h>
#include <stdlib.h>

struct queue_node_s {
	struct queue_node_s *next;
	void *data;
};

struct queue_s {
	struct queue_node_s *front;
	struct queue_node_s *back;
};

int queue_destroy(queue_t *queue)
{
	if (queue == NULL) {
		return ERR_INVAL;
	}
	while (queue->front != NULL) {
	    struct queue_node_s *node = queue->front;
	    queue->front = node->next;
	    free(node);
	}
	free(queue);
	return SUCCESS;
}

int queue_empty(queue_t *queue)
{
	  if (queue == NULL || queue->front == NULL) {
		return TRUE;
	  } else {
		return FALSE;
	  }
}

queue_t *queue_new(void)
{
	  queue_t *queue = malloc(sizeof(*queue));
	  if (queue == NULL) {
		return NULL;
	  }
	  queue->front = queue->back = NULL;
	  return queue;
}

void *queue_dequeue(queue_t *queue)
{
	  if (queue == NULL || queue->front == NULL) {
		return NULL;
	  }
	  struct queue_node_s *node = queue->front;
	  void *data = node->data;
	  queue->front = node->next;
	  if (queue->front == NULL) {
		queue->back = NULL;
	  }
	  free(node);
	  return data;
}

int queue_enqueue(queue_t *queue, void *data)
{
	  if (queue == NULL) {
		return ERR_INVAL;
	  }
	  struct queue_node_s *node = malloc(sizeof(*node));
	  if (node == NULL) {
		return ERR_NOMEM;
	  }
	  node->data = data;
	  node->next = NULL;
	  if (queue->back == NULL) {
		queue->front = queue->back = node;
	  } else {
		queue->back->next = node;
		queue->back = node;
	  }
	  return SUCCESS;
}
