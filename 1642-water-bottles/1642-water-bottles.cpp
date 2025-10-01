class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        int left=numBottles/numExchange;
        int rem=numBottles%numExchange;
        total+=left;
        while(left+rem>=numExchange){
            left+=rem;
            rem=(left)%numExchange;
            left=left/numExchange;
            total+=left;
        }
        return total;
    }
};