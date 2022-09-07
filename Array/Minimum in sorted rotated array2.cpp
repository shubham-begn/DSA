int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            else if(nums[high]<nums[mid])
                low=mid+1;
            else high=mid;
        }
        return nums[high];
    }
