// Last updated: 8/13/2025, 3:36:20 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*a=headA;
        ListNode*b=headB;
        int lenA=0;
        int lenB=0;
        if(a==b){
            return a;
        }
        else{
        while(a!=NULL){
             a=a->next;
             lenA++;
        }
         while(b!=NULL){
             b=b->next;
             lenB++;
        }
        cout<<lenA<<" "<<lenB<<endl;
        a=headA;
        b=headB;
        while(lenA>lenB){
             a=a->next;
            lenA--;
        }
        while(lenB>lenA){
            b=b->next;
            lenB--;
        }
        while(a!=NULL && b!=NULL){
            if(a==b){
                return a;
                break;
            }
            a=a->next;
            b=b->next;
    
        }
      }
      return NULL;
    }
};