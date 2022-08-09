#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data ;
    node *left;
    node *right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

void inorder(node * root)
{
    if(root==NULL) return ;
    stack<node *> s;
 
    node *curr=root;
    while(curr!=NULL ||  s.empty()==false)
    {
        while(curr!=NULL)
       {
        s.push(curr);
        curr=curr->left;
       }
    curr=s.top();
    s.pop();
    cout<<curr->data<<" ";
    curr=curr->right;

    }
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->left->left=new node(7);
    root->left->right->left->left->right=new node(8);

    inorder(root);
}
