class Solution {
public:
    int minAddToMakeValid(string s) {
        // Imagine we have a stack to store open brackets.
        // But actually we only need to store their count.
        int stack_size = 0;

        // The answer will be the stack size after iterating the string,
        // + number of closed brackets we faced when stack_size = 0.
        int ans = 0;
        for (auto &c : s) {
            // If it's open bracket, increase stack_size
            if (c == '(')
                stack_size++;

            // If it's closed, there are two cases:
            // 1. stack_size > 0, decrease stack_size
            // 2. stack_size = 0, increase the answer
            if (c == ')')
                stack_size == 0 ? ans++ : stack_size--;
        }

        // Add the stack_size to the answer, as for each open we need to insert a closed one.
        ans += stack_size;
        return ans;
    }
};

/*
    Time: O(n)
    Space: O(1)
*/
