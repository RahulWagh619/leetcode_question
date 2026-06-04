class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100){
            return 0;
        }
        int count=0;
        for(int i=max(num1,100);i<=num2;i++){
            string s=to_string(i);
            int len=s.length()-2;
            for(int j=1;j<=len;j++){
                int left=s[j-1]-'0';
                int right=s[j+1]-'0';
                int curr=s[j]-'0';
                if(curr>left && curr>right||curr<left && curr<right){
                    count++;
                }
            }

        }
        return count;
    }
};