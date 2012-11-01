#include "stdio.h"
#include "assert.h"
#include "list.h"

void LIST_NODE_INIT(list_node_t *node)
{
  ASSERT(node);
  node->prev = NULL;
  node->next = NULL;
}

void LIST_INIT(list_t *listroot)
{
  ASSERT(listroot);
  LIST_NODE_INIT(&listroot->listhead);
  listroot->length = 0;
}


void list_insert_before(list_t *listroot, list_node_t *new_node, list_node_t *before_this_node)
{
  ASSERT(listroot);
  ASSERT(new_node);

  if (before_this_node == listroot->listhead.next)
  {
    /* Adding at the head */
    new_node->prev = NULL;
    new_node->next = listroot->listhead.next;
    listroot->listhead.next = new_node;

    if (new_node->next)
      new_node->next->prev = new_node;
    else
    {
      /* first node being added */
      listroot->listhead.prev = new_node;
    }
  }
  else if (before_this_node == NULL)
  {
    /* adding at tail */
    new_node->next = NULL;
    new_node->prev = listroot->listhead.prev;
    listroot->listhead.prev = new_node;

    /* Adding at tail is possible from the second node only */
    new_node->prev->next = new_node;
  }
  else
  {
    new_node->next = before_this_node;
    new_node->prev = before_this_node->prev;
    before_this_node->prev = new_node;
    new_node->prev->next = new_node;
  }

  listroot->length++;
  return;
}

list_node_t* LIST_GET_NEXT(list_t *listroot, list_node_t *new_node)
{
  if (new_node)
    return new_node->next;
  else
    return NULL;
}

list_node_t* LIST_GET_PREVIOUS(list_t *listroot, list_node_t *new_node)
{
  if (new_node)
    return new_node->prev;
  else
    return NULL;
}


list_node_t* list_remove_node(list_t *listroot, list_node_t *node)
{
  ASSERT(listroot->length);

  if (node->prev)
    node->prev->next = node->next;
  else
    listroot->listhead.next = node->next;

  if (node->next)
    node->next->prev = node->prev;
  else
    listroot->listhead.prev = node->prev;

  listroot->length--;

  node->next = node->prev = NULL;

  return node;
}


