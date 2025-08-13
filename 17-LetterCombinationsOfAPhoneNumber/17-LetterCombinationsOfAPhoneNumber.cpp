// Last updated: 8/13/2025, 3:38:06 PM
class Solution {
public:
void pickornot(string&digits,int i,string&change,vector<string>&ans,vector<string>&keys){
    if(i==digits.size()){
        ans.push_back(change);
        return;
    }
    int val=digits[i]-'0';
    for(int j=0;j<keys[val].size();j++){
        change.push_back(keys[val][j]);
        pickornot(digits,i+1,change,ans,keys);
        change.pop_back();
    }
   
}
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        vector<string>keys{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       string change;
       pickornot(digits,0,change,ans,keys);
        return ans;
    }
};