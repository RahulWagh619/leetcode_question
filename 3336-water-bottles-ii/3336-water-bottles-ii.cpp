class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total=numBottles;
        int left=total;
        while(left>=numExchange){
            left-=(numExchange);
            left++;
            total++;
            numExchange++;
        }
        return total;
    }
};