// Last updated: 8/13/2025, 3:37:53 PM
class Solution {
public:
    int removeElement(vector<int>& a, int val) {
     int start=0;
     int end=a.size()-1;
     while(start<=end){
        if(a[start]==val){
            swap(a[start],a[end]);
            end--;
        }
        else{
            start++;
        }
     }
     return end+1;
    }
};