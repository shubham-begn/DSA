  int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int ans=INT_MAX;
        while(j<nums.size())
        {
           sum+=nums[j++];
           
            while(sum>=target)
            {
                ans=min(ans,j-i);
                sum-=nums[i++];
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
