//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        int bit = 0, num = 1;
        while(bit < k){
            num  = num << 1;
            bit++;
        }
        return n | num;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        Solution ob;
        int ans = ob.setKthBit(N, K);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends