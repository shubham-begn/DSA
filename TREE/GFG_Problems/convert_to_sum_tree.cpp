 void solve(Node * root)
    {
        if(root==NULL) return;
        
        int sm=0;
        if(root->left!=NULL) sm+=root->left->data;
        if(root->right!=NULL) sm+=root->right->data;
        
        root->data=sm;
        
        solve(root->left);
        solve(root->right);
    }
    void solve1(Node* root)
    {
        if(root==NULL) return;
        
        solve1(root->left);
        solve1(root->right);
       
        int sm=0;
        if(root->left!=NULL) sm+=root->left->data;
        if(root->right!=NULL) sm+=root->right->data;
        
        root->data+=sm;
        
        
        
    }
    void toSumTree(Node *node)
    {
        solve(node);
        solve1(node);
    }
