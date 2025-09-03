class Solution {
public:
    int solve(vector<int>& height, vector<int>& dp, int i, int n) {
        if(i == n - 1) return 0; 
        if(dp[i] != -1) return dp[i];

        int lcost = abs(height[i] - height[i + 1]) + solve(height, dp, i + 1, n);

        int rcost = INT_MAX;
        if(i + 2 < n) {
            rcost = abs(height[i] - height[i + 2]) + solve(height, dp, i + 2, n);
        }

        return dp[i] = min(lcost, rcost);
    }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(height, dp, 0, n);
    }
};
