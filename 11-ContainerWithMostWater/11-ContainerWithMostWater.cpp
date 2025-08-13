// Last updated: 8/13/2025, 3:38:11 PM
class Solution {
public:
    int maxArea(vector<int>&unit) {
      int maxi=0;
      int i=0;
      int j=unit.size()-1;
      while(i<j){
        maxi=max(min(unit[i],unit[j])*(j-i),maxi);
        if(unit[i]<unit[j]){
            i++;
        }
        else{
            j--;
        }
      }
      return maxi;
        
    }
};