class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        sort(capacity.rbegin(),capacity.rend());
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        int index=-1;
        for(int i=0;i<capacity.size();i++){
            sum-=capacity[i];
            if(sum<=0){
                index=i+1;
                break;
            }
        }
        return index;
    }
};