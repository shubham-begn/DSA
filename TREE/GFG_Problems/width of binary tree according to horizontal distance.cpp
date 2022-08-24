void solve(Node *root,unordered_set<int> &s,int hd)
{
    if(root==NULL) return ;
    s.insert(hd);
    solve(root->left,s,hd-1);
    solve(root->right,s,hd+1);
}
int verticalWidth(Node* root)
{
    unordered_set<int> s;
    solve(root,s,0);
    return s.size();
}
