// Last updated: 8/13/2025, 3:37:49 PM
class Solution {
public:
    void nextPermutation(vector<int>& a) {
            int index=-1;
    for (int i = a.size()-2; i >= 0; i--)
    {
        if(a[i]<a[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(a.begin(),a.end());
        return;
    }
    for (int i = a.size()-1; i>index; i--)
    {
        if(a[i]>a[index]){
            swap(a[i],a[index]);
            break;
        }
    }
      sort(a.begin()+index+1,a.end());

    }
};