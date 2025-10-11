class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        for (auto &p : power) {
            unique_power_sum[p] += p;
        }

        for (auto [key, _] : unique_power_sum) {
            unique_power.push_back(key);
        }
        sort(unique_power.begin(), unique_power.end());

        n = (int) unique_power.size();
        dp.assign(n, -1);

        return solve(0);
    }

private:
    vector<int> unique_power;
    unordered_map<int, long long> unique_power_sum;
    vector<long long> dp;
    int n;

    long long solve(int i) {
        if (i >= n) {
            return 0;
        }

        auto &ret = dp[i];
        if (ret != -1) {
            return ret;
        }

        ret = solve(i + 1);

        int j = find_first_castable_spell(i);
        ret = max(ret, unique_power_sum[unique_power[i]] + solve(j));

        return ret;
    }

    int find_first_castable_spell(int i) {
        int j = i;
        while(j < n && unique_power[j] <= unique_power[i] + 2) {
            ++j;
        }
        return j;
    }
};

/*
    Topics: Sorting, and Dynamic Programming
    Time: O(n + nlog(n))
    Space: O(n)
*/
