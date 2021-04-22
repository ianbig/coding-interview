#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fptr = head;
        int fstep = 0;
        // loop thr fast and slow ptr
        while (fptr && fptr->next) {
            fptr = fptr->next->next;
            fstep++;
        }
        // s in middle, head, length
        int llistLen = 2 * (fstep + 1) - 1;
        int pos_from_head = (llistLen - n) + 1;
        ListNode* mvptr = head;
        int step_from_head = pos_from_head - 1;
        while (mvptr && step_from_head > 1) {
            mvptr = mvptr->next;
            step_from_head--;
        }
        if (step_from_head == 0) {
            head = head->next;
            return head;
        }

        mvptr->next = mvptr->next->next;

        return head;
    }
};