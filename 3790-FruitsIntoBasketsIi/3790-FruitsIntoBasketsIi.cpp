// Last updated: 8/13/2025, 3:33:27 PM
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>a(fruits.size(),true);
        int count=0;
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j] && a[j]==true){
                    count++;
                    a[j]=false;
                    break;
                }
            }
        } 
        return fruits.size()-count;       
    }
};