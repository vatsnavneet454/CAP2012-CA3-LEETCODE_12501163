// LeetCode 61 - Rotate List (Medium)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k %= length;
        if (k == 0) {
            return head;
        }

        tail->next = head; // Temporarily make the list circular.

        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
