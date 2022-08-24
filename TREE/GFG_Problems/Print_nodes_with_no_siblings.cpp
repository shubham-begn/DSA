void solve(Node*root,vector<int>&ans)
{
    if(root==NULL) return;
    if(root->left==NULL && root->right!=NULL)
     ans.push_back(root->right->data);
     
     if(root->left!=NULL && root->right==NULL)
     ans.push_back(root->left->data);
     
     solve(root->left,ans);
     solve(root->right,ans);
}
vector<int> noSibling(Node* root)
{
     vector<int> ans;
     if(root==NULL) return ans;
   //  if(root->left==NULL && root->right!=NULL)||(root->left!=NULL && root->right==NULL)
    // temp=1;
     
     solve(root,ans);
     if(ans.empty()) ans.push_back(-1);
     
     sort(ans.begin(),ans.end());
     return ans;
     
}
