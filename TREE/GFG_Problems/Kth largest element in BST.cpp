void solve(Node*root,int k,int &cnt,int &ans)
    {
        if(root==NULL) return;
        solve(root->right,k,cnt,ans);
        cnt++;
        if(cnt==k)
        {
            ans=root->data;
            return;
        }
        solve(root->left,k,cnt,ans);
    }
    int kthLargest(Node *root, int k)
    {
    int cnt=0,ans;
    solve(root,k,cnt,ans);
    return ans;
    }
