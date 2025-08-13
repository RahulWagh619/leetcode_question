// Last updated: 8/13/2025, 3:33:51 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int>result(a.size());
        int i=0;
        int pos=0;
        int neg=1;
        while(i<a.size()){
            if(a[i]>0){
                result[pos]=a[i];
                pos=pos+2;
            }
            else{
                result[neg]=a[i];
                neg=neg+2;
            }
            i++;
        }
        return result;
    }
};