// Last updated: 8/13/2025, 3:38:04 PM
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
int getlength(ListNode*head){
    int count=0;
    ListNode*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int change=getlength(head)-n;
        ListNode*diff=head;
        if(change==0){
            head=head->next;
            diff=NULL;
            delete diff;
            return head;
        }
        else{
        int i=0;
        ListNode*prev=diff;
        while(i<change){
            prev=diff;
            diff=diff->next;
            i++;
        }
         prev->next=diff->next;
         diff=NULL;
        delete diff;
        return head;
    }
       
    }
};