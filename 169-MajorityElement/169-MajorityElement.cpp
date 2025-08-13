// Last updated: 8/13/2025, 3:36:18 PM
class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
    int element=a[0];
    int count=1;

  for(int i=1;i<n;i++){
    if(count!=0){if(a[i]==element){
        count++;
    }
    else{
        count--;
    }
    }
    else if(count==0 || count<0){
        element=a[i];
       count=1;
    }
    cout<<count<<endl;
   }

   return element;
    }
};