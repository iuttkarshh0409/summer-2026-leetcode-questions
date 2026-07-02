class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        vector<vector<char>> bucket(s.size()+1);

        for(auto &p : freq)
            bucket[p.second].push_back(p.first);

        string ans;

        for(int f = s.size(); f >= 1; f--){

            for(char c : bucket[f]){

                ans.append(f, c);   // append character c, f times
            }
        }

        return ans;
    }
};