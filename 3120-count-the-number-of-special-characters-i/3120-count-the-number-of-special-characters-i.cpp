class Solution {
public:
    int numberOfSpecialChars(string s) {
        int count=0;
        vector<int>a(26,0);
        vector<int>b(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                int idx=s[i]-'A';
                b[idx]=1;
            }
            else{
                int idx=s[i]-'a';
                a[idx]=1;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]==1 && b[i]==1)count++;
        }
        return count;
    }
};