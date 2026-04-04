class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.length()/rows;
        if(cols==0)return "";
        vector<vector<char>>mat(rows,vector<char>(cols));
        int v=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[i][j]=encodedText[v];
                v++;
            }
        }
        // for(int i=0;i<rows;i++){
        //    for(int j=0;j<cols;j++){
        //     cout<<mat[i][j]<<" ";
        //    }
        //    cout<<endl;
        // }
        string ans;
        for(int i=0;i<cols;i++){
            int z=0;
            for(int j=0;j<rows;j++){
                if(z+i>=cols){
                    break;
                }
                ans+=mat[j][z+i];
                // cout<<mat[j][z]<<endl;
                z++;
            }
            // cout<<endl;
        }
        cout<<ans<<endl;
        if(ans[ans.length()-1]!=' '){
            return ans;
        }
        int idx=-1;
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]!=' ')break;
            else idx=i;
        }
        string b=ans.substr(0,idx);
        return b;
    }
};