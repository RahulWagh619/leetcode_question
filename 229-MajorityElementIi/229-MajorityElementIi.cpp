// Last updated: 8/13/2025, 3:36:02 PM
class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        vector<int>ans;
        int count1=0;
        int count2=0;
        int ele1=0;
        int ele2=0;
        int k=a.size()/3;
        for(int i=0;i<a.size();i++){
            if(count1==0 && ele2!=a[i]){
                ele1=a[i];
                count1=1;
            }
            else if(count2==0 && ele1!=a[i]){
                ele2=a[i];
                count2=1;
            } 
            else if(a[i]==ele1){
                count1++;
            }
            else if(a[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }

        }
        count1=0;
        count2=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==ele1){
                count1++;
            }
            else if(a[i]==ele2){
                count2++;
            }
        }
        if(count1>k){
            ans.push_back(ele1);
        }
        if(count2>k){
            ans.push_back(ele2);
        }
        return ans;
    }
};