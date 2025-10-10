class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        string s(n , '0');
        vector<string>res;
        solve(s, 0 , res);
        return res;
    }
    void solve(string &s, int i , vector<string> &res){
        int n = s.length();
         if(i == n){
             res.push_back(s);
             return;
         }
         s[i] = '0';
         solve(s, i + 1, res);
         s[i] = '1';
         solve(s, i + 1, res);
    }
};