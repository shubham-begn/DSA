#include<bits/stdtr1c++.h>
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
int cnt=0;
vector<int> paths;
void ksumpaths(node *root,int k)
{
    if(root==NULL) return;
    paths.push_back(root->data);
    ksumpaths(root->left,k);
    ksumpaths(root->right,k);

    int sum=0,sz=paths.size();
    for(int i=sz-1;i>=0;i--)
    {
        sum+=paths[i];
        if(sum==k) cnt++;
    }
paths.pop_back();

}

void kthancestor(node *root,int k,int target)
{
    if(root==NULL) return ;
   

}
int main()
{
    node *root=new node(1);
    root->left=new node(9);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(2);
    root->right->left=new node(60);
    root->right->left=new node(70); 
    int k=2;
    ksumpaths(root,k);
    kthancestor(root,k,2);
    cout<<cnt;
}