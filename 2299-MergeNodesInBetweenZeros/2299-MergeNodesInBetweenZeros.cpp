// Last updated: 8/13/2025, 3:33:49 PM
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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        vector<int>result;
        ListNode*temp=head;
        while(temp!=NULL){
        if(temp->val==0 ){
            if(sum>0){
            result.push_back(sum);
            }
            sum=0;
        }
            sum+=temp->val;
        // cout<<sum<<endl;
            temp=temp->next;
        }
        if (result.size()==0) {
            return nullptr;
        }
         ListNode* ans = new ListNode(result[0]);
        ListNode* curr = ans; 
        for (int i = 1; i < result.size(); i++) {
            curr->next = new ListNode(result[i]);
            curr = curr->next; 
        }
        return ans;
    }
};