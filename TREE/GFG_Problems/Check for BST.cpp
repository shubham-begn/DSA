 int prev=INT_MIN;
    bool isBST(Node* root) 
    {
      if(root==NULL) return true;
      if(!isBST(root->left)) return false;
      if(root->data<=prev) return false;
      
      prev=root->data;
      
      return isBST(root->right);
      
    }
