// Last updated: 8/13/2025, 3:36:28 PM
class Solution {
public:
    void helper(string s, string ans, vector<string>& fans, set<string>& st) {
        if (s.empty()) {
            fans.push_back(ans.substr(0, ans.size() - 1)); // remove trailing space
            return;
        }
        for (int i = 1; i <= s.size(); i++) { // loop from 1 to s.size()
            string prefix = s.substr(0, i);
            if (st.count(prefix)) {
                helper(s.substr(i), ans + prefix + " ", fans, st);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<string> fans;
        helper(s, "", fans, st);
        return fans;
    }
};
