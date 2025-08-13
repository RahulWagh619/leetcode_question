// Last updated: 8/13/2025, 3:37:48 PM
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            int len=0;
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                len=i-st.top();
                maxlen=max(maxlen,len);
                }
            }
        }
        return maxlen;
    }
};