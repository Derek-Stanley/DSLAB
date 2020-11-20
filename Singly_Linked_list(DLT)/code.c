#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void display();
void delfun();
void insert();

int main()
{ int ch,ele;
  do
 {printf("\n1.Create & Insert\n2.Display\n3.Delete\n4. Exit"); printf("\nEnter your choice : ");
  scanf("%d",&ch);
  switch(ch)
  { case 1 : insert(); break;
    case 2 : display();break;
    case 3 : delfun(); break;
    default: if(ch!=4)
              printf("Invalid option");
  }
 }while(ch!=5);
}


void display()
{ struct node *ptr=NULL;
  ptr=head;
  if(ptr==NULL)
  { printf("Nothing to print\n"); }
  else
  { while(ptr!=NULL)
    { printf("%d ",ptr->data);
      ptr=ptr->next; }
  } 
}

void delfun()
{ struct node *temp,*del=NULL;
  if (head == NULL)
  { printf("Empty List.\n");return; }
  temp=head;
  int ch,ele;
  printf("Delete  at:\n1.Front\n2.Back\n3.Desired Element\nEnter choice :");
  scanf("%d",&ch);
    switch(ch)
    { case 1 : del=head;
               head=head->next;
               printf("Node Deleted\n");
               break;
      case 2 : while (temp->next->next!=NULL)
               { temp=temp->next;}
               del=temp->next;
               temp->next=NULL;
               printf("Node Deleted\n");
               break;
      case 3 : printf("Enter the element to delete\n");
               scanf("%d",&ele);
               if(head->data==ele)
               { head=head->next;}
               else
               while (temp->next!=NULL)
               { if(temp->next->data==ele)
                 { del=temp->next;
                   temp->next=del->next;
                 }
                 else
                 temp=temp->next; 
               }
      default : if(ch!=4)
                 printf("\nEnter Valid Choice");
    }
  if(del==NULL)
  { printf("Element not found in the list\n"); }  
}

 void insert()
 {  
    struct node  *temp, *newnode;
    int item;
    newnode =(struct node *) malloc (sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&item);
    newnode->data=item;
    if(head==NULL)
    { head=newnode;}
    else
    { temp=head;
      while(temp->next!=NULL)
      { temp=temp->next; }
      temp->next=newnode;
      newnode->next=NULL;
      printf("Node created\n");
    }
 }
