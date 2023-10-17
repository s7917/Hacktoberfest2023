class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sortedNums(nums);
        std::vector<int> res(n);

        // Sort the copy of the input array
        std::sort(sortedNums.begin(), sortedNums.end());

        for (int i = 0; i < n; i++) {
            // Use binary search to find the index of the current element in the sorted array
            res[i] = std::lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
        }

        return res;
    }
};