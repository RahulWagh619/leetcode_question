// Last updated: 8/17/2025, 1:20:07 AM
class Solution {
public:
    int maximum69Number (int num) {
        int index=-1;
        string s=to_string(num);
        for(int i=0;i<s.length();i++){
            if(s[i]=='6'){
                index=i;
                break;
            }
        }
        if(index==-1){
            return num;
        }
        s[index]='9';
        int k=stoi(s);
        return k;
    }
};