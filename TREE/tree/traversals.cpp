#include<bits/stdc++.h>
using namespace std;
struct node
{
   int data;
   node * left;
   node * right;
   node(int x)
   {
       data=x;
       left=right=NULL;
   }
};
void inorder(node * root)
{
    if(root!=NULL)
    {inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }
}
void preorder(node * root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    } 
}
void postorder(node * root)
{
    if(root!=NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    } 
}
int height(node * root)
{
    if(root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}
int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    postorder(root);
    cout<<"\n";
    cout<<"height="<<height(root);
    return 0;
}