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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fwd = nullptr;

        int cnt = 0;
        while(curr && cnt < k) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            cnt++;
        }

        int c = 0;
        ListNode* check = fwd;
        while(check && c <= k){
            check = check->next;
            c++;
        }

        if(fwd && c >= k) {
            head->next = reverseKGroup(fwd, k);
        } else {
            head->next = fwd;
        }

        return prev;
    }
};