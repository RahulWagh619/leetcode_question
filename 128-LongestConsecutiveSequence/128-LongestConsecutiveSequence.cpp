// Last updated: 8/13/2025, 3:36:38 PM
class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if(a.size()==0){
            return 0;
        }
        else if(a.size()==1){
            return 1;
        }
        sort(a.begin(),a.end());
        int count=1;
        int longest=0;
        int maxi=a[0];
        for(int i=0;i<a.size();i++){
            if(maxi==a[i]-1){
                count++;
                maxi=a[i];
            }
            else if(maxi!=a[i]){
                count=1;
                maxi=a[i];
            }
             longest=max(count,longest);
        }
        return longest;
    }
};