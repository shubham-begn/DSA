#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorder(node *root)
{
    if(root==NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root)
{
  if(root==NULL)
    return ;
    
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}   

void postorder(node *root)
{
    if(root==NULL)
    return ;
    
    
    postorder(root->left);
    
    postorder(root->right);
    
    cout<<root->data<<" ";
}

int height(node * root)
{
   if(root==NULL)
   return 0;

   int lh=height(root->left);
   int rh=height(root->right);
   return 1+max(lh,rh);
}

void printknodes(node* root,int k)
{
    if(root==NULL) return ;
    if(k==0) cout<<root->data<<" ";
    printknodes(root->left,k-1);
    printknodes(root->right,k-1);

}
void levelorder(node * root)
{
    if(root==NULL) return ;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node * curr=q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}

void linebyline(node * root)
{
    if(root==NULL) return ;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
       
        if(q.front()==NULL)
       {
           cout<<"\n";
           q.push(NULL);
           q.pop();
       }
       
        node *curr=q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);


    }
}

void linebyline2(node * root)
{
    if(root==NULL) return ;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        for(int i=0;i<sz;i++)
        {
          node * curr=q.front();
          cout<<curr->data<<" ";
          q.pop();
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
        }
        cout<<"\n";

    }
}

int size(node * root)
{
    if(root==NULL) return 0;

    int ls=size(root->left);
    int rs=size(root->right);

    return 1+ls+rs;
}
int maxm(node * root)
{
    if(root==NULL) return -1;

    int ls=maxm(root->left);
    int rs=maxm(root->right);

    return max(root->data,max(ls,rs));
}
void leftview(node *root)
{
    if(root==NULL) return;
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
         int sz=q.size();
        for(int i=0;i<sz;i++)
        {
          node * curr=q.front();

          if(i==0)
          cout<<curr->data<<" ";

          q.pop();
          if(curr->left!=NULL) q.push(curr->left);
          if(curr->right!=NULL) q.push(curr->right);
        }
    }
}
int maxlevel=0;
void leftview2(node * root,int lvl)
{

   if(root==NULL) return ;
   if(maxlevel<lvl)
    { 
        cout<<root->data<<" ";
        maxlevel++;
    }

   leftview2(root->left,lvl+1);
   leftview2(root->right,lvl+1);
}


bool child(node * root)
{
    if(root==NULL) return true;

    if(root->left==NULL && root->right==NULL) return true; // for leaf nodes

     int sm=0;
     if(root->left!=NULL) sm+=root->left->data;
     if(root->right!=NULL) sm+=root->right->data;
    if(root->data==sm && child(root->left) && child(root->right))
    return true;

    else return false;
}
bool ans=true;
int balance(node * root)
{
    if(root==NULL)
    return 0;

    int lh=balance(root->left);
    int rh=balance(root->right);

    if(abs(lh-rh)>1) ans=false;

    return 1+max(lh,rh);
}

int width(node *root)
{
    if(root==NULL) return 0;
    queue<node *> q;
    q.push(root);
    int ans1=1;
    while(!q.empty())
    {
       if(ans1<q.size()) ans1=q.size();
       for(int i=0;i<q.size();i++)
       {
           node *curr=q.front();
           q.pop();
           if(curr->left!=NULL) q.push(root->left);
           if(curr->right!=NULL) q.push(root->right);

       }
    }

    return ans1;
}vector<int> a;
bool path(node *root,int x)
{   if(root==NULL) return false;
    a.push_back(root->data);
 
    if((root->data==x) || path(root->left,x) || path(root->right,x)) return true;
    else
    {
        a.pop_back();
        return false;
    }


    
}
node *pr=NULL;
node *head=NULL;
void tree2dll(node * root)
{
    if(root==NULL) return ;
    tree2dll(root->left);
    if(head==NULL)
    {
        head=root;
        pr=root;
    }
    else{
    root->left=pr;
    pr->right=root;
    pr=root;
    }
    tree2dll(root->right);


}
 int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    //root->right->right->right=new node(70);

   
   
   tree2dll(root);
   node * c=head;
   while(c!=NULL)
   {
       cout<<c->data<<" ";
       c=c->right;
   }
   
    return 0;
}
