/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0;
        vector<int>v;
        ListNode*cur=head;
        while(cur!=NULL){
            v.push_back(cur->val);
            cur=cur->next;
        }
        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            int sum=v[i]+v[v.size()-1-i];
            maxi=max(maxi,sum);
        }
        return maxi;

    }
};