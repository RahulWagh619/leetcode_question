// Last updated: 8/13/2025, 3:33:56 PM
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mpp;
        int count=0;
        string store;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            cout<<mpp[arr[i]]<<endl;
            if(mpp[arr[i]]==1){
                count++;
            }
            if(count==k){
                return arr[i];
            }
        }
       return "";
        
    }
};