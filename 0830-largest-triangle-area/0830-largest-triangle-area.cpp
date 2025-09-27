class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        long double val=(long double)INT_MIN;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    long double z=abs(points[i][0]*(points[j][1]-points[k][1])+points[j][0]*(points[k][1]-points[i][1])+points[k][0]*(points[i][1]-points[j][1]));
                    z=(long double)z/2;
                    val=max(val,z);
                }
            }
        }
        return (double)val;
    }
};