class Solution {
public:
    // Custom comparator to sort by length
    static bool compareByLength(const std::string &a, const std::string &b) {
        return a.length() < b.length();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort lexicographically
        sort(folder.begin(), folder.end());

        // Step 2: Sort by length using stable_sort to maintain lexicographical order for equal lengths
        stable_sort(folder.begin(), folder.end(), compareByLength);

        vector<string> res;
        unordered_set<string> set;

        // Step 3: Iterate through the sorted folder list
        for (string i : folder) {
            if (set.empty()) {
                set.insert(i);
                res.push_back(i);
            } else {
                string str = "/";
                int flag = 0;

                // Step 4: Build substrings and check if they exist in the set
                for (int j = 1; j < i.length(); j++) {
                    str += i[j];

                    if (j == i.length() - 1) {  // When we reach the end of the string
                        if (!set.count(str)) {
                            res.push_back(str);
                            set.insert(str);
                        }
                    }

                    // Check for '/' delimiter in the string
                    if (i[j] == '/') {
                        if (set.count(str)) {  // If a parent folder is already in the set
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};
