class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]=i;
        }
        vector<int>ans;
        int start=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++){
              maxi=max(maxi,mpp[s[i]]);
              if(i==maxi){
                 ans.push_back(maxi-start+1);
                 start=i+1;
              }
        }
        return ans;

    }
};