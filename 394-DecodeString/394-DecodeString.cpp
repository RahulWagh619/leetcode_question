// Last updated: 8/13/2025, 3:35:29 PM
class Solution {
public:
bool isdigit(char k){
    if(k-'0'>=0 && k-'0'<=9){
        return true;
    }
    return false;
}
    string decodeString(string s) {
        stack<char>st;
        string finalans;
        for(int i=0;i<s.length();i++){
            string ans;
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else if(s[i]==']'){
                while(st.top()!='[' && !st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                reverse(ans.begin(),ans.end());
                st.pop();
                string val="";
                while(!st.empty() && isdigit(st.top())){
                    val+=st.top();
                    st.pop();
                }
                    string another="";
                if(val!=""){
                    reverse(val.begin(),val.end());
                    long long fans=stoll(val);
                    while(fans--){
                        another+=ans;
                    }
                }
                for(char c:another){
                    st.push(c);
                }
             }
            }
           while(!st.empty()){
            finalans+=st.top();
            st.pop();
           }
           reverse(finalans.begin(),finalans.end());
           return finalans;

    }
};