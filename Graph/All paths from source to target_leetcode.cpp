  void dfs(int src,vector<vector<int>> graph,vector<vector<int>> &ans,vector<int> temp,int n)
    {
        //vis[src]=true;
        temp.push_back(src);
        if(src==n)
        {   //cout<<"hi";
          //  vis[src]=false;
            ans.push_back(temp);
            return;
        }
        
         for(auto x:graph[src])
        {
          
                dfs(x,graph,ans,temp,n);
           
        }
       // vis[src]=false;
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        int n=graph.size();
      //  cout<<n<<"\n";
       // vector<bool> vis(n,false);
        vector<int> temp;
       
            dfs(0,graph,ans,temp,n-1);
        
        
        return ans;
    }
