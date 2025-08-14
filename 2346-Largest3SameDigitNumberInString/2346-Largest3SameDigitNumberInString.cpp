// Last updated: 8/14/2025, 2:36:09 PM
class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        for (int i = 0; i <= num.size() - 3; ++i) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triplet(3, num[i]); 
                if (result.empty() || triplet > result) {
                    result = triplet;
                }
            }
        }
        return result;
    }
};
