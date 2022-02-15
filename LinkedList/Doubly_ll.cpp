#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void circular_llTraversal(struct Node *head)
{
    struct Node *p=head;

    while(p != NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

struct Node *insertionAtBegin(struct Node *head,int element)
{
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->data=element;
    p->prev=NULL;

    head->prev=p;
    p->next=head;
    head=p;

    return head;
}
struct Node *insertionAtlast(struct Node *head,int element)
{
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->data=element;
    struct Node *ptr=head;

    while(ptr->next != NULL){
        ptr=ptr->next;
    }

    ptr->next=p;
    p->next=NULL;
    p->prev=ptr;
    return head;
}

struct Node *insertionAtIndex(struct Node *head,int index,int element)
{
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));
    p->data=element;

    struct Node *ptr=head;

    for (int i = 0; i < index-1; i++)
    {
        ptr=ptr->next;
    }

    p->next=ptr->next;
    ptr->next->prev=p;
    ptr->next=p;
    p->prev=ptr;

    return head;
}

int main()
{
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *first=(struct Node *)malloc(sizeof(struct Node));
    struct Node *second=(struct Node *)malloc(sizeof(struct Node));
    struct Node *third=(struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));

    head->next=first;
    head->prev=NULL;
    head->data=10;

    first->next=second;
    first->prev=head;
    first->data=20;
    
    second->next=third;
    second->prev=second;
    second->data=30;
    
    third->next=fourth;
    third->prev=third;
    third->data=40;
    
    fourth->next=NULL;
    fourth->prev=third;
    fourth->data=50;

    circular_llTraversal(head);
    // head=insertionAtBegin(head,60);
    // head=insertionAtBegin(head,70);
    // head=insertionAtBegin(head,80);
    // head=insertionAtBegin(head,90);

    // head=insertionAtlast(head,60);
    // head=insertionAtlast(head,70);
    // head=insertionAtlast(head,80);
    // head=insertionAtlast(head,90);
    // head=insertionAtlast(head,100);

    // head=insertionAtIndex(head,2,100);
    // head=insertionAtIndex(head,3,90);
    // head=insertionAtIndex(head,4,80);
    circular_llTraversal(head);

    return 0;
}