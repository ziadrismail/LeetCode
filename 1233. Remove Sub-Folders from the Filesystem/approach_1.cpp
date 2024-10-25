class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        // We need a hash set to check if a sub-folder's prefix in st
        unordered_set < string > st;
        for (auto &folder : folders)
            st.insert(folder);

        vector < string > ans;

        for (auto &folder : folders) {
            string sub_folder_prefix;
            bool is_sub = false;
            st.erase(folder);
            for (int i = 0; i < (int) folder.size();) {
                sub_folder_prefix += folder[i++];
                while (i < (int) folder.size() && folder[i] != '/')
                    sub_folder_prefix += folder[i++];
                is_sub |= st.count(sub_folder_prefix) > 0;
            }
            st.insert(folder);
            if (!is_sub)
                ans.push_back(folder);
        }

        return ans;
    }
};
