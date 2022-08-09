#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;

    }
};

void inorder(node* root)
{
if(root==NULL) return;

stack<node*> s;
//s.push(root);
node* curr=root;

while(curr!=NULL || s.empty()==false)
{
    while(curr!=NULL)
    {
        s.push(curr);
        curr=curr->left;
    }
    curr=s.top();
    s.pop();
    cout<<curr->data;
    curr=curr->right;
}

}

void preorder(node *root)
{
    if(root==NULL) return;
    stack<node* > s;
    s.push(root);
    while(!s.empty())
    {   node *temp=s.top();
    s.pop();
        cout<<temp->data;
        if(temp->right!=NULL) s.push(temp->right);
        if(temp->left!=NULL) s.push(temp->left);
    }

}
void postorder(node * root)
{
    if(root==NULL) return;
    stack<node*> s;
    node * curr=root;
    s.push(root);
    while(!s.empty()|| curr!=NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr=curr->left;
        }
        if(curr==NULL)
        {   cout<<s.top()->data;  
            curr=s.top()->right;
            
        }
    }

}
int main()
{
     node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(6);
    root->right->left = new node(5);
    root->right->right = new node(4);

    //inorder(root);
    preorder(root);
}