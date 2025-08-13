// Last updated: 8/13/2025, 3:37:51 PM
class Solution {
public:
    int strStr(string a, string b) {
        int size1=a.length();
        int size2=b.length();
        if(size2<=size1){
            int pos=a.find(b);
            if(pos!=string::npos){
                return pos;
            }
        }
        
        return -1;
    }
};