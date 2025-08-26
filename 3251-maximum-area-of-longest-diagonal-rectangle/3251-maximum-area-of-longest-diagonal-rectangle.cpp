class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        // vector<pair<double,int>>vp;
        double maxi1=(double)-1;
        int maxi2=-1;
        for(int i=0;i<dimensions.size();i++){
              int v1=dimensions[i][0];
              int v2=dimensions[i][1];
              int value=(v1*v1)+(v2*v2);
              int final=v1*v2;
              double squareroot=(double)sqrt(value);

              if(squareroot>maxi1){
                maxi1=squareroot;
                maxi2=final;
              }
              else if(squareroot==maxi1){
                maxi2=max(maxi2,final);
              }
        }
        return maxi2;

    }
};