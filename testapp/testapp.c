#include <stdio.h>

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
    printf("\n\n\n1. Insert at head\n2. Insert at Tail\n3. Remove from head\n4. Remove from tail\n5. Print list\n6. Print in reverse\n7. quit\n");
    printf("\tEnter ur option: ");
    scanf("%u", &user_input);
    getchar();

    if (user_input == 7)
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
#if 0
       case 3:
        {
          data_box_t *data_box = LIST_REMOVE_FROM_HEAD(&data_list);

          printf("\nRemoved node data : %c\n", data_box->data);
        }
        break;
        case 4:
        {
          data_box_t *data_box = LIST_REMOVE_FROM_TAIL(&data_list);

          printf("\nRemoved node data : %c\n", data_box->data);
        }
        break;
#endif
        case 5:
        {
          data_box_t *tmp = LIST_GET_APP_HEAD(&data_list, data_box_t, list_entry);
          
          while(tmp)
          {
            printf("\n %c ", tmp->data);
            tmp = LIST_GET_APP_NEXT(&data_list, &tmp->list_entry, data_box_t, list_entry);
          }
        }
        case 3:
        case 4:
        case 6:
          printf("Not Implemented ");
          break;
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
