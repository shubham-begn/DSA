void solve(TreeNode* root,int k,unordered_set<int> &s,bool &ans)
    {
        if(root==NULL) return;
        
        int temp=k-root->val;
        if(s.find(temp)!=s.end()) ans=true;
        else s.insert(root->val);
        
        solve(root->left,k,s,ans);
        solve(root->right,k,s,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans=false;
        unordered_set<int> s;
        
        solve(root,k,s,ans);
        return ans;
    }
