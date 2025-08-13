// Last updated: 8/13/2025, 3:34:56 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int sum=0;
        unordered_map<int,int>mpp;
        for(auto &i:answers){
            mpp[i]++;
        }
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0){
                sum++;
            }
        }
        // cout<<sum<<endl;
        for(auto &i:mpp){
            if(i.first!=0){
              double val=(double)i.second/(i.first+1);
              val=ceil(val);
              val=(i.first+1)*val;
              sum+=val;
            }
        }
        return sum;
    }
};