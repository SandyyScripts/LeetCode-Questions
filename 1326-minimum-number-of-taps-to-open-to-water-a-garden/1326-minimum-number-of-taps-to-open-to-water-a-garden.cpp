class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min=0, max=0, count=0;  // Initialize variables to keep track of the minimum and maximum reach, and the number of taps used.
        while (max < n) {  // Continue looping until we cover the entire range from 0 to n.
            for (int i = 0; i < ranges.size(); i++) {
                // Check if tap i can cover the current minimum position (min) and reach the current maximum position (max).
                if (i - ranges[i] <= min && i + ranges[i] >= max)
                    max = i + ranges[i];  // Update the maximum reach if this tap can cover the current range.
            }
            if (max == min) return -1;  // If max is not updated in this loop, it means we can't extend the reach further. Return -1 as it's not possible.
            count++;  // Increment the count of taps used.
            min = max; 
        }
        return count; 
    }
};