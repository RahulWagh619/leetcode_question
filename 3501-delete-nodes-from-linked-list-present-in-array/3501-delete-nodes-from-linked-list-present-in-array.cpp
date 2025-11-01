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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        vector<int>a;
        ListNode* temp = head;
        while(temp!=NULL){
               if(st.find(temp->val)==st.end()){
                a.push_back(temp->val);
               }
               temp=temp->next;
        }
        if(a.size()==0)return NULL;
        ListNode*newhead=new ListNode(a[0]);
        ListNode*mover=newhead;
        for(int i=1;i<a.size();i++){
            ListNode*newnode=new ListNode(a[i]);
            mover->next=newnode;
            mover=newnode;
        }
        return newhead;
    }
};