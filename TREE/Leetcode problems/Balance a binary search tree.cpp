 TreeNode* build(vector<int> in,int st,int en)
    {   if(st>en) return NULL;
        int mid=(st+en)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left=build(in,st,mid-1);
        root->right=build(in,mid+1,en);
        
        return root;
    }
    void traverse(TreeNode* root,vector<int> &in)
    {
        if(root==NULL) return;
        traverse(root->left,in);
        in.push_back(root->val);
        traverse(root->right,in);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        traverse(root,in);
        return build(in,0,in.size()-1);
    }
