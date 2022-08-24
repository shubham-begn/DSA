TreeNode* abc(vector<int>& nums,int st,int en)
    {if(st>en) return NULL;
        
     int mid=(st+en)/2;
     TreeNode * root=new TreeNode(nums[mid]);
        root->left=abc(nums,st,mid-1);
        root->right=abc(nums,mid+1,en);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
      
        TreeNode * a=abc(nums,0,n-1);
        return a;
       
        
    }
