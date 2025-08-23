class Solution {
    private final String openBrackets = "([{";
    private final String closeBrackets = ")]}";

    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        for (char c : s.toCharArray()) {
            if (isOpen(c)) {
                stk.push(c);
            } else if (canRemove(stk, c)) {
                stk.pop();
            } else {
                return false;
            }
        }

        return stk.isEmpty();
    }

    private boolean isOpen(char bracket) {
        return openBrackets.indexOf(bracket) != -1;
    }

    private boolean canRemove(Stack<Character> stk, char close) {        
        return !stk.isEmpty() && (openBrackets.indexOf(stk.peek()) == closeBrackets.indexOf(close));
    }

}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
