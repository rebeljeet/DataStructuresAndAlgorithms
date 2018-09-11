#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *link;
};



void insert_at_begining(struct Node **first,int data)
{
    struct Node *new_node = NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->info = data;
    new_node->link = (*first);
    (*first) = new_node;

}

void insert_after(struct Node **first,int info_of_node_to_insert_after,int data)
{

    struct Node *new_node = NULL;
    struct Node *pred_node = NULL;
    pred_node = (*first);
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->info = data;
    while(pred_node->info != info_of_node_to_insert_after)
    {
        pred_node = pred_node->link;
    }
    new_node->link = pred_node->link;
    pred_node->link = new_node;
}

void insert_at_end(struct Node **first,int data)
{
    struct Node *new_node = NULL;
    struct Node *pred_node = NULL;

    pred_node = (*first);
    new_node = (struct Node *)malloc(sizeof(new_node));
    new_node->info = data;
    while(pred_node->link !=  NULL)
    {
        pred_node = pred_node->link;
    }
    new_node->link = NULL;
    pred_node->link = new_node;

}

void delete_element(struct Node **first,int key)
{
    struct Node *temp = (*first),(*previous_node);

    if(first == NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }

    if(temp != NULL && temp->info == key)
    {
        (*first) = temp->link;
        free(temp);
        return;
    }

    while(temp->info != key && temp != NULL)
    {
        previous_node = temp;
        temp = temp->link;
        if(temp == NULL)
        {
            printf("\nValue %d not found in Linked List.",key);
            return;
        }
    }

    previous_node->link = temp->link;
    free(temp);
}

void printlist(struct Node* n)
{
    printf("\n\t");
    while(n != NULL)
        {
            printf("[%d]--->",n->info);
            n = n->link;
            if(n == NULL)
            {
                printf("[NULL]\n");
            }
        }
}

int main()
{
    int choice,data,info_pred,key;
    struct Node *first = NULL;
    while(1)
    {
        printf("\nPress 1 to INSERT :: Press 2 to DELETE :: Press 0 to EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            {
                exit(0);
            }
        case 1:
            {
                printf("\n\tPress 1 to INSERT at BEGINING");
                printf("\n\tPress 2 to INSERT in BETWEEN");
                printf("\n\tPress 3 to INSERT at END\n");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    {
                        printf("\nEnter the value:");
                        scanf("%d",&data);
                        insert_at_begining(&first,data);
                        printlist(first);
                        break;
                    }
                case 2:
                    {
                        printf("\nEnter  the value:");
                        scanf("%d",&data);
                        printf("\nEnter the value to insert after:");
                        scanf("%d",&info_pred);
                        insert_after(&first,info_pred,data);
                        printlist(first);
                        break;
                    }
                case 3:
                    {
                        printf("\nEnter  the value:");
                        scanf("%d",&data);
                        insert_at_end(&first,data);
                        printlist(first);
                        break;
                    }
                default:
                    {
                        printf("\nEnter valid choice");
                        break;
                    }
                }
                break;
            }
        case 2:
            {
                printf("\nEnter the Value you want to delete:");
                scanf("%d",&key);
                delete_element(&first,key);
                printlist(first);
                break;
            }

        default:
            {
                printf("\nEnter valid choice");
                break;
            }
        }
    }
return 0;
}
