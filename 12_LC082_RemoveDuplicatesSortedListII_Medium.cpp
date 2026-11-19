// LeetCode 82 - Remove Duplicates from Sorted List II (Medium)
// LeetCode provides the ListNode definition.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* previous = &dummy;
        ListNode* current = head;

        while (current != nullptr) {
            if (current->next != nullptr && current->val == current->next->val) {
                int duplicateValue = current->val;

                while (current != nullptr && current->val == duplicateValue) {
                    current = current->next;
                }
                previous->next = current;
            } else {
                previous = current;
                current = current->next;
            }
        }

        return dummy.next;
    }
};
