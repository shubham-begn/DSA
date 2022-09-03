 void solve(TreeNode* root,int value,int &ans)
    {
        if(root==NULL) return;
        value=value*10+root->val;
        if(root->left==NULL && root->right==NULL)
        {
          ans+=value;
        }
        solve(root->left,value,ans);
        solve(root->right,value,ans);
        
    }
    int sumNumbers(TreeNode* root) {
        int ans=0,value=0;
        if(root==NULL) return ans;
        
        solve(root,value,ans);
        return ans;
    }
