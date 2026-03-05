class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int n=s.length();
        int count=1;
        string v="";
        string b="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                v+='1';
                b+='0';
            }
            else{
                v+='0';
                b+='1';
            }
        }
        int diff1=0;
        int diff2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=v[i]){
                diff1++;
            }
            else{
                diff2++;
            }
        }
        int val=min(diff2,diff1);
        return val;
    }
};