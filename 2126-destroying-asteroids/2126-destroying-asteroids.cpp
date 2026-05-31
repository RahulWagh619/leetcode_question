class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
       long long val=mass;
       multiset<int>st;
       int n=asteroids.size();
       sort(asteroids.begin(),asteroids.end());
       for(int i=0;i<n;i++){
        st.insert(asteroids[i]);
       }   
       int maxi=asteroids[n-1];
       while(!st.empty()){
          auto it=st.upper_bound(val);
          if(it==st.begin()){
            return false;
          }
          it--;
          if(*it==maxi){
            return true;
          }
          val+=*it;
          st.erase(it);
       }
       return true;
    }
};