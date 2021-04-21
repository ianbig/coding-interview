#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *hashCycle(ListNode *head) {
        ListNode *slow_ptr = head, *fast_ptr = head;

        while (fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if (slow_ptr == fast_ptr) {
                return slow_ptr;
            }
        }

        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *meetNode = hashCycle(head);
        ListNode *startNode = head;

        while (startNode != meetNode) {
            startNode = startNode->next;
            meetNode = meetNode->next;
        }

        return meetNode;
    }
};

int main() {}