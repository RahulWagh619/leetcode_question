class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1)return s;
        if(n<=numRows)return s;
        vector<vector<char>>v(numRows);
        int i=0;
        int idx=0;
        while(true){
            bool up=false;
            while(i<n && idx!=numRows && !up){
                v[idx].push_back(s[i]);
                idx++;
                i++;
            }
            idx-=2;
            up=true;
            while(i<n && idx!=-1 && up){
                v[idx].push_back(s[i]);
                idx--;
                i++;
            }
            idx+=2;
            if(i>=n){
                break;
            }
        }
        string m;
        for(int i=0;i<numRows;i++){
            // string k;
            for(int j=0;j<v[i].size();j++){
                m+=v[i][j];
                // k+=v[i][j];
            }
            // cout<<k<<endl;
        }
        return m;

    }
};