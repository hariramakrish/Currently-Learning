#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val ;
    struct node * next;
}node;

node *  create (node * p , int val)
{
        p = (node *)malloc(sizeof(node));
        p->val  = val;
        p->next = NULL;
        return p;
}
void add(node ** p,int val)
{
    
    if(*p == NULL)
    {
        *p = create(*p,val);
        (*p)->next = *p;
    }
    else
    {
        node * temp = *p;
        while (temp->next != *p)
        {
            temp = temp->next;
        }
        
        temp->next = (node *)malloc(sizeof(node));
        temp->next->val  = val;
        temp->next->next = *p;
    }
}

void insert(node ** p,int val,int pos)
{
    node * temp = create(temp,val);
    if(*p == NULL)
    {
        printf("Node is Emty");
    }
    if(pos == 0)
    {
        temp->next = *p;
        *p = temp;
        do{
            temp = temp->next;
          }while(temp->next != (*p)->next);
          temp->next = *p;
          return;
    }
    else
    {
        node * current = *p;
        for(int i = 1; i < pos; i++)
        {
            current = current->next;
               
            if(current == *p )
            {
                printf("invail position namber\n");
                return;
            }
            
        }
        temp->next = current->next;
        current->next = temp;
    }
}
void Remove(node ** p,int pos)
{
    node * current = *p;
    
    if(pos == 0)
    {
        while(current->next != *p)
        {
            current = current->next;
        }
        *p = (*p)->next;
        current->next = *p;
        
    }
    else
    {
        for(int i = 1; i < pos; i++)
        {
            current = current->next;
               
            if(current == *p )
            {
                printf("invail position namber\n");
                return;
            }
            
        }
        current->next = current->next->next;
    }
}
void display(node * p)
{
    node * last = p;
   
   do{
        printf("%d\n",p->val);
        p = p->next;
    } while(p != last);
}


int main() 
{
    node * New;
    add(&New,1);
    add(&New,2);
    add(&New,3);
    insert(&New,5,0);
    insert(&New,4,4);
    Remove(&New,0);
    Remove(&New,3);
    display(New);
    return 0;
}
