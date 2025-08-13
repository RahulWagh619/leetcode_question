// Last updated: 8/13/2025, 3:35:34 PM
class Solution {
public:
bool isVowel(char ch){
    return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
}
    string reverseVowels(string s) {
    
        int i=0;
        int j=s.length()-1;
        while(i<=j){
                if(isVowel(s[i]) && isVowel(s[j])){
                    swap(s[i],s[j]);
                    i++;
                    j--;
                } 
                else if(!isVowel(s[i])){
                    i++;
                }
                else{
                    j--;
                }
        }
        return s;
        
    }
};