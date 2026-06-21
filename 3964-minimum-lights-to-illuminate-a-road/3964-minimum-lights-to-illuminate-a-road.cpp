class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>diff(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int left=max(0,i-lights[i]);
                int right=min(n-1,i+lights[i]);
                diff[left]+=1;
                if(right!=n-1){
                    diff[right+1]-=1;
                }
            }
        }
        vector<int>pf(n);
        pf[0]=diff[0];
        for(int i=1;i<n;i++){
           pf[i]=pf[i-1]+diff[i];
        }
        int count=0;
        if(pf[0]==0){
            if(n==1){
                return 1;
            }
            count++;
            if(n==2){
                pf[0]=1;
                pf[1]=1;
            }
            else{
                pf[0]=1;
                pf[1]=1;
                pf[2]=1;
            }
        }
         if(pf[n-1]==0){
            if(n==1){
                return 1;
            }
            count++;
            if(n==2){
                pf[n-1]=1;
                pf[n-2]=1;
            }
            else{
                pf[n-1]=1;
                pf[n-2]=1;
                pf[n-3]=1;
            }
        }
        for(int i=1;i<n-1;i++){
             if(pf[i]==0){
                int idx=-1;
                int maxi=0;
              
                if(i==1){
                   for(int j=i;j<=i+1;j++){
                     int v=0;
                     if(pf[j]==0){
                         v++;
                     }
                     if(pf[j-1]==0){
                        v++;
                     }
                     if(pf[j+1]==0){
                        v++;
                     }
                     if(v>maxi){
                        idx=j;
                        maxi=v;
                     }
                   }
                }
                else if(i==n-2){
                    for(int j=i-1;j<=i;j++){
                     int v=0;
                     if(pf[j]==0){
                         v++;
                     }
                     if(pf[j-1]==0){
                        v++;
                     }
                     if(pf[j+1]==0){
                        v++;
                     }
                     if(v>maxi){
                        idx=j;
                        maxi=v;
                     }
                   }
                }
                else{
                for(int j=i-1;j<=i+1;j++){
                     int v=0;
                     if(pf[j]==0){
                         v++;
                     }
                     if(pf[j-1]==0){
                        v++;
                     }
                     if(pf[j+1]==0){
                        v++;
                     }
                     if(v>maxi){
                        idx=j;
                     }
                }
                }
                pf[idx]=1;
                pf[idx-1]=1;
                pf[idx+1]=1;
                count++;
             }
        }
        return count;
    }
};