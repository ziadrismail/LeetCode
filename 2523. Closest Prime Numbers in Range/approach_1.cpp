class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        generatePrimes();

        vector < int > primesInRange;
        for (int i = left; i <= right; ++i)
            if (isPrime[i])
                primesInRange.push_back(i);

        int n = (int) primesInRange.size();
        if (n < 2)
            return {-1, -1};
        
        int minDiff = INT_MAX;
        vector < int > ans;
        for (int i = 0; i + 1 < n; ++i) {
            int num1 = primesInRange[i], num2 = primesInRange[i + 1];
            int curDiff = num2 - num1;
            if ((curDiff < minDiff) || (curDiff == minDiff && num1 < ans[0])) {
                minDiff = curDiff;
                ans = {num1, num2};
            }
        }

        if (minDiff == INT_MAX)
            return {-1, -1};
        return ans;
    }

private:
    static const int MAX = (int) 1e6;
    bool isPrime[MAX + 100];

    void generatePrimes() {
        for (int i = 2; i <= MAX; ++i)
            isPrime[i] = true;
        for (int i = 4; i <= MAX; i += 2)
            isPrime[i] = false;
        for (int i = 3; i * i <= MAX; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }
    }
};

/*
    Time: O(MAXloglog(MAX)) -> Because of Sieve of Eratosthenes
    Space: O(MAX)
*/
