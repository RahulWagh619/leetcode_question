// Last updated: 8/13/2025, 3:34:44 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        map<int,int>mpp;
        int n=fruits.size();
        int count=0;
        int i=0;
        if(n==1)return 1;
        mpp[fruits[0]]++;
        for(int j=1;j<n;j++){
              if(mpp.size()<=2){
                  mpp[fruits[j]]++;
                //   if(mpp.size()<=2){
                // //   maxi=max(maxi,j-i+1);
                //   }
                //   else{
                     while(mpp.size()==3){
                      mpp[fruits[i]]--;
                      if(mpp[fruits[i]]==0){
                        mpp.erase(fruits[i]);
                      }
                       i++;
                     }
                //   }
              }
                      maxi=max(maxi,j-i+1); 
        }
        return maxi;
    }
};