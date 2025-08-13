// Last updated: 8/13/2025, 3:35:31 PM
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        queue<int>q;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};