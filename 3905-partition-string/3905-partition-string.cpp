class Solution {
public:
    vector<string> partitionString(string s) {
        map<string,int>mpp;
        string z="";
        vector<string>ans;
        for(int i=0;i<s.length();i++){
              z+=s[i];
              if(mpp[z]==0){
                mpp[z]++;
                ans.push_back(z);
                z="";
              }
        }
        return ans;
    }
};