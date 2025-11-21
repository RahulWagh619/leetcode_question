class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,int>mpp;
        int count=0;
        int n=s.length();
        for(int i=0;i<n-2;i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]++;
                int start=i;
                int end=n-1;
                while(start<end){
                    if(s[start]==s[end]){
                        break;
                    }
                    else{
                        end--;
                    }
                }
                if(start>=end){
                    continue;
                }
                set<char>st;
                for(int z=start+1;z<end;z++){
                    st.insert(s[z]);
                }
                count+=st.size();
            }
        }
        return count;
    }
};