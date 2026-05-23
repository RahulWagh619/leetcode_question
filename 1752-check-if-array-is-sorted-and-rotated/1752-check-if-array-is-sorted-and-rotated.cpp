class Solution {
public:
bool issort(vector<int>&a){
    if(a.size()==1)return true;
    for(int i=1;i<a.size();i++){
        if(a[i]<a[i-1])return false;
    }
    return true;
}
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int>a=nums;
            for(int j=0;j<n;j++){
                a[j]=nums[(j+i)%n];
            }
            if(issort(a)){
                cout<<i<<endl;
                return true;
            }
        }
        return false;
    }
};