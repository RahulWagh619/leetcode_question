class Solution {
public:
    bool doesAliceWin(string s) {
        string z="aeiou";
        // bool ans=false;
        for(int i=0;i<s.length();i++){
            if(z.find(s[i])!=string::npos){
                return true;
            }
        }
        return false;
    }
};