 int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   if(cnt<k)
               {
                pq.push(matrix[i][j]);
                cnt++;
               }
             else
             {
                 if(matrix[i][j]<pq.top())
                 {
                     pq.pop();
                     pq.push(matrix[i][j]);
                 }
             }
            } 
        }
        return pq.top();
    }
