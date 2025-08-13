// Last updated: 8/13/2025, 3:37:45 PM
class Solution {
public:
int foccur(vector<int>&a,int start,int end,int target,int store){
    if(start>end)return store;
    int mid=(start+end)/2;
    if(a[mid]==target){
        store=mid;
        return foccur(a,start,mid-1,target,store);
    }
    else if(a[mid]>target){
        return foccur(a,start,mid-1,target,store);
    }
    else{
        return foccur(a,mid+1,end,target,store);
    }
}
int loccur(vector<int>&a,int start,int end,int target,int store){
    if(start>end)return store;
    int mid=(start+end)/2;
    if(a[mid]==target){
        store=mid;
        return loccur(a,mid+1,end,target,store);
    }
    else if(a[mid]>target){
        return loccur(a,start,mid-1,target,store);
    }
    else{
        return loccur(a,mid+1,end,target,store);
    }
}

    vector<int> searchRange(vector<int>& a, int target) {
        int start=0;
        int end=a.size()-1;
        int f=foccur(a,start,end,target,-1);
        int l=loccur(a,start,end,target,-1);
        return {f,l};
    }
};