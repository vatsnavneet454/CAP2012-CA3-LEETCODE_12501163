// LeetCode 25 - Reverse Nodes in k-Group (Hard)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrevious = &dummy;

        while (true) {
            // Find the kth node from groupPrevious.
            ListNode* kth = groupPrevious;
            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            // Fewer than k nodes remain: leave them unchanged.
            if (kth == nullptr) {
                break;
            }

            ListNode* groupNext = kth->next;
            ListNode* previous = groupNext;
            ListNode* current = groupPrevious->next;

            // Reverse exactly this group.
            while (current != groupNext) {
                ListNode* nextNode = current->next;
                current->next = previous;
                previous = current;
                current = nextNode;
            }

            ListNode* oldGroupHead = groupPrevious->next;
            groupPrevious->next = kth;
            groupPrevious = oldGroupHead;
        }

        return dummy.next;
    }
};
