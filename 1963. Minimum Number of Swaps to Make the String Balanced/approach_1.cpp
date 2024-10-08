class Solution {
public:
    int minSwaps(string s) {
        // Stack to hold the opening brackets
        stack < char > st;

        // Check the string like the famous problem "Valid Parentheses".
        // Save the opening brackets(that don't have closing ones) in the stack.
        for (auto &c : s) {
            // If c is an opening, put it in the stack
            if (c == '[')
                st.push(c);
            
            // Else, pop the top from the stack if it isn't empty
            if (c == ']' && !st.empty())
                st.pop(); 
        }

        // Each swap will fix two pairs, so the answer is the current size of the stack(rounded up)
        return ((int) st.size() + 1) / 2;;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
