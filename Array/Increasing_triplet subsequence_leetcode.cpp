//Just maintain minimum and second minimum number before the current index 
//initialize both minimum nos. with INT_MAX

 bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        
        int first_mn=INT_MAX;
        int second_mn=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
           if(second_mn>first_mn && nums[i]>second_mn)
               return true;
            
           else if(nums[i]<first_mn)
               first_mn=nums[i];
            else if(nums[i]>first_mn && nums[i]<second_mn)
                second_mn=nums[i];
        
            
        }
        return false;
        
    }
