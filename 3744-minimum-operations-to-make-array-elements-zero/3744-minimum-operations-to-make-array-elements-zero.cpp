class Solution {
public:
void helper(vector<long long>&powerof4){
    long long z=1;
    for(int i=0;i<=15;i++){
        powerof4.push_back(z);
        z*=4;
    }
}
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        vector<long long>powerof4;
        helper(powerof4);
        for(int i=0;i<queries.size();i++){
            long long l=queries[i][0];
            long long r=queries[i][1];
            long long count=0;
            for (int k = 1; k <= 15; ++k) {
                long long block_start = powerof4[k - 1];
                long long block_end = powerof4[k] - 1;
                if (l > block_end) {
                    continue;
                }
                if (block_start > r) {
                    break;
                }
                long long intersection_start = max(l, block_start);
                long long intersection_end = min(r, block_end);
                long long num_elements = intersection_end - intersection_start + 1;
                count += k * num_elements;
            }

            ans+=((count+1)/2);
        }
        return ans;
    }
};