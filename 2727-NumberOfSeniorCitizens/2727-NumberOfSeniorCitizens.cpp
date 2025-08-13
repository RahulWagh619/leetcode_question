// Last updated: 8/13/2025, 3:33:39 PM
class Solution {
public:
    int countSeniors(vector<string>& a) {
        unordered_map<string,int>mpp;
        string ans;
        int count=0;
        for(int i=0;i<a.size();i++){
           int ans=stoi(a[i].substr(11,2));
           cout<<ans<<endl;
          if(ans>60){
            count++;
          }
        }
        return count;
    }
};