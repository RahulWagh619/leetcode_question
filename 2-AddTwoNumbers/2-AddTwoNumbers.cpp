// Last updated: 8/13/2025, 3:38:16 PM
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverse(l1);
        // l2 = reverse(l2);

        ListNode* ansHead = nullptr;
        ListNode* ansTail = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            if (ansHead == nullptr) {
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }
        }
        return ansHead;
    }
};
