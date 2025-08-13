// Last updated: 8/13/2025, 3:37:56 PM
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
    int getlength(ListNode* head) {
        ListNode* temp = head; 
        int length = 0;
        while (temp != NULL) {
            temp = temp->next;
            length++;
        }
        return length;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getlength(head);
        if (k > len) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        int count = 0;

        while (count < k) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (forward != NULL) {
            head->next = reverseKGroup(forward, k);
        }

        return prev; 
    }
};
