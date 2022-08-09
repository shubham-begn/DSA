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
void verticaltraversal(node *root)
{
    if(root==NULL) return;
    queue<pair <node* ,pair<int,int> > > q;
    map<int, map<int,vector<int> > > mp;

    q.push(make_pair(root,make_pair(0,0)));
    while(q.empty()==false)
    {
        pair<node *,pair<int,int> >  temp=q.front();
        q.pop();
        node * t=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;

        mp[hd][lvl].push_back(t->data);

        if(t->left!=NULL) q.push(make_pair(t->left,make_pair(hd-1,lvl+1)));
        if(t->right!=NULL) q.push(make_pair(t->right,make_pair(hd+1,lvl+1)));

    }
    for(auto i: mp){
    for(auto k: i.second){
    for(auto j: k.second){
    cout<<j<<" ";
}}}

}
int main()
{
    node *root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node(50);
    root->right->left=new node(60);
    root->right->left=new node(70); 
    verticaltraversal(root);

}