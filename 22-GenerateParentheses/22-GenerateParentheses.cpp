// Last updated: 8/13/2025, 3:37:59 PM
class Solution {
public:
void generateParentheses(int n, string current, int open, int close, vector<string>& result) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        generateParentheses(n, current + '(', open + 1, close, result);
    }

    if (close < n) {
        generateParentheses(n, current + ')', open, close + 1, result);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParentheses(n, "", 0, 0, result);
        vector<string>final;
        for(int i=0;i<result.size();i++){
            stack<char>st;
            bool ans=true;
            for(int j=0;j<result[i].size();j++){
               if(result[i][j]=='('){
                st.push('(');
               }
               else{
                if(st.empty()){
                    ans=false;
                    break;
                }
                else if(st.top()=='('){
                    st.pop();
                }
               }
            }
            if(ans){
                final.push_back(result[i]);
            }
        }
        return final;
        
    }
};