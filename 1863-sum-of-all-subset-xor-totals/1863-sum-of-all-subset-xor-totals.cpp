class Solution {
public:
    // Helper function to recursively calculate the sum of XOR totals
    int helper(vector<int>& nums, int i, int currXOR) {
        // Base case: if we've considered all elements
        if (i == nums.size()) {
            return currXOR;
        }

        // Recursively calculate the XOR total when including the current element
        int including = helper(nums, i + 1, currXOR ^ nums[i]);

        // Recursively calculate the XOR total when excluding the current element
        int excluding = helper(nums, i + 1, currXOR);

        // Return the sum of XOR totals from both cases
        return including + excluding;
    }

    // Main function to initiate the recursive calls
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};