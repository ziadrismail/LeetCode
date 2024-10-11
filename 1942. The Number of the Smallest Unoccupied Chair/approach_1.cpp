class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = (int) times.size();
        
        // We need a priority queue (min-heap) to store the arrival time, leave time, index
        priority_queue < pair < int, pair < int, int > > > q;
        for (int i = 0; i < n; ++i)
            q.push(make_pair(-times[i][0], make_pair(times[i][1], i)));    

        // We need another priority queue (min-heap) to store leave time, occupied chair
        priority_queue < pair < int, int > > occupied;

        // We need a set to store chairs that have been free, we will use std::set to retrieve smallest one in O(log(n))
        set < int > free_chairs;

        // We need an integer to indicate the smallest chair that never been occupied
        int mn_chair = 0;

        // We need an integer to indicate the current time
        int cur_time = 0;

        // Start with a friend with smallest arrival time then the next and so on...
        while (!q.empty()) {
            int arrival = -(q.top().first);
            int leaving = q.top().second.first;
            int cur_friend = q.top().second.second;

            q.pop();

            // Set the current time to arrival
            cur_time = arrival;

            // Free chairs where the occupied person has leaving time <= current time
            while(!occupied.empty() && -(occupied.top().first) <= cur_time) {
                // move the occupied char to free_chairs set
                free_chairs.insert(occupied.top().second);
                occupied.pop();
            }

            // Try to minimize the chair will be occupied
            int cur_mn;
            if (free_chairs.empty())
                cur_mn = mn_chair++;
            else {
                int set_mn = *free_chairs.begin();
                if (set_mn < mn_chair) {
                    cur_mn = set_mn;
                    free_chairs.erase(set_mn);
                } else {
                    cur_mn = mn_chair++;
                }
            }

            // If we reach target, return the current chair will be occupied
            if (cur_friend == targetFriend)
                return cur_mn;
            
            // Save the leaving time and chair number and continue searching for target
            occupied.push(make_pair(-leaving, cur_mn));
        }

        // Dummy variable, it's guaranteed that we will return the function within the while loop
        return -1;
    }
};

/*
    Time: O(nlog(n))
    Space: O(n)
*/
