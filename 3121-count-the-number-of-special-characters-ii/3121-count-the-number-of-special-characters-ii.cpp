class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>a(26,-1);
        vector<int>b(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                int idx=s[i]-'A';
                if(b[idx]==-1){
                    b[idx]=i;
                }
            }
            else{
                int idx=s[i]-'a';
                a[idx]=i;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(a[i]==-1||b[i]==-1)continue;
            if(a[i]<b[i]){
                count++;
            }
        }
        return count;
    }
};