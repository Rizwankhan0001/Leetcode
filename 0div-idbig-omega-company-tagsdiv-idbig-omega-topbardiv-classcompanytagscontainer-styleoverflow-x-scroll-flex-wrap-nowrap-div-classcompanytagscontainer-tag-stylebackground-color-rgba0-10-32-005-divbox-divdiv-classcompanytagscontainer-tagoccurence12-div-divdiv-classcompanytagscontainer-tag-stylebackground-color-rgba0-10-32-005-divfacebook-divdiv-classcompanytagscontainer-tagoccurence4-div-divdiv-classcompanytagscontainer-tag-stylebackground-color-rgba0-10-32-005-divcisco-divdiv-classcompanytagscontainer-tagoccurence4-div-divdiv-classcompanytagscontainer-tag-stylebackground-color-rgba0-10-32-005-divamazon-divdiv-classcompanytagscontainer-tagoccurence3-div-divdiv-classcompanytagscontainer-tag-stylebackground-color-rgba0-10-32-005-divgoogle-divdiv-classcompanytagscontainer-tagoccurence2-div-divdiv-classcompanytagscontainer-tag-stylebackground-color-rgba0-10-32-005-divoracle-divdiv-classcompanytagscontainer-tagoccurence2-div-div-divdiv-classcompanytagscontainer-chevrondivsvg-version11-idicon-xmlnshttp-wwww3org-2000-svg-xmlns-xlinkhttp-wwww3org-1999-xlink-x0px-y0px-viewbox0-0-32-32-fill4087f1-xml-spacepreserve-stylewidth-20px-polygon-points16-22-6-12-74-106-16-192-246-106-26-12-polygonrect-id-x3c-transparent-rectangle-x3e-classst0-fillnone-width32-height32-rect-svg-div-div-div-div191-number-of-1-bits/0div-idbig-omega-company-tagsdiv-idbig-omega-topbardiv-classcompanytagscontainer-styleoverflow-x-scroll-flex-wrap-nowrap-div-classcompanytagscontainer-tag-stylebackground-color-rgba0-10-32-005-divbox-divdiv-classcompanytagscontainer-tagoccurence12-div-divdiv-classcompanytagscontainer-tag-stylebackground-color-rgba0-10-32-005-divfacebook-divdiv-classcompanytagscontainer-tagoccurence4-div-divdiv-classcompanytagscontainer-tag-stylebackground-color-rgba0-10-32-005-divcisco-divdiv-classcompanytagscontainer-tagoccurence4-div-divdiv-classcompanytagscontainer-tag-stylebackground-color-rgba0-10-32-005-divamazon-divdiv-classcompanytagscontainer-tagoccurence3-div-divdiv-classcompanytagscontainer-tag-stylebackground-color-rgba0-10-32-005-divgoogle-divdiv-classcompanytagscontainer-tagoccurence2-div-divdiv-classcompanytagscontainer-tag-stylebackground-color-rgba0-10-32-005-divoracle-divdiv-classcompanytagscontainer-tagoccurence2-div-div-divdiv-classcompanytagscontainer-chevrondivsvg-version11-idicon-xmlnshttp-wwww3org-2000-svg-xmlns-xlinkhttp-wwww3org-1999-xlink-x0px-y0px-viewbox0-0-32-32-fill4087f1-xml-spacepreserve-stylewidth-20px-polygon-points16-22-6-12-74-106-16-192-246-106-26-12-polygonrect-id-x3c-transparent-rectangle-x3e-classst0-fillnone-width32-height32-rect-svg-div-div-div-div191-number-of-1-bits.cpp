class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;  // Initialize a variable to store the count of set bits

        // Iterate through each bit of the input integer
        while (n != 0) {
            if (n & 1 == 1)  // Check if the rightmost bit is 1
                count++;     // Increment the count if the rightmost bit is 1
            n = n >> 1;      // Right shift the input integer to examine the next bit
        }

        return count;  // Return the total count of set bits
    }
};
