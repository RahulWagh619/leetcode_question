class Solution {
public:
    int totalMoney(int n) {
        int val=(n+6)/7;
        int sum=0;
        int z=1;
        for(int i=1;i<=val;i++){
            if(i==val){
            int p=(n%7);
            if(p==0){
                p=7;
            }
            for(int j=z;j<p+z;j++){
                sum+=j;
              }
            }
            else{
                for(int j=z;j<z+7;j++){
                    sum+=j;
                }
            }
            z++;
        }
        return sum;
    }
};