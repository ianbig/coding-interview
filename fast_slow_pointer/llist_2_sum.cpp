#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* append(ListNode* head, int val) {
        if (head == nullptr) {
            head = new ListNode(val);
            tail = head;
            head->next = nullptr;
            return head;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cin = 0, tmp = 0;
        ListNode* ans = NULL;
        // loop through 2 list
        while (l1 && l2) {
            tmp = cin + l1->val + l2->val;
            cin = tmp / 10;
            tmp = tmp % 10;
            ans = append(ans, tmp);
            l1 = l1->next;
            l2 = l2->next;
        }
        // if list not pasresd continue, remeber deal with cin
        while (l1) {
            if (cin) {
                l1->val = cin + l1->val;
                cin = l1->val / 10;
                l1->val = l1->val % 10;
            }
            ans = append(ans, l1->val);
            l1 = l1->next;
        }

        while (l2) {
            if (cin) {
                l2->val = cin + l2->val;
                cin = l2->val / 10;
                l2->val = l2->val % 10;
            }
            ans = append(ans, l2->val);
            l2 = l2->next;
        }
        // if list parse out, they are the same, check for cin
        if (cin) {
            ans = append(ans, cin);
        }

        return ans;
    }

   private:
    ListNode* tail;
};