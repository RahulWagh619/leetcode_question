class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idx=0;
        int count=0; 
        if(s.size()==0){
            return 0;
        }
        // for(int i=0;i<g.size();i++){
            int i=0;
        while(i<g.size()){
              if(s[idx]>=g[i]){
                count++;
                idx++;
                i++;
              }
              else{
                idx++;
              }
              if(idx==s.size()){
                break;
              }
        }
        // }
        return count;
    }
};