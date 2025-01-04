class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> minExist(26, INT_MAX);
        vector<int> maxExist(26, INT_MIN);

        for(int i = 0; i < s.size(); i++) {
            int ind = s[i] - 'a';
            minExist[ind] = min(minExist[ind], i);
            maxExist[ind] = max(maxExist[ind], i);
        }
        int uniqueCount = 0;
        for (int ind = 0; ind < 26; ind++) {
            // Check if the character has occurred in the input string
            if (minExist[ind] == INT_MAX || maxExist[ind] == INT_MIN) {
                continue; // No occurrences, move to the next character
            }

            // Set to store unique characters between the minimum and maximum occurrences
            unordered_set<char> st;

            // Iterate over the characters between the minimum and maximum occurrences
            for (int j = minExist[ind] + 1; j < maxExist[ind]; j++) {
                st.insert(s[j]);
            }

            // Add the count of unique characters between the occurrences to the final count
            uniqueCount += st.size();
        }

        // Return the total count of unique palindromic subsequences
        return uniqueCount;
    }
};