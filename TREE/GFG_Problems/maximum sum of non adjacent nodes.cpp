    pair<int,int> solve(Node*root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        
        pair<int,int> lh=solve(root->left);
        pair<int,int> rh=solve(root->right);
        
        pair<int,int> res;
        
        res.first=root->data+lh.second+rh.second;
        res.second=max(lh.first,lh.second)+max(rh.first,rh.second);
        
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
        
    }
