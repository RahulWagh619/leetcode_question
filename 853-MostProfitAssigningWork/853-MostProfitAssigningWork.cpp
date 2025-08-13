// Last updated: 8/13/2025, 3:34:55 PM
class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>vp;
        int n=d.size();
        for(int i=0;i<d.size();i++){
            vp.push_back({d[i],p[i]});
        }
        sort(vp.begin(),vp.end());
        vector<int>maxi(n);
        maxi[0]=vp[0].second;
        for(int i=1;i<n;i++){
          maxi[i]=max(maxi[i-1],vp[i].second);
        }
        vector<int>ans;
        for(int i=0;i<w.size();i++){
            int target=w[i];
            int start=0;
            int end=d.size()-1;
            int val=-1;
            while(start<=end){
                int mid=(start)+(end-start)/2;
                if(target>=vp[mid].first){
                    val=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            ans.push_back(val);
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=-1){
                sum+=maxi[ans[i]];
            }
        }
        return sum;
    }
};