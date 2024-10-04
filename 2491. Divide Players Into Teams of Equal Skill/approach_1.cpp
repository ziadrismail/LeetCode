class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int teams = (int) skill.size() / 2;
        int overall_skill = accumulate(skill.begin(), skill.end(), 0);

        // overall skill must be divisible by the number of teams(n / 2)
        if (overall_skill % teams)
            return -1;

        // Calculate the skill of each team
        int team_skill = overall_skill / teams;

        // Multiset to save each player's skill and try to find his teammate
        multiset < int > players(skill.begin(), skill.end());

        long long ans = 0;

        // Match teammates, if current player's skill = x, his teammate will have skill = team_skill - x.
        // If you couldn't find a match, return -1, otherwise add team chemistry to the answer
        
        auto it = players.begin();
        while (it != players.end()) {
            // First player's skill
            auto x = *it;

            // Try to find a second player for this team
            auto it2 = players.find(team_skill - x);

            // If it2 = players.end(), it means we couldn't find a second player
            if (it2 == players.end())
                return -1;
            
            // Add team chemistry to the answer
            auto y = *it2;
            ans += 1LL * x * y;

            // Remove both players from the multiset
            players.erase(it);
            it2 = players.find(y);
            players.erase(it2);

            // Update iterator to search for the next team
            it = players.begin();
        }

        return ans;
    }
};

/*  
    Time: O(nlog(n))
    Space: O(n)
*/
