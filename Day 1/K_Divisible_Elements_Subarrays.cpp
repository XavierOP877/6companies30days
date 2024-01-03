#include <vector>
#include <unordered_set>

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    int countDistinct(std::vector<int>& nums, int k, int p) {
        auto is_divisible = [p](int x) { return x % p == 0; };

        int n = nums.size();
        std::unordered_set<std::vector<int>, VectorHash> distinct_subarrays;

        for (int i = 0; i < n; ++i) {
            int divisible_count = 0;
            for (int j = i; j < n; ++j) {
                if (is_divisible(nums[j])) {
                    divisible_count++;
                }
                if (divisible_count > k) {
                    break;
                }
                distinct_subarrays.insert(std::vector<int>(nums.begin() + i, nums.begin() + j + 1));
            }
        }

        return distinct_subarrays.size();
    }
};
