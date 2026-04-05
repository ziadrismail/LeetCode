class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        
        for (auto &move : moves) {
            if (move == 'L' || move == 'R') {
                x += (move == 'R' ? 1 : -1);
            } else {
                y += (move == 'U' ? 1 : -1);
            }
        }

        return !x && !y;
    }
};
