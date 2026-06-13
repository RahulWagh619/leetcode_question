class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        string ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            int len=words[i].length();
            int sum=0;
            for(int j=0;j<len;j++){
                int idx=words[i][j]-'a';
                sum+=weights[idx];
            }
            sum=(sum%26);
            char ch=alpha[25-sum];
            ans+=ch;
        }
        return ans;
    }
};