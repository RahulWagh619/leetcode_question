// Last updated: 8/13/2025, 3:34:29 PM
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(i==0){
             st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string abc;
        while(!st.empty()){
            abc+=st.top();
            st.pop();
        }
        reverse(abc.begin(),abc.end());
        return abc;

    }
};