// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int largesthistogram(int arr[],int n)
  {   int ans=0,width;
      stack<int> s;
      s.push(0);
      for(int i=1;i<n;i++)
      {
          while(s.empty()==false && arr[i]<arr[s.top()])
          {
              int length=arr[s.top()];
              s.pop();
              if(s.empty())
               width=i;
              else width=i-s.top()-1;
              
              ans=max(ans,length*width);
          }
          s.push(i);
      }
          while(!s.empty())
          {
              int length=arr[s.top()];
              s.pop();
              if(s.empty())
              width=n;
              else width=n-s.top()-1;
              
              ans=max(ans,length*width);
              
          
      }
      return ans;
  }
    int maxArea(int M[MAX][MAX], int n, int m) {
         int ans=INT_MIN,temp;
        
       // int arr[m]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   if(i==0)
                 temp=largesthistogram(M[i],m);
                
                else {
                   if( M[i][j]==1)
                    M[i][j]+=M[i-1][j];
                }
            }
             temp=largesthistogram(M[i],m);
            ans=max(ans,temp);
        }
       // cout<<ans<<" ";
        return ans;
        
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
