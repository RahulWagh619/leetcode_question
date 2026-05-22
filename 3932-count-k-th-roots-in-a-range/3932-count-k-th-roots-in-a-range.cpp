class Solution {
public:
typedef long long ll;
const int mod = 1e9 + 7;
ll power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    ll res = power(a, b / 2);
    res = (res * res);
    if (b & 1)
    {
        res = (res * a);
    }
    return res;
}
    int countKthRoots(int l, int r, int k) {
        int count=0;
        if(k==1){
            return r-l+1;
        }
        for(int i=0;i<=r;i++){
            ll val=power(i,k);
            if(val>r){
                break;
            }
            if(val>=l && r>=val){
                count++;
            }
        }
        return count;
    }
};