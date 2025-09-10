class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<vector<int>> z;
        
        for (int i = 0; i < friendships.size(); i++) {
            int one = friendships[i][0];
            int two = friendships[i][1];
            bool ans = false;
            for (int lang1 : languages[one - 1]) {
                for (int lang2 : languages[two - 1]) {
                    if (lang1 == lang2) {
                        ans = true;
                        break;
                    }
                }
                if (ans) {
                    break;
                }
            }
            if (ans) continue;

            vector<int> v;
            v.push_back(one);
            v.push_back(two);
            z.push_back(v);
        }
        
        set<int> st;
        for (int i = 0; i < z.size(); i++) {
            st.insert(z[i][0]);
            st.insert(z[i][1]);
        }
        if (st.empty()) {
            return 0;
        }
        map<int, int> mpp;
        for (int user_id : st) {
            for (int lang : languages[user_id - 1]) {
                mpp[lang]++;
            }
        }

        int maxi = 0; 
        for (auto const& [lang, freq] : mpp) {
            if (freq > maxi) {
                maxi = freq;
            }
        }
        return st.size() - maxi;
    }
};