class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(),s.end());
        int val=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')continue;
            else{
                int z=s[i]-'a';
                val=26-z;
                break;
            }
        }
        if(val==-1)return 0;
        else return val;
    }
};