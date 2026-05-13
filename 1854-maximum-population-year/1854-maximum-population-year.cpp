class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        int maxi=-1;
        int year=-1;
        vector<vector<int>>sl;
        for(int i=0;i<n;i++){
            int birth=logs[i][0];
            int dead=logs[i][1];
            sl.push_back({birth,1});
            sl.push_back({dead,-1});
        }
        sort(sl.begin(),sl.end());
        int count=0;
        for(int i=0;i<sl.size();i++){
            count+=sl[i][1];
            if(count>maxi){
                year=sl[i][0];
                maxi=count;
            }
        }
        return year;
    }
};