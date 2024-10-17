class Solution {
public:
    int maximumSwap(int num) {
        // If we deal with num as string, we can do swap operation easily
        string numString = to_string(num);
        
        int answer = num, numSize = (int) numString.size();

        // Keep track of the maximum from right to left and try to maximize the answer
        // by doing the swap operation if you find digit smaller than the maximum
        char maxDigit = numString.back();
        int maxDigitIndex = numSize - 1;
        for (int i = numSize - 2; i >= 0; --i) {
            if (numString[i] < maxDigit) {
                // Do the swap operation
                swap(numString[i], numString[maxDigitIndex]);

                // Convert the resulting number (after swap) back to int
                int possibleAnswer = stoi(numString);
                answer = max(answer, possibleAnswer);

                // Undo the swap operation to calculate the following iteration correctly
                swap(numString[i], numString[maxDigitIndex]);
            }

            // Update the maximum digit if possible
            if (numString[i] > maxDigit) {
                maxDigit = numString[i];
                maxDigitIndex = i;
            }
        }

        return answer;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
