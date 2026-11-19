// LeetCode 206 - Reverse Linked List (Easy)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }

        return previous;
    }
};
