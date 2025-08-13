// Last updated: 8/13/2025, 3:37:17 PM
class Solution {
public:
void reverse(stack<string>&st,string&ans){
    if(st.empty()){
        return;
    }
    string a=st.top();
    st.pop();
    reverse(st,ans);
    ans+=a;
}
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end=i+1;
            while(path[end]!='/' && end<path.size()){
                 end++;
            }
            i=end;
            string s=path.substr(start,end-start);
            if(s=="/.."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(s!="/." && s!="/"){
                st.push(s);
            }
        }
        string ans;
        if(st.empty()){
            ans="/";
        }
        reverse(st,ans);
        return ans;
    }
};