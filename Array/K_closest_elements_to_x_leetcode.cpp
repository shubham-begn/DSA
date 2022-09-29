vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(x-arr[i]),arr[i]});
        }
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            pair<int,int> temp=pq.top();
            pq.pop();
            
            ans.push_back(temp.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
