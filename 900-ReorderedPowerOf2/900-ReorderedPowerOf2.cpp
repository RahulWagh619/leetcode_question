// Last updated: 8/13/2025, 3:34:49 PM
class Solution {
public:
bool ispowerof2(string s){
    long long n=stoll(s);
    if((n & (n-1))==0 ){
        return true;
    }
    return false;
}
bool helper(string &s,int i){
    if(i>=s.length()){
          if(s[0]=='0'){
              return false;
          }
          else{
             if(ispowerof2(s)){
                return true;
             }
             else{
                return false;
             }
          }
    }

    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        if (helper(s, i + 1)) return true;
        swap(s[i],s[j]);
    }
    return false;
}
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        return helper(s,0);
    }
};