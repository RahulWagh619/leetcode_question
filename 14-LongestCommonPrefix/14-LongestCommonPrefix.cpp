// Last updated: 8/13/2025, 3:38:09 PM

class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        if(a.size()==1){
            return a[0];
        }
        int mini=INT_MAX;
      for (int i = 0; i < a.size(); i++)
       { int size=a[i].length();
    mini=min(mini,size);
      }
    string prefix="";
    bool ans;
    for(int j=0;j<mini;j++){
      char c=a[0][j];
        for (int i = 1; i < a.size(); i++)
        {
          if(a[i][j]!=c){
            ans=false;
            break;
          }
          else ans=true;
        }
        if(ans) prefix+=c;
        if(ans==false)return prefix;
    }
    return prefix;
    }
};