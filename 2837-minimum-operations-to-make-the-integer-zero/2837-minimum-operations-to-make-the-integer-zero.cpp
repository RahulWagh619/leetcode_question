class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>=num1)return -1;
        long long ans=-1;
        for(long long i=1;i<=60;i++){
            long long val=num1-(i*num2);
            long long z=__builtin_popcountll(val);
            if(val<0){
                return -1;
            }
            if(z<=i && val>=i){
                return i;
                break;
            }
        }
        return -1;
    }
};