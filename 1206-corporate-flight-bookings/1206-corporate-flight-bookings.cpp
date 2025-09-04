class Solution {

public:

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int>k(n+2);

        for(int i=0;i<bookings.size();i++){

            int start=bookings[i][0];

            int end=bookings[i][1];

            int val=bookings[i][2];

            k[start]+=val;

            k[end+1]-=val;

        }

        vector<int>pf(n+1);
        pf[1]=k[1];
        for(int i=2;i<=n;i++){
            pf[i]=pf[i-1]+k[i];
        }
        vector<int>ans(pf.begin()+1,pf.end());
        return ans;

    }

};