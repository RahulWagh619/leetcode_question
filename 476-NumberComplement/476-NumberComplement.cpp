// Last updated: 8/13/2025, 3:35:24 PM
class Solution {
public:
string decimalToBinary(int num) {
    string binary = "";
    
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num = num / 2;
    }

    return binary;
}
    int findComplement(int nums) {
        string ans=decimalToBinary(nums);
        for(int i=0;i<ans.length();i++){
            if(ans[i]=='0'){
                ans[i]='1';
            }
            else{
                ans[i]='0';
            }
        }
        reverse(ans.begin(),ans.end());
        vector<int>num;
         for(int i=0;i<ans.length();i++){
            if(ans[i]=='1'){
                // ans[i]='1';
                num.push_back(i);
            }
        }
        int finalans=0;
         for(int i=0;i<num.size();i++){
            finalans+=pow(2,num[i]);
            cout<<num[i]<<" ";
        }
    return finalans;
    }
};