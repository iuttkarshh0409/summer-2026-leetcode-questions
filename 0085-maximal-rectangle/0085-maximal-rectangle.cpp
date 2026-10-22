class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            stack<int> st;

            for (int j = 0; j <= n; j++) {
                int currHeight = (j == n) ? 0 : heights[j];

                while (!st.empty() && heights[st.top()] > currHeight) {
                    int h = heights[st.top()];
                    st.pop();

                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, h * width);
                }

                st.push(j);
            }
        }

        return maxArea;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna