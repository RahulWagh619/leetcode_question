class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int count = 0;
        set<int> st;
        for (int i = 0; i < reservedSeats.size();) {
            int digit = reservedSeats[i][0];
            st.insert(digit);
            vector<int> v;
            while (i < reservedSeats.size() && reservedSeats[i][0] == digit) {
                v.push_back(reservedSeats[i][1]);
                i++;
            }
            auto it = lower_bound(v.begin(), v.end(), 2);
            if (it == v.end()) {
                count += 2;
                continue;
            }
            if (*it > 5) {
                count++;
                auto it = lower_bound(v.begin(), v.end(), 6);
                if (it == v.end() || *it > 9)
                    count += 1;
                continue;
            }
            it = lower_bound(v.begin(), v.end(), 4);
            if (it == v.end() || *it > 7) {
                count++;
                continue;
            }
            it = lower_bound(v.begin(), v.end(), 6);
            if (it == v.end() || *it > 9) {
                count++;
            }
        }
        count += (n - st.size()) * 2;
        return count;
    }
};