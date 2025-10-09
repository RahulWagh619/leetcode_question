class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long>a(n);
        vector<long long>pf(n);
        pf[0]=skill[0];
        for(long long i=1;i<n;i++){
            pf[i]=pf[i-1]+skill[i];
        }
        for(long long i=0;i<n;i++){
            a[i]=pf[i]*mana[0];
        }
        for(int j=1;j<m;j++){
              long long y=a[0];
              for(int i=0;i<n-1;i++){
                y=max(y,a[i+1]-pf[i]*mana[j]);
              }
              for(int i=0;i<n;i++){
                   a[i]=y+(pf[i]*mana[j]);
              }
        }
        return a[n-1];
    }
};