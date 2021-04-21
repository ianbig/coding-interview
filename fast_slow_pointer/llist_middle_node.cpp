#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode *sptr = head, *fptr = head;

        while (fptr && fptr->next) {
            sptr = sptr->next;
            fptr = fptr->next->next;
        }

        return sptr;
    }
};