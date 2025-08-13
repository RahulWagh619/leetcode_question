// Last updated: 8/13/2025, 3:34:21 PM
class Solution {
public:
    int tribonacci(int n) {
        int a=0;
        int b=1;
        int c=1;
        if(n==0){
            return a;
        }
        if(n==1){
            return b;
        }
        if(n==2){
            return c;
        }
        int val=0;
        for(int i=3;i<=n;i++){
               val=a+b+c;
               a=b;
               b=c;
               c=val;
        }
        return val;
    }
};