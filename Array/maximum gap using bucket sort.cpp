  int maximumGap(vector<int>& nums) {
        
        int n=nums.size();
        if(n<2) return 0;
        
        int mini=INT_MAX,maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
            
        }
        if(maxi==mini) return 0;
        
        int interval=(int)ceil((double)(maxi-mini)/(n-1));
        
       vector<int> min_bucket(n,INT_MAX);
        vector<int> max_bucket(n,-1);
        
        for(int i=0;i<n;i++)
        {
            int index=(nums[i]-mini)/interval;
            min_bucket[index]=min(min_bucket[index],nums[i]);
            max_bucket[index]=max(max_bucket[index],nums[i]);
        }
        int prev=mini,ans=0;
        for(int i=0;i<min_bucket.size();i++)
        {
            if(max_bucket[i]==-1) continue;
            
            ans=max(min_bucket[i]-prev,ans);
            prev=max_bucket[i];
        }
        ans=max(ans,maxi-prev);
        return ans;
    }
