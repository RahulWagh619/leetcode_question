class Solution {
public:
bool check(string s,string k){
    bool z=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            z=false;
            break;
        }
    }
    if(!z)return false;
     for(int i=0;i<k.length();i++){
        if(k[i]=='0'){
            z=false;
            break;
        }
    }
    return z;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;
        for(int i=1;i<=(n/2)+1;i++){
            int val1=i;
            int val2=n-i;
            string s=to_string(val1);
            string k=to_string(val2);
            if(check(s,k)){
                ans.push_back(val1);
                ans.push_back(val2);
                break;
            }
        }
        return ans;
    }
};