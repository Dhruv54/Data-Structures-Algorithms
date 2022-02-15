#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void TraverseLL(struct Node *head)
{
    struct Node *p=head;
    while (p != NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

struct Node* deletionAtBegining(struct Node *head)
{
    struct Node *p=head;
    head=head->next;
    free(p);
    return head;
}

struct Node* deletionAtEnding(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while (q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node* deletionAtIndex(struct Node *head,int index)
{
    struct Node *p=head;
    struct Node *q=head->next;

    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node* deletionAtElement(struct Node* head,int element)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while (q->data != element && q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }

    if(q->data==element){
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node* head=(struct Node *)malloc(sizeof(struct Node));
    struct Node* first=(struct Node *)malloc(sizeof(struct Node));
    struct Node* second=(struct Node *)malloc(sizeof(struct Node));
    struct Node* third=(struct Node *)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    first->data=20;
    second->data=30;
    third->data=40;
    fourth->data=50;

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    cout<<"Before Deletion :"<<endl;
    TraverseLL(head);
    cout<<"After Deletion :"<<endl;
    // head=deletionAtBegining(head);
    // TraverseLL(head);
    // head=deletionAtEnding(head);
    // TraverseLL(head);
    // head=deletionAtIndex(head,10);
    // TraverseLL(head);
    head=deletionAtElement(head,40);
    TraverseLL(head);

    return 0;
}