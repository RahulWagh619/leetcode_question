// Last updated: 8/13/2025, 3:38:12 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
    else{

    long long rev=0;
    long long temp=x;
    while(temp!=0){
    int ldigit=temp%10;
    rev=rev*10+ldigit;
    temp/=10;}
    cout<<rev<<" "<<x<<endl;
    return(rev==x);
        }
    }
};