class Solution {
public:
    int maximumSwap(int num) {
        // If we deal with num as string, we can do swap operation easily
        string numString = to_string(num);

        int n = (int) numString.size(), ans = num;

        // Try all possible swaps
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Do the swap operation
                swap(numString[i], numString[j]);

                // Covert numString back to int again and try to maximize the answer
                int possibleAnswer = stoi(numString);
                ans = max(ans, possibleAnswer);

                // Undo the swap operation to calculate the following iteration correctly
                swap(numString[i], numString[j]);
            }
        }

        return ans;
    }
};

/*
    Time: O(n^2)
    Space: O(n)
*/
