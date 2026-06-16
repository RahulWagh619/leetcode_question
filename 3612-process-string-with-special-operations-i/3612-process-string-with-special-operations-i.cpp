class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        set<char>c;
        c.insert('*');
        c.insert('#');
        c.insert('%');
        string v;
        for(int i=0;i<n;i++){
            if(c.find(s[i])==c.end()){
                v.push_back(s[i]);
            }
            else{
                if(s[i]=='*'){
                    if(v.length()>0){
                        v.pop_back();
                    }
                }
                else if(s[i]=='#'){
                    v+=v;
                }
                else{
                    reverse(v.begin(),v.end());
                }
            }
        }
        return v;
    }
};