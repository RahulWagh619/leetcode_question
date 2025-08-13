// Last updated: 8/13/2025, 3:36:36 PM
class Solution {
public:
bool ispalindrome(string a,int i,int j){
    while(i<=j){
        if(a[i]!=a[j]){
            return false;
        }
            i++;
            j--;
    }
    return true;
}
void printpalindrome(string a,int i,vector<vector<string>>&ans,vector<string>&b){
    if(i>=a.length()){
        ans.push_back(b);
        return;
    }
    for(int j=i;j<a.length();j++){
        if(ispalindrome(a,i,j)){
          b.push_back(a.substr(i,j-i+1));
          printpalindrome(a,j+1,ans,b);
          b.pop_back();
        }
    }
}
    vector<vector<string>>partition(string a) {
        int i=0;
        vector<vector<string>>ans;
        vector<string>b;
        printpalindrome(a,i,ans,b);

    return ans;
    }
};