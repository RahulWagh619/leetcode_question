class Solution {
public:
bool helper(vector<int>&weights,int days,int mid){
    int sum=0;
    int i=0;
    for(int j=0;j<days;j++){
         while(i<weights.size() && sum<mid){
            if(sum+weights[i]<=mid){

            sum+=weights[i];
            i++;
            } 
            else{
                break;
            } 
         }
         sum=0;
    }
    if(i>=weights.size())return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int result = -1;
        int left=1;
        int right=0;
        for(int i=0;i<weights.size();i++){
            right+=weights[i];
        }
        while (left <= right) {
        int mid = left + (right - left) / 2;
        if (helper(weights,days,mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1; 
        }
      }
        return result;
    }
};