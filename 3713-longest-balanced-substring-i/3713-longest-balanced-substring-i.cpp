class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            map<char,int>mpp;
            string k;
            for(int j=i;j<s.length();j++){
                  k+=s[j];
                  mpp[s[j]]++;
                  int z=mpp[s[j]];
                  bool found=true;
                  for(auto &i:mpp){
                      if(i.second!=z){
                        found=false;
                        break;
                      }
                  }
                  if(found){
                    ans=max(ans,j-i+1);
                  }
            }
        }
        return ans;
    }
};