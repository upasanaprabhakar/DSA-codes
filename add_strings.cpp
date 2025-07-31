class Solution {
public:
    string addStrings(string num1, string num2) {

        string  ans = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry =0;

        while(i >=0 || j>=0 || carry){
            int n1 = 0 , n2 = 0;
        
        if(i >=0){
             n1 = num1[i] - '0'; //convert into string to integer 
            i--;
        }

        if(j >= 0){
             n2 = num2[j]-'0';//convert into string to integer
            j--;
        }

        int sum = n1 +n2 + carry ;
        carry = sum /10;
        ans +=(sum % 10) + '0';
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};