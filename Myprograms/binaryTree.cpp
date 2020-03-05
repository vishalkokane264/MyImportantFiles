#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<queue>
using namespace std;
typedef struct tree
{
    int data;
    struct tree *left_node, *right_node;
}tree;

tree* createNode(int data)
{
    tree* node=new tree();
    node->data=data;
    node->left_node=NULL;
    node->right_node=NULL;
    return node;
}

void insert(tree *root,int key)
{
    queue<tree*> myQ;
    myQ.push(root);
    while(!myQ.empty())
    {
        tree *node=myQ.front();
        myQ.pop();
        if(node->left_node==NULL)
        {
            node->left_node=createNode(key);
            break;
        }
        else
        {
            myQ.push(node->left_node);
        }
        if(node->right_node==NULL)
        {
            node->right_node=createNode(key);
            break;
        }
        else
        {
            myQ.push(node->right_node);
        }
    }
}
void printTree(tree *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printTree(root->left_node);
        printf(" %d ",root->data);
        printTree(root->right_node);
    }    
}

int isBst(tree *root,int min,int max)
{
    if(root==NULL)
    {
        return 1;
    }
    if(root->data<min || root->data>max)
    {
        return 0;
    }
    return isBst(root->left_node,min,root->data)&& isBst(root->right_node,root->data,max);
}

int isBST(tree *root)
{
    if(isBst(root,0,10001))
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}
tree* insertBst(tree *root,int data)
{
    if(root==NULL)
    {
        root=createNode(data);
        return root;
    }
    else
    {
        if(root->data<data)
        {
            root->right_node=insertBst(root->right_node,data);
        }
        else
        {
            root->left_node=insertBst(root->left_node,data);
        }        
    }
    

}
void printAllLeafNode(tree *root)
{
    queue<tree*> myq;
    myq.push(root);
    while(!myq.empty())
    {
        tree *temp=myq.front();
        myq.pop();
        if(temp->left_node==NULL && temp->right_node==NULL)
        {
            printf("%d ",temp->data);
        }
        if(temp->left_node)
        myq.push(temp->left_node);
        if(temp->right_node)
        myq.push(temp->right_node);
    }
}
int main()
{
    tree *root;
    int key;
    printf("1.Tree data:");
    key=rand()%1000;
    printf("%d ",key);
    root=createNode(key);
    for(int i=0;i<10;i++)
    {
        key=rand()%1000;
        printf("%d ",key);
        insert(root,key);
//        insertBst(root,key);
    }
    printf("\n");
    printf("2.Printing in inorder:");
    printTree(root);
    printf("\n3.Is Bst?:");
    if(isBST(root))
    {
        printf("Tree is bst\n");
    }
    else
    {
        printf("Tree is not bst\n");
    }
    printf("4.Printing all leaf nodes:");
    printAllLeafNode(root);
}