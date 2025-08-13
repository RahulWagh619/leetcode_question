// Last updated: 8/13/2025, 3:36:12 PM
class Solution {
public:

  
    int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
            
            int j=2*i;
            while(j<n){
                prime[j]=false;
                j=j+i;
            }
        }
        }
        
        
        return count;
    }
};
  