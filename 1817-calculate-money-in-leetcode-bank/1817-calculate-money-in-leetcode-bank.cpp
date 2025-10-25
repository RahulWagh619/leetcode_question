class Solution {
public:
    int totalMoney(int n) {
        int val=(n+6)/7;
        int sum=0;
        for(int i=1;i<=val;i++){
            int k=i+7-1;
            if(i==val){
                int p=(n%7);
                if(p==0){
                    p=7;
                }
                k=i+p-1;
            }
                int diff=(k+1)*(k);
                diff/=2;
                int diff2=(i)*(i-1);
                diff2/=2;
                sum+=diff-diff2;
        }
        return sum;
    }
};