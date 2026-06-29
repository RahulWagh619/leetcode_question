class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.length();
        int m=patterns.size();
        int count=0;
        for(int i=0;i<m;i++){
            int size=patterns[i].size();
            for(int j=0;j<=n-size;j++){
                 string v;
                 for(int k=j;k<j+size;k++){
                    v+=word[k];
                 }
                 if(v==patterns[i]){
                    count++;
                    break;
                 }
            }
        } 
        return count;
    }
};