class Solution {
public:
vector<string>ans;
void check(string s,int size,int k){
    int sum=0;
    for(int i=0;i<size;i++){
        if(s[i]=='1'){
        sum+=i;
        }
        if(sum>k){
            return;
        }
    }
    ans.push_back(s);
}
void helper(string s,int n,int k){
    int size=s.length();
    if(n==size){
        check(s,size,k);
        return;
    }
    if(s.empty()||(!s.empty() && s.back()=='0')){
        // s+='1';
        helper(s+'1',n,k);
    }
    helper(s+'0',n,k);
    // s+='0';
}
    vector<string> generateValidStrings(int n, int k) {
        helper("",n,k);
        return ans;
    }
};