// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long > s;
        s.push(0);
        long long  ans=INT_MIN;
        for(long long int i=1;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {   long long int length=arr[s.top()];
                long long int en=i;
                s.pop();
                long long int st=(s.empty()?-1:s.top());
                ans=max(ans,length*(en-st-1));
            }
            s.push(i);
        }long long int wd;
        while(!s.empty())
        {
            long long int ln=arr[s.top()];
            s.pop();
             if(s.empty()==false)
               wd=n-1-s.top();
               
               else wd=n;
               
               ans=max(ans,wd*ln);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
