class Solution {
public:
vector<char>vowel{'A','E','I','O','U','a','e','i','o','u'};
bool check(char c){
       bool ans=false;
       for(int i=0;i<vowel.size();i++){
           if(c==vowel[i]){
            ans=true;
            break;
           }
       }
   return ans;
}
    string sortVowels(string s) {
        string z="";
        vector<char>a(s.length(),'1');
        vector<pair<int,char>>vp;
        for(int i=0;i<s.length();i++){
                if(!check(s[i])){
                    a[i]=s[i];
                    continue;
                }
                int val=static_cast<int>(s[i]);
                vp.push_back({val,s[i]});
        }
        sort(vp.begin(),vp.end());
        int start=0;
        for(int i=0;i<s.length();i++){
                if(a[i]!='1'){
                    z+=a[i];
                    continue;
                }
                z+=vp[start].second;
                start++;
        }
        return z;
    }
};