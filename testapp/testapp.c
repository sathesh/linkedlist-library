#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct data_box
{
  char data;
  list_node_t list_entry;
}data_box_t;


data_box_t* create_data_box();

list_t data_list;

void main()
{
  unsigned int user_input;

  LIST_INIT(&data_list);
  
  do
  {
    user_input = 777;
    printf("\n\n\n0. quit\n1. Insert at head\n2. Insert at Tail\n3. get from head\n" \
                  "4. get from tail\n5. Print list\n6. Print in reverse\n" \
                  "7. print list length\n8. Remove all nodes \n");
    printf("\tEnter ur option: ");
    scanf("%u", &user_input);
    getchar();

    if (user_input == 0)
      break;

    switch(user_input)
    {
      case 1:
        {
          data_box_t *data_box = create_data_box();
          LIST_INSERT_AT_HEAD(&data_list, &data_box->list_entry);
        }
        break;
      case 2:
        {
          data_box_t *data_box = create_data_box();
          LIST_INSERT_AT_TAIL(&data_list, &data_box->list_entry);
        }
        break;
       case 3:
        {
          data_box_t *tmp = LIST_GET_MEMBER_HEAD(&data_list, data_box_t, list_entry);
          if (tmp)
            printf("\nHead member data: %c\n\n", tmp->data);
          else
            printf("\nlist empty\n\n");

        }
        break;
        case 4:
        {
          data_box_t *tmp = LIST_GET_MEMBER_TAIL(&data_list, data_box_t, list_entry);
          if (tmp)
            printf("\ntail member data: %c\n\n", tmp->data);
          else
            printf("\nlist empty\n\n");
        }
        break;
        case 5:
        {
          data_box_t *tmp = LIST_GET_MEMBER_HEAD(&data_list, data_box_t, list_entry);
          
          while(tmp)
          {
            printf("\n %c ", tmp->data);
            tmp = LIST_GET_MEMBER_NEXT(&data_list, &tmp->list_entry, data_box_t, list_entry);
          }
        }
        break;
        case 6:
         {
          data_box_t *tmp = LIST_GET_MEMBER_TAIL(&data_list, data_box_t, list_entry);
          
          while(tmp)
          {
            printf("\n %c ", tmp->data);
            tmp = LIST_GET_MEMBER_PREVIOUS(&data_list, &tmp->list_entry, data_box_t, list_entry);
          }
        }
          break;
        case 7:
          printf("List length : %u\n", LIST_GET_LENGTH(&data_list));
          break;
         case 8:
        {
          data_box_t *tmp = LIST_GET_MEMBER_HEAD(&data_list, data_box_t, list_entry);
          
          while(tmp)
          {
            data_box_t *next;
            next = LIST_GET_MEMBER_NEXT(&data_list, &tmp->list_entry, data_box_t, list_entry);
            LIST_REMOVE_MEMBER(&data_list, tmp, list_entry);
            free(tmp);
            tmp = next;
          }
          printf("List is empty now!!\n\n");
        }
       default:
          break;
    }


  }while(1);
}


data_box_t* create_data_box()
{
  data_box_t *data_box = malloc (sizeof(data_box_t));
  printf("\nEnter Data char: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%c", &data_box->data);
  return data_box;
}
