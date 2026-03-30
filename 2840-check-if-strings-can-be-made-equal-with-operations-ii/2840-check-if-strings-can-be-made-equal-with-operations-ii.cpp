class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                mpp1[s1[i]]++;
            }
            else{
                mpp2[s1[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(mpp1.find(s2[i])==mpp1.end()){
                    return false;
                }
                mpp1[s2[i]]--;
                if(mpp1[s2[i]]==0){
                    mpp1.erase(s2[i]);
                }
            }
            else{
                 if(mpp2.find(s2[i])==mpp2.end()){
                    return false;
                }
                mpp2[s2[i]]--;
                if(mpp2[s2[i]]==0){
                    mpp2.erase(s2[i]);
                }
            }
        }
        return true;

    }
};