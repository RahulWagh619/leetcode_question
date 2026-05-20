class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count=0;
        int n=A.size();
        vector<int>a(n);
        set<int>st;
        for(int i=0;i<n;i++){
            int val1=A[i];
            int val2=B[i];
            if(val1==val2){
                count++;
                
            }
            else{
                if(st.find(val1)!=st.end()){
                    count++;
                }
                 if(st.find(val2)!=st.end()){
                    count++;
                }
            }
            st.insert(val1);
            st.insert(val2);
                a[i]=count;
        }
        return a;
    }
};