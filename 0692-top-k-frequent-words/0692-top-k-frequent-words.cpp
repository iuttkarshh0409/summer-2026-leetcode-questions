class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> freq;

        for (string &w : words)
            freq[w]++;

        vector<vector<string>> bucket(words.size() + 1);

        for (auto &p : freq)
            bucket[p.second].push_back(p.first);

        for (auto &v : bucket)
            sort(v.begin(), v.end());

        vector<string> ans;

        for (int f = words.size(); f >= 1; f--) {

            for (string &w : bucket[f]) {

                ans.push_back(w);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};