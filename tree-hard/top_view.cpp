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
void topview(node* root)
{
    if(root==NULL) return;

    queue<pair<node*, int>> q;
    map<int,node*> mp;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node* ,int> temp=q.front();
        q.pop();
        node* f=temp.first;
        int hd=temp.second;

        if(mp.find(hd)==mp.end())
        {
            mp[hd]=f;

        }

        if(f->left!=NULL) q.push(make_pair(f->left,hd-1));
        if(f->right!=NULL) q.push(make_pair(f->right,hd+1));

    }

    for(auto x: mp)
    cout<<x.second->data<<" ";

}
int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->right->right=new node(70);

    

    topview(root);
}