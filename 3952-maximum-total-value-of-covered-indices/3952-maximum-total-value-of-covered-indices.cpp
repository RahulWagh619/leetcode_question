class Solution {
public:
typedef long long ll;
    long long maxTotal(vector<int>& nums, string s) {
        ll ans=0;
        int n=nums.size();
        vector<ll>pf(n);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
           pf[i]=nums[i]+pf[i-1];
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!pq.empty()){
                    int len=pq.size();
                    int start=i-len;
                    ll val=0;
                    if(start==0){
                        val=pf[i-1];
                    }
                    else{
                        val=pf[i-1]-pf[start-1];
                    }
                     if(s[start]=='0'){
        val-=pq.top();
        }
                    ans+=val;
                    while(!pq.empty()){
                        pq.pop();
                    }
                }
                if(i+1<n && s[i+1]=='1'){
                    pq.push(nums[i]);
                }
            }
            else{
                pq.push(nums[i]);
            }
        }
        if(!pq.empty()){
        int len=pq.size();
        int start=n-len;
         ll val=0;
                    if(start==0){
                        val=pf[n-1];
                    }
                    else{
                        val=pf[n-1]-pf[start-1];
                    }
        if(s[start]=='0'){
        val-=pq.top();
        }

        ans+=val;
        }
        return ans;
    }
};