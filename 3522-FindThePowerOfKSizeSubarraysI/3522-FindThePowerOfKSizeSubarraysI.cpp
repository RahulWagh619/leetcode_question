// Last updated: 8/13/2025, 3:33:32 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        vector<int>result;
        for(int i=0;i<=a.size()-k;i++){
        bool ans=true;
            for(int j=i;j<k+i-1;j++){
                if(a[j]+1!=a[j+1]){
                    ans=false;
                    break;
                }
            }
            // cout<<endl;
            // cout<<ans<<endl;
                if(!ans){
                    result.push_back(-1);
                }
                else{
                    result.push_back(a[k+i-1]);
                }
        }
        
        return result;
    }
};