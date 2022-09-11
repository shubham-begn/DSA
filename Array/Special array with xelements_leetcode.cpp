int specialArray(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        unordered_set<int> s(nums.begin(),nums.end());
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<=n;i++)
        {
           
                 vector<int>::iterator lower;
                 lower = lower_bound(nums.begin(), nums.end(), i);
                
                int pos=lower-nums.begin();
                //cout<<i<<n-pos<<"\n";
                if(i==n-pos)
                {
                    ans=i;
                    break;
                }
             
        }
        return ans;
        
    }
