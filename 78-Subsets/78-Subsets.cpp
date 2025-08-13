// Last updated: 8/13/2025, 3:37:13 PM
class Solution {
public:
void print(int i,vector<int>&a,vector<vector<int>>&c,vector<int>b){
    if(i>=a.size()){
        // if(b.size()==0){
        //     c.push_back([]);
        // }
       
        c.push_back(b);
        
        return;
    }
    b.push_back(a[i]);
    print(i+1,a,c,b);
    b.pop_back();
    print(i+1,a,c,b);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int>b;
        vector<vector<int>>c;
        print(i,nums,c,b);

        return c;
    }
};