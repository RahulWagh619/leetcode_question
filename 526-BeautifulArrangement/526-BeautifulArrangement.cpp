// Last updated: 8/13/2025, 3:35:13 PM
class Solution {
public:
void printpermutations(vector<int>&a,int n,int &ans,int curnum){
    if(curnum==n+1){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0 && (curnum%i==0 || i%curnum==0)){
            a[i]=curnum;
            printpermutations(a,n,ans,curnum+1);
            a[i]=0;

        }
    }
}
    int countArrangement(int n) {
        vector<int>a(n+1);
        int ans=0;
        printpermutations(a,n,ans,1);
        return ans;
    }
};