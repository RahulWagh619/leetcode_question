class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(nums[i]%2==0){
                  count1++;
                }
                else{
                    count2++;
                }
            }
            else{
                if(nums[i] & 1){
                    count1++;
                }
                else{
                    count2++;
                }
            }
        }
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        // int minc=mini;
        // int maxc=maxi;
        // if(count1==count2){
        //     for(int i=0;i<n;i++){
        //         if(i%2==0){
        //             if(nums[i]%2==0){
        //                  if(nums[i]==mini){
        //             mini++;
        //         }
        //         if(nums[i]==maxi){
        //             maxi--;
        //         }
        //             }
        //         }
        //         else{
        //             if(nums[i] & 1){
        //                  if(nums[i]==mini){
        //             mini++;
        //         }
        //         if(nums[i]==maxi){
        //             maxi--;
        //         }
        //             }
        //         }
        //     }
        // }
        int mini1=min(count1,count2);
        vector<int>temp=nums;
         if(count1<=count2){
            for(int i=0;i<n;i++){
                if(i%2==0){
                    if(nums[i]%2==0){
                        if(nums[i]==mini){
                           temp[i]++;
                        }
                        else if(nums[i]==maxi){
                           temp[i]--;
                        }
                    }
                }
                else{
                    if(nums[i] & 1){
                         if(nums[i]==mini){
                             temp[i]++;
                        }
                        else if(nums[i]==maxi){
                             temp[i]--;
                        }
                    }
                }
              }
        }
        int val1=*max_element(temp.begin(),temp.end())-(*min_element(temp.begin(),temp.end()));
        if(count1<count2){
            return {mini1,val1}; 
        }
        temp=nums;
        if(count1>=count2){
            for(int i=0;i<n;i++){
                if(i%2==0){
                    if(nums[i] & 1){
                        if(nums[i]==mini){
                             temp[i]++;
                        }
                    else if(nums[i]==maxi){
                             temp[i]--;
                        }
                    }
                }
                else{
                     if(nums[i]%2==0){
                        if(nums[i]==mini){
                            temp[i]++;
                        }
                     else if(nums[i]==maxi){
                             temp[i]--;
                        }
                    }
                }
              } 
        }
        int val2=*max_element(temp.begin(),temp.end())-(*min_element(temp.begin(),temp.end()));
        if(count2<count1){
            return {mini1,val2};
        }
        // cout<<val1<<" "<<val2<<endl;
        int val=min(val2,val1);
        
        return {mini1,val};
    }
};