void abc(TreeNode* root,vector<double>&ans)
{
  
  double sum=0;
 queue<TreeNode *> q1;
    q1.push(root);
    while(q1.empty()==false)
    {int cnt=q1.size();
     sum=0;
     for(int i=0;i<cnt;i++)
     {   TreeNode * curr=q1.front();
         sum+=curr->val;
          q1.pop();
      if(curr->left!=NULL) q1.push(curr->left);
      if(curr->right!=NULL) q1.push(curr->right);
     }
     ans.push_back(sum/cnt);
        
    }
}
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        abc(root,ans);
        return ans;
    }
