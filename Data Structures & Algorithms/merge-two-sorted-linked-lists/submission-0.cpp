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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 && list2)
        {
            ListNode * ret = nullptr;
            if(list1->val <= list2->val)
            {
                ret = list1;
                ret->next = mergeTwoLists(list1->next,list2);
            }
            else 
            {
                ret = list2;
                ret->next = mergeTwoLists(list1,list2->next);
            }
            return ret;
        }
        else if(list1)
            return list1;
        else
            return list2;
        
    }
};
