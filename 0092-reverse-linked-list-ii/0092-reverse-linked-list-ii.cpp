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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int pos=1;
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*ll=NULL;
        ListNode*rr=NULL;
        ListNode*l=NULL;
        ListNode*r=NULL;
        while(cur){
            ListNode*node=cur->next;
            // if(node==NULL){
            //     break;
            // }
            if(pos==left){
                l=cur;
                if(pos>1){
                    ll=prev;
                }
            }
            if(pos>left && pos<=right){
                cur->next=prev;
            }
            if(pos==right){
                r=cur;
                if(node){
                    rr=node;
                }
            }
            prev=cur;
            cur=node;
            pos++;
        }
        // if(rr){
           l->next=rr;
        // }
        if(ll){
            ll->next=r;
        }
        // if(left==1 && right==1){
        //     return head;
        // }
        if(left==1){
            return r;
        }
        return head;
    }
};