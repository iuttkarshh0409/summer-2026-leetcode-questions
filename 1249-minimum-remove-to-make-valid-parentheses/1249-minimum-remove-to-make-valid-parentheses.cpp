class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
                result += c;
            } 
            else if (c == ')') {
                if (balance > 0) {
                    balance--;
                    result += c;
                }
            } 
            else {
                result += c;
            }
        }

        string ans;
        balance = 0;

        for (int i = result.size() - 1; i >= 0; i--) {
            if (result[i] == ')') {
                balance++;
                ans += result[i];
            } 
            else if (result[i] == '(') {
                if (balance > 0) {
                    balance--;
                    ans += result[i];
                }
            } 
            else {
                ans += result[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna