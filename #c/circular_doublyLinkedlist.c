#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node * prev;
    struct node * next;
}node;

node * create(node * p, int val)
{
       p = (node *) malloc(sizeof(node));
       p->val  = val;
       p->prev = NULL;
       p->next = NULL;
       return p ;
}

void add(node ** p, int val)
{
    if(*p == NULL)
    {
     *p = create(*p,val);
     (*p)->next = *p;
     (*p)->prev = *p;
    }
    else
    {
      node * temp = *p;    
      do
      {
          temp = temp->next;
          
      }while(temp->next != *p);
      
      temp->next = (node *) malloc(sizeof(node));
      temp->next->val  = val;
      temp->next->prev = temp;
      temp->next->next = *p;
            (*p)->prev = temp->next;                               
    }
}

void insert (node ** p, int val, int pos)
{
 
   node * temp = create(temp,val);
   if(pos == 0)
   {
       temp->prev = (*p)->prev;
       temp->next = *p;
       temp->next->prev = temp;
       temp->prev->next = temp;
       *p = temp;
   }
   else
   {
       node * crt = *p; 
       for(int i = 1; i < pos; i++)
       {
           crt = crt->next;
       }
       crt->next->prev = temp;
       temp->next = crt->next;
       crt->next  = temp;
       temp->prev = crt; 
       
   }
    
}
void removN (node ** p, int pos)
{
   node * crt = *p;
   if(pos == 0)
   {
      crt->next->prev = (*p)->prev;
      crt->prev->next = (*p)->next;
      *p = (*p)->next;
   }
   else
   {
       for(int i = 1; i < pos; i++)
       {
           crt = crt->next;
       }
       
       (*p)->prev = crt;
       crt->next  = crt->next->next;
   }
    
}

void display(node * p)
{
    node * temp = p;
    do{
        printf("%d\n",p->val);
        p = p->next;
      }while(p != temp);
}

void revers(node * p)
{
    node * temp = p;
    do{
        printf("%d\n",p->val);
        p = p->prev;
      }while(p != temp);
}


int main() 
{
    
    node * New;
    add(&New,1);
    add(&New,2);
    add(&New,3);
    insert(&New,0,0);
    insert(&New,4,4);
    removN(&New,0);
    removN(&New,3);
    display(New);
    revers(New);
    return 0;
}
