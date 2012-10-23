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



#define LIST_GET_APP_HEAD(listroot, type, list_member) \
            LIST_GET_HEAD(listroot) ? ((type*) ((unsigned long) (LIST_GET_HEAD(listroot)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;
#define LIST_GET_APP_NEXT(listroot, node, type, list_member) \
            LIST_GET_NEXT(listroot, node) ? ((type*) ((unsigned long) (LIST_GET_NEXT(listroot, node)) - \
                                                (unsigned long)&(((type* )0)->list_member))) : NULL;
