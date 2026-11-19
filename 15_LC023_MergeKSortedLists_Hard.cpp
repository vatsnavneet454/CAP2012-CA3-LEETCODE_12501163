// LeetCode 23 - Merge k Sorted Lists (Hard)
#include <queue>
#include <vector>
#include <functional>
using namespace std;

// LeetCode provides the ListNode definition.
class Solution {
private:
    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val; // Min-heap by node value.
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;

        for (ListNode* node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            ListNode* nextNode = smallest->next;
            tail->next = smallest;
            tail = smallest;

            if (nextNode != nullptr) {
                minHeap.push(nextNode);
            }
        }

        tail->next = nullptr;
        return dummy.next;
    }
};
