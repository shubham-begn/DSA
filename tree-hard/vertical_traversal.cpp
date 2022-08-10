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

void vertical(node * root)
{
    if(root==NULL) return;

    queue<pair<node*,pair<int , int >>> q;
    map<int,map<int ,vector<node*> >> mp;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty())
    {
        pair<node*,pair<int ,int>> temp=q.front();
        q.pop();

        node * front=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        
        mp[hd][lvl].push_back(front);

        if(front->left!=NULL)
        q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));

        if(front->right!=NULL)
        q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));

        
    }

    for(auto x:mp)
    {
        for(auto y: x.second)
        for(auto z:y.second)
        cout<<z->data<<" ";
    }
}int main()
{
    node * root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->right=new node(50);
    root->right->right->right=new node(70);

    

    vertical(root);
}
