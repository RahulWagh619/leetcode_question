// Last updated: 8/13/2025, 3:35:50 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.length()!=t.length()){
            return false;
        }
        else{ 
            int i=0;
        while(i<s.length()){
            if(s[i]!=t[i]){
                return false;
            }
            else{
                i++;
            }
        }
        }
        return true;
    }
};