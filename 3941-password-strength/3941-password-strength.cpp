class Solution {
public:
    int passwordStrength(string s) {
        int n=s.length();
        vector<int>a(26,1);
        vector<int>b(26,1);
        vector<int>c(26,1);
        set<char>st;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                   int idx=s[i]-'a';
                   if(a[idx]==1){
                    count++;
                    a[idx]=0;
                   }
            }
            else if(s[i]>='A' && s[i]<='Z'){
                int idx=s[i]-'A';
                   if(b[idx]==1){
                    count+=2;
                    b[idx]=0;
                   }
            }
            else if(s[i]>='0' && s[i]<='9'){
int idx=s[i]-'0';
                   if(c[idx]==1){
                    count+=3;
                    c[idx]=0;
                   }
            }
            else{
                  if(st.find(s[i])==st.end()){
                      st.insert(s[i]);
                      count+=5;
                  }
            }
        }
        return count;
    }
};