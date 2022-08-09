#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left,*right;
    int data;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
void spiral(node *root)
{
    stack<node *> s1,s2;
    s1.push(root);

    while(!s1.empty()|| !s2.empty())
    {
        while(!s1.empty())
        {
            node * temp=s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL) s2.push(temp->left);
            if(temp->right!=NULL) s2.push(temp->right);

        }

        while(!s2.empty())
        {
            node* temp=s2.top();
            s2.pop();

            cout<<temp->data<<" ";

            if(temp->right!=NULL) s1.push(temp->right);
            if(temp->left!=NULL) s1.push(temp->left);
        }
    }
}
node *pr=NULL;
node*nh=NULL;
void ttodll(node*root)
{
if(root==NULL) return;

ttodll(root->left);
if(pr==NULL)
{
    nh=root;
    root->left=pr;
}
else 
{
root->left=pr;
pr->right=root;
}
pr=root;
ttodll(root->right);

}
int solve(node* root,bool &ans)
{
    if(root==NULL) return 0;
    int lh=solve(root->left,ans);
    int rh=solve(root->right,ans);

    if(abs(lh-rh)>1) ans=false;
    return 1+max(lh,rh);
}
bool balance(node*root)
{
    bool ans=true;
    int h=solve(root,ans);
    return ans;
}
bool childsum(node* root)
{
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;

    int sum=0;
    if(root->left!=NULL) sum+=root->left->data;
    if(root->right!=NULL) sum+=root->right->data;

    if(sum==root->data && childsum(root->left) && childsum(root->right))
    return true;

    else return false;

}
int maxlevel=0;
void leftview2(node*root,int level)
{
   if(root==NULL) return;
   if(maxlevel<level) 
   {
    cout<<root->data<<" ";
    maxlevel=level;
   }

   leftview2(root->left,level+1);
   leftview2(root->right,level+1);
}
void leftview(node*root)
{
    if(root==NULL) return;
    queue<node*> q;

    q.push(root);

    while (!q.empty())
    {
        int cnt=q.size();
        for(int i=0;i<cnt;i++)
        {
            node * temp=q.front();
            q.pop();

            if(i==0) cout<<temp->data<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
    
}
void lvl2(node* root)
{
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int cnt=q.size();
        for(int i=0;i<cnt;i++)
        {
            node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        cout<<"\n";
    }
}
void lvl(node*root)
{
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>1)
    {
        node * temp =q.front();
        q.pop();
        if(temp==NULL)
        {   cout<<"\n";
            q.push(NULL);
            continue;
        }
        else 
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }
}
int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->right->right=new node(70);

    // ttodll(root);

    // while(nh!=NULL)
    // {
    //     cout<<nh->data<<" ";
    //     nh=nh->right;
    // }

    spiral(root);
}