 TreeNode* solve(vector<int> nums,int st,int en)
    {   if(st>=en) return NULL;
        
        int mx=nums[st];
        int index=st;
        for(int i=st+1;i<en;i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                index=i;
            }
        }
     
     TreeNode * root=new TreeNode(mx);
     root->left=solve(nums,st,index);
     root->right=solve(nums,index+1,en);
     
     return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size());
    }
