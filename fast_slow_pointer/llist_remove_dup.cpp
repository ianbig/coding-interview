#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *sptr = head, *fptr = head;

        while (fptr) {
            if (sptr == fptr) {
                fptr = fptr->next;
            } else if (sptr->val != fptr->val) {
                sptr = fptr;
            } else if (sptr->val == fptr->val) {
                fptr = fptr->next;
                sptr->next = fptr;
            }
        }

        return head;
    }
};