// Last updated: 8/13/2025, 3:37:26 PM
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
    ListNode*temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* rotateRight(ListNode* head, int k) {
        int size=getlength(head);
        if(head==NULL || head->next == NULL){
            return head;}
        else{
            int changek=(k%size);
            if(changek==0)return head;
            int newlastnodepos=size-changek-1;
            ListNode*newlastnode=head;
            for(int i=0;i<newlastnodepos;i++){
                newlastnode=newlastnode->next;
            }
            ListNode*newhead=newlastnode->next;
            newlastnode->next=NULL;
            ListNode*temp=newhead;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=head;
        return newhead;
        }    

    }
};