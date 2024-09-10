//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int bs( int low, int high, int*ans, int n, int m ){
      if(low > high)return -1;
     int  mid = (low + high)/2;
     long long int pro = 1;
      int count = 0;
      while(count < n){
          pro = pro * mid;
          if(pro > m){
              break;
          }
          count++;
      }
      if(pro > m){
         return bs(low, mid - 1, ans,n, m);
      }else if(pro == m)return mid;
      else if(pro < m){
        
          return bs(mid + 1, high, ans, n, m);
          
      }
      return -1;
      
  }
	int NthRoot(int n, int m)
	{
	    // Code here.
	      int low = 0, high = m ;
        int ans1 = -1;
       int* ans = &ans1;
        return bs(low, high, ans, n, m);
        
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends