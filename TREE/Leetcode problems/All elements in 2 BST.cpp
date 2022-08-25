 void solve(TreeNode* root,vector<int> &v)
    {
        if(root==NULL) return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    
    void merge(vector<int> v1,vector<int> v2,vector<int> &ans)
    {
        int n1=v1.size();
        int n2=v2.size();
        
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(v1[i]<=v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            else
            {
                ans.push_back(v2[j]);
                j++;
            }
        }
        
        while(i<n1)
        {
            ans.push_back(v1[i]);
            i++;
        }
        while(j<n2)
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        vector<int> ans;
        
        solve(root1,v1);
        solve(root2,v2);
        
        merge(v1,v2,ans);
        return ans;
        
        
    }
