void abc(TreeNode *root,vector<int>&ans)
{
    if(root==NULL) return ;
    if(root->left==NULL &&root->right==NULL) ans.push_back(root->val);
    abc(root->left,ans);
    abc(root->right,ans);

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      bool temp=true; 
    vector<int> ans1;
    vector<int> ans2;
        abc(root1,ans1);
        abc(root2,ans2);
        if(ans1==ans2) temp=true;
        else temp=false;
       
        return temp;
    }
