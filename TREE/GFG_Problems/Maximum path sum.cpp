int solve(Node* root,int &ans)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int lh=max(0,solve(root->left,ans));
        int rh=max(0,solve(root->right,ans));
        
        
         ans=max(ans,lh+rh+root->data);
        return (max(lh,rh)+root->data);
        
       
    }
    void solve1(Node* root,int &ans)
    {
        if(root==NULL) return;
        
        solve1(root->left,ans);
        ans=max(ans,root->data);
        solve1(root->right,ans);
    }
    int findMaxSum(Node* root)
    {
        int ans=INT_MIN;
       int temp=solve(root,ans);
        solve1(root,ans);
        return ans;
        
    } 
