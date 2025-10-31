class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()){
            return "0";
        }
        stack<int>st;;
        for(int i=0;i<num.length();i++){
            while(!st.empty() && num[i]<st.top() && k>0){
                st.pop();
                k--;
            }
                st.push(num[i]);
        }
        string s;
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        int idx=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            return "0";
        }
        s=s.substr(idx);
        int val=s.length()-k;
        if(val<=0){
            return "0";
        }
        s=s.substr(0,val);
        if(s.length()==0)return "0";
        return s;
    }
};