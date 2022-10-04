This question seems to be difficult but in this we jst only need to print those nodes which have indegree=0 that's all
  
   vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][1]]++;
        }
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)==mp.end())
                ans.push_back(i);
        }
        return ans;
    }
