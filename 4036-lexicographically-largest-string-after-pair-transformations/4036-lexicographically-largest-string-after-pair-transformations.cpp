class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        vector<char>ch{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        for(int i=0;i<n;i++){
            string v="";
            for(int j=0;j<31;j++){
                if(((nums[i]>>j) & 1)==1){
                    if(j<26){
                    v+=ch[j];
                    }
                    else{
                        int count=1 << (j - 25);;
                        while(count--){
                            v+='z';
                        }
                    }
                }

            }   
            reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};