class Solution {
public:
    void helper(int open, int close, int n ,string& curr, vector<string>& ans){
        if(curr.size() == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            helper(open+1, close, n, curr, ans);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            helper(open, close+1, n, curr, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        helper(0,0,n,curr,ans);
        return ans;
    }
};