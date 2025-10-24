class Solution {
public:
    bool isBalance(int x) {
        string s=to_string(x);
        vector<int> count(10);
        while (x > 0) {
            count[x % 10]++;
            x /= 10;
        }
        int sum=0;
        for (int d = 0; d < 10; ++d) {
            if (count[d] > 0 && count[d] != d) {
                return false;
            }
            sum+=count[d];
        }
        if(sum==s.length()){
            return true;

        }
        return false;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; ++i) {
            if (isBalance(i)) {
                return i;
            }
        }
        return -1;
    }
};