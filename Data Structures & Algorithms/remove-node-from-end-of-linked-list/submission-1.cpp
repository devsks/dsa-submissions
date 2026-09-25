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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head,*cur = head;

        for(int i=0;i<n && cur;++i)
        {
            cur = cur->next;
        }

        if(cur==nullptr)
        {
            return head->next;
        }
        else
            cur = cur->next;

        while(cur)
        {
            prev = prev->next;
            cur = cur->next;
        }

        if(cur==nullptr)
        {
            ListNode* del = prev->next;
            if(del)
                prev->next = del->next;
            
        }

        return head;
        
    }
};
