    void solve1(TreeNode* root,int &ans)
    {
        if(root==NULL) return;
        ans+=root->val;
        solve1(root->left,ans);
        solve1(root->right,ans);
    }
    int solve(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
        {
            int temp=root->val;
            root->val=0;
            return temp;
        }
        
        int lh=solve(root->left);
        int rh=solve(root->right);
        
        int temp=root->val+lh+rh;
        root->val=abs(lh-rh);
        return temp;
    }
    int findTilt(TreeNode* root) {
        int temp=solve(root);
        int ans=0;
        solve1(root,ans);
        return ans;
    }
