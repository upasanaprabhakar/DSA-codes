class Solution {
public:
    void helper(string& digits, string& curr, vector<string>& ans, vector<string>& mapping, int idx = 0){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        
        string letters = mapping[digits[idx] - '0'];

        for(char ch : letters){
            curr.push_back(ch);
            helper(digits, curr, ans, mapping, idx+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> mapping = {
           "" , "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans;
        string curr;
        helper(digits, curr, ans, mapping, 0);
        return ans;
    }
};