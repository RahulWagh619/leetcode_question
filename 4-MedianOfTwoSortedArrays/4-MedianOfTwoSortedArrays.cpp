// Last updated: 8/13/2025, 3:38:14 PM
class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        for(int i=0;i<num2.size();i++){
            num1.push_back(num2[i]);
        }
        double ans;
        sort(num1.begin(),num1.end());
        int a=num1.size()-1;
        if(a%2==0){
            ans=(double)(num1[a/2]);
        }
        else{
            int i=num1[a/2];
            int j=num1[(a+1)/2];
            ans=(double)(i+j)/2;
        }
        return ans;

        
    }
};