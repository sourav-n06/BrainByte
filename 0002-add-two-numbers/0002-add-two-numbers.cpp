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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 && l2) {
                int sum = l1->val + l2->val + carry;
                carry = sum / 10;
                tail->next = new ListNode(sum % 10);
                l1 = l1->next;
                l2 = l2->next;
                tail = tail->next;
            } else if (l1 && !l2) {
                int sum = l1->val + carry;
                carry = sum / 10;
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
                l1 = l1->next;
            } else if (!l1 && l2) {
                int sum = l2->val + carry;
                carry = sum / 10;
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
                l2 = l2->next;
            }
        }
        if (carry) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head->next;
    }
};