   int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        mp[nums[0]]++;
        for(int i=1;i<nums.size();i++)
        {
           if( mp.find(nums[i])!=mp.end())
            {
                ans+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
