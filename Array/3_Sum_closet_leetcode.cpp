int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        int curr=0;
        for(int i=0;i<n-2;i++)
        {
         int j=i+1;
         int k=n-1;
            
        while(j<k)
        {
            curr=nums[i]+nums[j]+nums[k];
            if(abs(target-curr)<abs(target-res))
                res=curr;
            
            if(curr<target) j++;
            else k--;
        }
        }
        
        return res;
    }
