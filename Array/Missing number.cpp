OPTIMISED--

int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int sum1=0;
        for(int i=0;i<n;i++)
            sum1+=nums[i];
        
        return sum-sum1;
    }
};


BETTER SOLUTION 

int missingNumber(vector<int>& nums) {
      int n=nums.size();
        bool z=false;
        int ans=n;
        if(n==1)
        {
            if(nums[0]==0) return 1;
            else return 0;
        }
        int alter;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                alter=nums[i];
                break;
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) 
            {   z=true;
                nums[i]=alter;
                break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            
                nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
            
        }
        if(z==false) return 0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) 
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
