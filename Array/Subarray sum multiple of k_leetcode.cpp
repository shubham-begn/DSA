//Main thing is just store the modulus value
//Find prefix sum==0 using hashing technique(already solved)




bool checkSubarraySum(vector<int>& nums, int k) {
        
        int pre_sum=0;
        unordered_map<int,int> mp;
        mp.insert({0,-1});
        
        for(int i=0;i<nums.size();i++)
        {
            pre_sum+=nums[i];
            pre_sum%=k;
            
            if(mp.find(pre_sum)!=mp.end())
            {
                if(i-mp[pre_sum]>=2)
                    return true;
            }
            else mp[pre_sum]=i;
        }
        
        return false;
    }
};
