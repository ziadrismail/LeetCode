class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        auto primes = generatePrimes();
        reverse(primes.begin(), primes.end());

        for (auto &prime : primes) {
            if (prime < nums[0]) {
                nums[0] = min(nums[0], nums[0] - prime);
                break;
            }
        }
                
        
        for (int i = 1; i < (int) nums.size(); ++i) {
            int candidate = 10000;
            for (auto &prime : primes) {
                if (prime < nums[i] && nums[i] - prime > nums[i - 1]) {
                    candidate = nums[i] - prime;
                    break;
                }
            }

            if (candidate != 10000 && nums[i] > nums[i - 1])
                nums[i] = min(candidate, nums[i]);
            else if (candidate != 10000)
                nums[i] = candidate;
        }

        bool ans = true;
        for (int i = 1; i < (int) nums.size(); ++i)
                ans &= nums[i] > nums[i - 1];

        return ans;
    }

private:
    static const int MAX = 1000;
    bool isPrime[MAX + 10];

    vector < int > generatePrimes() {
        vector < int > ret;
        
        for (int i = 2; i <= MAX; ++i)
            isPrime[i] = true;
        
        ret.push_back(2);
        for (int i = 4; i <= MAX; i += 2)
            isPrime[i] = false;
        
        for (int i = 3; i <= MAX; i += 2) {
            if (isPrime[i]) {
                ret.push_back(i);
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        return ret;
    }
};

/*
    Time: O(n + MAXlog(log(MAX)))
    Space: O(MAX)
*/
