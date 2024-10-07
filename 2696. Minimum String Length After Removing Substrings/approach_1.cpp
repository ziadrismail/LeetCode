class Solution {
public:
    int minLength(string s) {
        // Stack to store characters we didn't remove, so the answer will be its size
        stack < char > stk;

        // Store characters in the stack, if we face 'B' and the top of the stack 'A' 
        //or we face 'D' and the top 'C', pop the top element and don't push the current into the stack
        for (auto &c : s) {
            // Check this condition first to avoid run-time errors
            // because we always need to check the top element
            if (stk.empty()) {
                stk.push(c);
                continue;
            }

            // check cases we disscused
            if (c == 'B' && stk.top() == 'A')
                stk.pop();
            else if (c == 'D' && stk.top() == 'C')
                stk.pop();
            else
                stk.push(c);
        }

        // Return the size of the stack, means characters we didn't remove
        return (int) stk.size();
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
