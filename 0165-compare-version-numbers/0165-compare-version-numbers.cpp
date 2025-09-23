class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>a;
        vector<int>b;
        string s;
        for(int i=0;i<version1.length();i++){
            s+=version1[i];
            if(version1[i]=='.'){
                a.push_back(stoi(s));
                s.clear();
                continue;
            }
        }
        if(s.length()>0){
             a.push_back(stoi(s));
        }
        s.clear();
        for(int i=0;i<version2.length();i++){
            s+=version2[i];
            if(version2[i]=='.'){
                b.push_back(stoi(s));
                s.clear();
                continue;
            }
        }
        if(s.length()>0){
             b.push_back(stoi(s));
        }
        int size=min(a.size(),b.size());
        int size2=max(a.size(),b.size());
        if(size!=size2){
            int diff=size2-size;
            if(a.size()==size){
               for(int i=0;i<diff;i++){
                  a.push_back(0);
               }
            }
            else{
               for(int i=0;i<diff;i++){
                  b.push_back(0);
               }
            }
        }
        bool ans=false;
        for(int i=0;i<a.size();i++){
               if(a[i]>b[i]){
                return 1;
               }
               if(a[i]<b[i]){
                return -1;
               }
        }
        return 0;
    }
};