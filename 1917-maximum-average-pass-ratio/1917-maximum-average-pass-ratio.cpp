
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++) {
            double pass = classes[i][0];
            double total = classes[i][1];
            double gain = (pass + 1) / (total + 1) - pass / total;
            pq.push({gain, i});
        }

        while (extraStudents > 0) {
            int index = pq.top().second;
            pq.pop();

            classes[index][0]++;
            classes[index][1]++;
            double pass = classes[index][0];
            double total = classes[index][1];
            double new_gain = (pass + 1) / (total + 1) - pass / total;
            pq.push({new_gain, index});

            extraStudents--;
        }
        double ans = 0;
        for (int i = 0; i < classes.size(); i++) {
            ans += (double)classes[i][0] / classes[i][1];
        }
        
        // Divide by the actual number of classes, not a hardcoded value
        ans /= classes.size();
        return ans;
    }
};