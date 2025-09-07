class Solution {
public:
    int minOperations(string s) {
        vector<int>ans(26);
        for(int i=0;i<s.length();i++){
            int ch=s[i]-'a';
            ans[ch]++;
        }
        if(ans[0]==s.length()){
            return 0;
        }
        // cout<<ans[1]<<endl;
        int val=-1;
        for(int i=1;i<26;i++){
           if(ans[i]>0){
             val=(26-i);
             break;
           }
        }
        return val;
    }
};