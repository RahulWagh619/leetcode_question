class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()){
            return "0";
        }
        stack<int>st;
        st.push(num[0]-'0');
        for(int i=1;i<num.length();i++){
            if(st.empty()){
                st.push(num[i]-'0');
            }
            else{
                int curr=num[i]-'0';
                if(st.top()<=curr){
                    st.push(curr);
                }
                else{
                    while(!st.empty() && st.top()>curr && k>0){
                        st.pop();
                        k--;
                    }
                    st.push(curr);
                }
                
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        string z="";
        while(!st.empty()){
            z+=st.top()+'0';
            st.pop();
        }
        reverse(z.begin(),z.end());
        if(z.length()==0){
            return "0";
        }
        int idx=-1;
        for(int i=0;i<z.length();i++){
            if(z[i]=='0'){
                continue;
            }
            else{
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return "0";
        }
        int left=z.length()-idx;
        return z.substr(idx,left);
    }
};