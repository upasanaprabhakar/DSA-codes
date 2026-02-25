class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void helper(string& s, vector<string>& curr, vector<vector<string>>& ans, int idx = 0){
        if(idx == s.size()){
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                helper(s, curr, ans, i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, curr, ans, 0);
        return ans;
    }
};