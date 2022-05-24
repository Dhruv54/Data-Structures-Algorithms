#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preOrder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node* root)
{
    if(root!=NULL)
    {
        preOrder(root->left);
        preOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(struct Node* root)
{
    if(root!=NULL)
    {
        preOrder(root->left);
        printf("%d ",root->data);
        preOrder(root->right);
    }
}

int main()
{
    // struct Node* p;
    // p=(struct Node*)malloc(sizeof(struct Node));
    // p->data=2;

    // struct Node* p1;
    // p1=(struct Node*)malloc(sizeof(struct Node));
    // p1->data=3;

    // struct Node* p2;
    // p2=(struct Node*)malloc(sizeof(struct Node));
    // p2->data=4;
    struct Node* p;struct Node* p1;struct Node* p2;struct Node* p3;struct Node* p4;struct Node* p5;struct Node* p6;
    p=createNode(11);
    p1=createNode(10);
    p2=createNode(9);
    p3=createNode(8);
    p4=createNode(7);
    p5=createNode(6);
    p6=createNode(5);

    //   11
    //  /  \
    // 10  9
    // /\  /\
    //8 7 6  5

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    // printf("%d ",p->data);
    // printf("%d ",p1->data);
    // printf("%d ",p2->data);
    preOrder(p);printf("\n");
    postOrder(p);printf("\n");
    inOrder(p);
    return 0;
}