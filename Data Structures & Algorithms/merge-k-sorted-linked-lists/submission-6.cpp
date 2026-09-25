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
    class compare {
       public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *root = nullptr, *cur = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> bucket;
        for (ListNode* ptr : lists) {
            if (ptr) bucket.push(ptr);
        }
        while (!bucket.empty()) {
            ListNode* minPtr = bucket.top();
            bucket.pop();
            if (root == nullptr)
                root = cur = minPtr;
            else {
                cur->next = minPtr;
                cur = cur->next;
            }
            if (minPtr->next) {
                bucket.push(minPtr->next);
            }
        }
        return root;
    }
};
