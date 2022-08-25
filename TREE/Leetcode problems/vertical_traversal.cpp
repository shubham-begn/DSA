difference than gfg-> in same level we need to store in sorted order 



vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,vector<int>>> mp;
        
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
           pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            
            TreeNode* fr=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            
            mp[hd][lvl].push_back(fr->val);
            if(fr->left!=NULL) q.push(make_pair(fr->left,make_pair(hd-1,lvl+1)));
            if(fr->right!=NULL) q.push(make_pair(fr->right,make_pair(hd+1,lvl+1)));
            
        }
        
        
        for(auto i : mp){
            vector<int> topush;
            for(auto j : i.second){
                sort(j.second.begin(),j.second.end());
               for(auto k: j.second){
                   topush.push_back(k);
               }
            }
            ans.push_back(topush);
        }
        
        return ans;
    }
