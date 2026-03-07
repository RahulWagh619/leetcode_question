class Solution {
public:
bool check(map<char,int>&mpp1,map<char,int>&mpp2){
    for(auto &i:mpp1){
        if(mpp2[i.first]<i.second){
            return false;
        }
    }
 return true;
}
bool correct(map<char,int>&mpp1,map<char,int>&mpp2){
    for(auto &i:mpp2){
        if(mpp1.find(i.first)==mpp1.end()){
            return false;
        }
    }
     for(auto &i:mpp1){
        if(mpp2[i.first]!=i.second){
            return false;
        }
    }
 return true;
}
    bool checkInclusion(string s1, string s2) {
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(int i=0;i<s1.length();i++){
            mpp1[s1[i]]++;
        }
        int l=0;
        for(int i=0;i<s2.length();i++){
            mpp2[s2[i]]++;
        while(check(mpp1,mpp2) && l<=i){
            if(correct(mpp1,mpp2))return true;
            mpp2[s2[l]]--;
            if(mpp2[s2[l]]==0){
                mpp2.erase(s2[l]);
            }
            l++;
        }
        }
    return false;
    }
};