class Solution {
public:
    int minSwaps(string s) {
        // Imagine we're using a stack to save the opening brackets.
        // But actually we don't have to save them, we just want to know their count.
        // So instead of using a stack, use an integer to save their count.
        int stack_size = 0;

        // As we did in approach_1, use the same algorithm as "Valid Parentheses" problem
        for (auto &c : s) {
            // If we face opening bracket, increase the stack size
            stack_size += c == '[';

            // If we face closing bracket and stack size greater than 0, reduce the stack size
            stack_size -= c == ']' && stack_size > 0;
        }

        // Each swap operation will fix two balanced pairs, so the answer will be stack_size / 2 (rounded up)
        return (stack_size + 1) / 2; 
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
