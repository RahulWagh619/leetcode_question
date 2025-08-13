// Last updated: 8/13/2025, 3:37:54 PM
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i=0;
        int j=i+1;
        while(j<a.size()){
            if(a[i]==a[j]){
                j++;
            }
            else{
                a[i+1]=a[j];
                i++;
                j++;
            }
        }
        return i+1;
        }
};