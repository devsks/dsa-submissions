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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        stack<ListNode*> secondHalf;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast)
        slow = slow->next;
        while(slow)
        {
            secondHalf.push(slow);
            slow = slow->next;
        }
        
        ListNode* ptr = head;
        while(!secondHalf.empty())
        {
            ListNode* nxt = ptr->next;
            cout<<secondHalf.top()->val<<" ";
            ptr->next = secondHalf.top();
            secondHalf.pop();
            ptr->next->next = nxt;
            ptr = nxt;
        }
        ptr->next = nullptr;

    }
};
