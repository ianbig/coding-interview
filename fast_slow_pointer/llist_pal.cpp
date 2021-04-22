#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head || head->next == nullptr) {
            return head;
        }

        ListNode* next = head->next;
        ListNode* new_head = reverseList(next);
        next->next = head;
        head->next = NULL;

        return new_head;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *sptr = head, *fptr = head;

        while (fptr && fptr->next) {
            sptr = sptr->next;
            fptr = fptr->next->next;
        }

        fptr = reverseList(sptr);
        sptr = head;
        while (fptr) {
            if (fptr->val != sptr->val) return false;
            sptr = sptr->next;
            fptr = fptr->next;
        }

        return true;
    }
};