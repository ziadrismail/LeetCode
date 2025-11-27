class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, cur_max_idx = n + m - 1;
        while (cur_max_idx >= 0) {
            if (i >= 0 && j >= 0) {
                if (nums2[j] >= nums1[i]) {
                    nums1[cur_max_idx--] = nums2[j--];
                } else {
                    nums1[cur_max_idx--] = nums1[i];
                    nums1[i] = 0;
                    --i;
                }
            } else if (j >= 0) {
                while (j >= 0) {
                    nums1[cur_max_idx--] = nums2[j--];
                }
            } else {
                break;
            }
        }
    }
};

/*
    Time: O(n + m)
    Space: O(1)
*/
