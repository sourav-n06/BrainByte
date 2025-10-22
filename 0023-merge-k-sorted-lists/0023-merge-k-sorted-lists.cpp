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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap based on node value
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        

        int n = lists.size();
        
        if(n == 0) return NULL;

        cout<<n;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < n; i++) {
            if(lists[i])
                pq.push(lists[i]);
        }

        ListNode* resHead = new ListNode(-1);
        ListNode* resTail = resHead;

        while(!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            if(temp->next) pq.push(temp->next);

            resTail->next = temp;
            temp->next = nullptr;

            resTail = resTail->next;
        }

        return resHead->next;
    }
};