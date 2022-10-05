int check(vector<int> parent,int st)
    {
        if(parent[st]==st) return st;
        return check(parent,parent[st]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<int> parent(n+1);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
        {
            int st=edges[i][0];
            int en=edges[i][1];
            
            int p1=check(parent,st);
            int p2=check(parent,en);
            
            if(p1==p2) return edges[i];
            else parent[p1]=p2;
        }
        return {-1,-1};
    }
