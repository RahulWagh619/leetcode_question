// Last updated: 8/13/2025, 3:38:02 PM
class Solution {
public:
bool checker(char i,char j){
    if(i=='(' && j==')')return true;
    else if(i=='{' && j=='}')return true;
    else if(i=='[' && j==']')return true;
    else return false;
}
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                char k=s[i];
                if(!st.empty()){
                char l=st.top();
                if(checker(l,k)){
                    st.pop();
                }
                else{
                    return false;
                }
              }
              else{
                return false;
              }
               
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }

    }
};