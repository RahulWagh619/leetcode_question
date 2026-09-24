class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        int last=speed[n-1];
        int count=n;
        for(int i=n-2;i>=0;i--){
            if(speed[i]>last||position[i+1]-position[i]<=distance){
                count--;
            }
            else{
                last=speed[i];
            }
        }
        return count;
    }
};