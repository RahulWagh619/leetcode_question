class Solution {
public:
    int maxDistinct(string s) {
        set<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        return st.size();
    }
};