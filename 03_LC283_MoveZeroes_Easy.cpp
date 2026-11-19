// LeetCode 283 - Move Zeroes (Easy)
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        while (writeIndex < static_cast<int>(nums.size())) {
            nums[writeIndex] = 0;
            writeIndex++;
        }
    }
};
