class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        int n=chunks.size();
        for(int i=0;i<n;i++){
            string v=chunks[i];
            s+=v;
        }
        string m="";
        map<string,int>mpp;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(m.length()>0){
                    mpp[m]++;
                    // cout<<m<<endl;
                }
                    m="";
            }
            else if(s[i]=='-'){
                if(i>0 && i<s.length()-1 && (s[i-1]!='-' && s[i-1]!=' ') && (s[i+1]!='-'&& s[i+1]!=' ')){
                    m+='-';
                    // cout<<m<<endl;
                    continue;
                }
                // else{
                if(m.length()>0){
                    mpp[m]++;
                    // cout<<m<<endl;
                }
                    m="";  
            }
            else{
                m+=s[i];
            }
        }
        if(m.length()>0){
             mpp[m]++;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(mpp.find(queries[i])==mpp.end()){
                ans.push_back(0);
            }
            else{
                int val=mpp[queries[i]];
                ans.push_back(val);
            }
        }
        return ans;
    }
};