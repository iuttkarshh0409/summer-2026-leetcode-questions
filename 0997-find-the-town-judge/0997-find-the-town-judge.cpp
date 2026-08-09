class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> degree(n + 1, 0);

        for (auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];

            degree[a]--;
            degree[b]++;
        }

        for (int person = 1; person <= n; person++) {
            if (degree[person] == n - 1) {
                return person;
            }
        }

        return -1;
    }
};