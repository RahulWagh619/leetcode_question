// Last updated: 8/13/2025, 3:34:33 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='b'){
                st.push(s[i]);
            }
            else{
                if(st.size()>=2){
                    char a=st.top();st.pop();
                    char b=st.top();st.pop();

                    if(a=='b' && b=='a'){
                        continue;
                    }
                    else{
                        st.push(b);
                        st.push(a);
                        st.push('c');
                    }
                }
                else{
                    st.push('c');
                }
            }
        }
        return st.empty();
       
    }
};