  void solve(TreeNode* root,int sum,vector<vector<int>> &ans,vector<int> &v)
    {
        if(root==NULL) return;
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL && sum-root->val==0)
        {
            ans.push_back(v);
        }
        solve(root->left,sum-root->val,ans,v);
        solve(root->right,sum-root->val,ans,v);
        
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        if(root==NULL) return ans;
        solve(root,targetSum,ans,v);
        return ans;
       
    }
