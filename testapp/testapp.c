#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct data_box
{
  char data;
  list_node_t list_member;
}data_box_t;


data_box_t* create_data_box();
int cmp_char(char* a, char* b);

list_t data_list;



void main()
{
  unsigned int user_input;
  char *buffer = NULL;
  int read_len;
  int buf_len;

  LIST_INIT(&data_list);
  
  do
  {
    printf("\n\n\n100. quit\n1. Insert at head\n2. Insert at Tail\n3. get from head\n" \
                  "4. get from tail\n5. Print list\n6. Print in reverse\n" \
                  "7. print list length\n8. Remove all nodes \n9. lookup \n10. remove from head \n11. remove from tail \n\n");
    printf("\tEnter ur option: ");

    read_len = getline(&buffer, &buf_len, stdin);
    if (read_len == -1)
      break;

    if (buffer[0] == '\0')
      continue;

    user_input = atoi(buffer);
    free(buffer);
    buffer = NULL;

    switch(user_input)
    {
      case 100:
        exit(0);
      case 1:
        {
          data_box_t *data_box = create_data_box();
          LIST_INSERT_AT_HEAD(&data_list, &data_box->list_member);
        }
        break;
      case 2:
        {
          data_box_t *data_box = create_data_box();
          LIST_INSERT_AT_TAIL(&data_list, &data_box->list_member);
        }
        break;
       case 3:
        {
          data_box_t *tmp = LIST_GET_ENTRY_HEAD(&data_list, data_box_t, list_member);
          if (tmp)
            printf("\nHead member data: %c\n\n", tmp->data);
          else
            printf("\nlist empty\n\n");

        }
        break;
        case 4:
        {
          data_box_t *tmp = LIST_GET_ENTRY_TAIL(&data_list, data_box_t, list_member);
          if (tmp)
            printf("\ntail member data: %c\n\n", tmp->data);
          else
            printf("\nlist empty\n\n");
        }
        break;
        case 5:
        {
          data_box_t *tmp = LIST_GET_ENTRY_HEAD(&data_list, data_box_t, list_member);
          
          while(tmp)
          {
            printf("\n %c ", tmp->data);
            tmp = LIST_GET_ENTRY_NEXT(&data_list, &tmp->list_member, data_box_t, list_member);
          }
        }
        break;
        case 6:
         {
          data_box_t *tmp = LIST_GET_ENTRY_TAIL(&data_list, data_box_t, list_member);
          
          while(tmp)
          {
            printf("\n %c ", tmp->data);
            tmp = LIST_GET_ENTRY_PREVIOUS(&data_list, &tmp->list_member, data_box_t, list_member);
          }
        }
          break;
        case 7:
          printf("List length : %u\n", LIST_GET_LENGTH(&data_list));
          break;
        case 8:
        {
          data_box_t *tmp = LIST_GET_ENTRY_HEAD(&data_list, data_box_t, list_member);
          
          while(tmp)
          {
            data_box_t *next;
            next = LIST_GET_ENTRY_NEXT(&data_list, &tmp->list_member, data_box_t, list_member);
            LIST_REMOVE_ENTRY(&data_list, tmp, list_member);
            free(tmp);
            tmp = next;
          }
          printf("List is empty now!!\n\n");
        }
        case 9:
        {
          data_box_t *tmp = NULL;
          char key1;

          printf("Enter Key to lookup: ");
          key1 = getchar();
          LIST_LOOKUP_ENTRY(&data_list, &key1, data, data_box_t, list_member, cmp_char, tmp);

          if (tmp)
          {
            printf("Look up success!!\n");
          }
          else
          {
            printf("Look up Fail!!\n");
          }
        }
        break;
        case 10:
        {
          data_box_t *tmp = NULL;
          LIST_REMOVE_ENTRY_HEAD(&data_list, data_box_t, list_member, tmp);
          if (tmp)
          {
            printf("Head node removed: %c\n", tmp->data);
          }
          else
          {
            printf("List must be empty\n");
          }

        }
        break;
        case 11:
        {
          data_box_t *tmp = NULL;
          LIST_REMOVE_ENTRY_TAIL(&data_list, data_box_t, list_member, tmp);
          if (tmp)
          {
            printf("Tail node removed: %c\n", tmp->data);
          }
          else
          {
            printf("List must be empty\n");
          }
        }
        break;

        default:
          break;
    }


  }while(1);
}


data_box_t* create_data_box()
{
  char *buffer = NULL;
  int read_len;
  int buf_len;
  data_box_t *data_box = malloc (sizeof(data_box_t));
  printf("\nEnter Data char: ");

  read_len = getline(&buffer, &buf_len, stdin);
  if (read_len == -1)
    exit(0);

  data_box->data = *buffer;
  free(buffer);
 
  return data_box;
}

int cmp_char(char* a, char* b)
{
  if (*a == *b)
    return 0;
  else
    return 1;
}


