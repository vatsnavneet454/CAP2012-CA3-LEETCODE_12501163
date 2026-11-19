// LeetCode 735 - Asteroid Collision (Medium)
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivors; // Used as a stack.

        for (int asteroid : asteroids) {
            bool alive = true;

            while (alive && asteroid < 0 && !survivors.empty() && survivors.back() > 0) {
                long long rightSize = survivors.back();
                long long leftSize = -static_cast<long long>(asteroid);

                if (rightSize < leftSize) {
                    survivors.pop_back();
                } else if (rightSize == leftSize) {
                    survivors.pop_back();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                survivors.push_back(asteroid);
            }
        }

        return survivors;
    }
};
