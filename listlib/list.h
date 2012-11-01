/* 
   File Name : list.h


   Revision history
   ----------------------------------------------------------------------------
  | Changed by  | Description                                                  |
   ----------------------------------------------------------------------------
  | Sathesh    - Initial version
   ----------------------------------------------------------------------------

   */

#define ASSERT  assert
typedef struct list_node
{
  struct list_node *prev;
  struct list_node *next;
}list_node_t;


typedef struct
{
  list_node_t listhead;
  unsigned int length;
}list_t;


void LIST_NODE_INIT(list_node_t *node);
void LIST_INIT(list_t *listroot);
void list_insert_before(list_t *listroot, list_node_t *new_node, list_node_t *before_this_node);
list_node_t* list_remove_node(list_t *listroot, list_node_t *node);


#define LIST_GET_LENGTH(listroot) ((listroot)->length)
#define LIST_GET_HEAD(listroot)   ((listroot)->listhead.next)
#define LIST_GET_TAIL(listroot)   ((listroot)->listhead.prev)
#define LIST_INSERT_AT_HEAD(listroot, new_node) \
  list_insert_before(listroot, new_node, (LIST_GET_HEAD(listroot)))

#define LIST_INSERT_AT_TAIL(listroot, new_node) \
  list_insert_before(listroot, new_node, NULL)


#define LIST_GET_MEMBER_HEAD(listroot, type, list_member) \
            LIST_GET_HEAD(listroot) ? ((type*) ((unsigned long) (LIST_GET_HEAD(listroot)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;

#define LIST_GET_MEMBER_NEXT(listroot, node, type, list_member) \
            LIST_GET_NEXT(listroot, node) ? ((type*) ((unsigned long) (LIST_GET_NEXT(listroot, node)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;

#define LIST_GET_MEMBER_TAIL(listroot, type, list_member) \
            LIST_GET_TAIL(listroot) ? ((type*) ((unsigned long) (LIST_GET_TAIL(listroot)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;

#define LIST_GET_MEMBER_PREVIOUS(listroot, node, type, list_member) \
            LIST_GET_PREVIOUS(listroot, node) ? ((type*) ((unsigned long) (LIST_GET_PREVIOUS(listroot, node)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;



#define LIST_REMOVE_MEMBER(listroot, member, list_member) \
            list_remove_node(listroot, &(member)->list_member)

#define LIST_REMOVE_MEMBER_HEAD(listroot ) \
            list_remove_node(listroot, LIST_GET_HEAD(listroot))
            
#define LIST_REMOVE_MEMBER_TAIL(listroot ) \
            list_remove_node(listroot, LIST_GET_TAIL(listroot))
