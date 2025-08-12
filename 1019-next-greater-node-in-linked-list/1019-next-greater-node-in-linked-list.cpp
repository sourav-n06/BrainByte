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

    ListNode* revLink(ListNode* head) {
        if(head == nullptr || head->next == nullptr) 
            return head;

        ListNode* chotoHead = revLink(head->next);

        head->next->next = head;
        head->next = nullptr;

        return chotoHead;
    }

    void NGE(vector<int> &ans, ListNode* head, stack<int> st) {
        
        while(head) {
            
            if(!st.empty() && head->val < st.top()) {
                int n = st.top();
                ans.push_back(n);
            } else {
                while(!st.empty() && head->val >= st.top()) {
                    st.pop();
                }
                if(st.empty()) ans.push_back(0);
                else ans.push_back(st.top());
            }
            st.push(head->val);
            head = head->next;
        }
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        
        vector<int> ans;
        head = revLink(head);
        stack<int> st;

        NGE(ans, head, st);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};