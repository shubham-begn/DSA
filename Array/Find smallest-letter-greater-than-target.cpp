char nextGreatestLetter(vector<char>& letters, char target) {
       int low=0,high=letters.size();
        char ans=letters[0];
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(letters[mid]<=target)
            {
                low=mid+1;
            }
            else 
            {
                if(letters[mid]>target && (mid==0 || letters[mid-1]<=target))
                {
                    ans=letters[mid];
                    break;
                }
                else high=mid-1;
            }
        }
        
        return ans;
        
    }
