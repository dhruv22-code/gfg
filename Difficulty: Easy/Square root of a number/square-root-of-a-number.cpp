//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
  void bs(long long low, long long high, long long*ans, long long n){
      if(low > high)return;
      long long mid = (low + high)/2;
      if(mid * mid <= n){
          *ans = max(*ans, mid);
          bs(mid + 1, high, ans, n);
          
      }else if(mid * mid > n){
          bs(low, mid - 1, ans,n);
      }
      
  }
    long long int floorSqrt(long long int n) {
        // Your code goes here
       long long int low = 0, high = n ;
       long long int ans1 = 0;
       long long int* ans = &ans1;
        bs(low, high, ans, n);
        return *ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends