#include<stdio.h>
#include<stdlib.h>
#define SIZE_OF_FREE_LIST 5

struct Free_List{
    int info;
    struct free_list* link;
}free_list[SIZE_OF_FREE_LIST];

int *avail;

int check_for_free_list_underflow(struct Free_List free_list)
{
    avail = &free_list;
    if(avail == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void get_node_from_free_list(struct Free_List free_list)
{
     struct Free_List *new_node;
    if(check_for_free_list_underflow(free_list) == 1)
    {
        printf("FREE LIST UNDERFLOW");
    }
    else
    {
        new_node = avail;
        avail = link->avail;
    }
}

void printlist(struct linked_list* n)
{
    while(n != NULL)
        {
            printf("%d__[%d|%d]->",n,n->info,n->link);
            n = n->link;
        }
}

main()
{


       return 0;
}
