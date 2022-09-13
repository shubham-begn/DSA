   int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if((mid==0 || nums[mid]!=nums[mid-1]) && (mid==nums.size()-1 ||nums[mid]!=nums[mid+1]))
            {
                ans=nums[mid];
                break;
            }
            else if(mid%2!=0 )
            {
                if(nums[mid]==nums[mid-1]) low=mid+1;
                else high=mid-1;
            }
            else
            {
                if(nums[mid]==nums[mid+1]) low=mid+1;
                else high=mid-1;
            }
        }
        return ans;
    }
