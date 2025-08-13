// Last updated: 8/13/2025, 3:34:24 PM
class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        vector<int>b;

       for(int i=1;i<a.size();i++){
        int max=a[i];
        for(int j=i+1;j<a.size();j++){
            if(a[j]>max){
                max=a[j];
            }
        }
        b.push_back(max);
       }
       b.push_back(-1);
       for(int i=0;i<a.size();i++){
        a[i]=b[i];
       }
        return a;
    }
};