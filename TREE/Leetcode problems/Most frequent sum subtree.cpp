bool cmp(pair<int, int>& a,
         pair<int, int>& b)
{
    return a.second > b.second;
}



  
// Function to sort the map according
// to value in a (key-value) pairs
void sort1(unordered_map<int, int>& M,vector<int> &ans)
{
  
    // Declare vector of pairs
    vector<pair<int, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    int mx=A[0].second;
    for(auto x: A)
    {
        if(x.second==mx)
            ans.push_back(x.first);
        else break;
    }
}

    int solve(TreeNode*root, unordered_map<int,int> &mp)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) 
        {   mp[root->val]++;
            return root->val;
        }
        int lh=solve(root->left,mp);
        int rh=solve(root->right,mp);
        
        mp[root->val+lh+rh]++;
        
        return root->val+lh+rh;
    }
  
  
    vector<int> findFrequentTreeSum(TreeNode* root) {
      unordered_map<int,int> mp;
     // vector<pair<int,int>> p;
      int temp=solve(root,mp);
        vector<int> ans;
        sort1(mp,ans);
        return ans;
        
        
    }
