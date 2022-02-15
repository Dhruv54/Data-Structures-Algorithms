#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout<<"Element = "<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct Node *InsertionAtBegin(struct Node *head,int data)
{
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

struct Node *InsertionAtEnd(struct Node *head,int data)
{
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node *p= head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;

    return ptr;
}

struct Node *InsertionAtIndex(struct Node *head,int index,int data)
{
    struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node *p= head;

    int i=0;
    while (i != index-1)
    {
        p=p->next;
        i++;
    }

    ptr->next=p->next;
    p->next=ptr;
    
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *mainnp;

    head= (struct Node *)malloc(sizeof(struct Node));
    second= (struct Node *)malloc(sizeof(struct Node));
    third= (struct Node *)malloc(sizeof(struct Node));
    fourth= (struct Node *)malloc(sizeof(struct Node));
    mainnp= (struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next = second;
    
    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;    
    
    fourth->data=40;
    fourth->next=NULL;
    cout<<"Before insertion"<<endl;
    linkedListTraversal(head);
    // mainnp=InsertionAtBegin(head,90);
    // cout<<"After insertion"<<endl;
    // linkedListTraversal(mainnp);

    // mainnp = InsertionAtEnd(head,150);
    // cout<<"After insertion"<<endl;
    // linkedListTraversal(head);

    mainnp = InsertionAtIndex(head,3,100);
    cout<<"After insertion"<<endl;
    linkedListTraversal(head);

    return 0;
}