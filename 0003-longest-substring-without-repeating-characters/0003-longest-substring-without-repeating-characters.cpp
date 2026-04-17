#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> mp; // Map to track occurrence of characters
        int length = 0; // Length of the current substring
        int ans = 0; // Length of the longest substring
        int left = 0; // Left pointer for the sliding window
        
        for (int right = 0; right < s.size(); ++right) {
            // If the character has been seen and is within the current window
            while (mp[s[right]]) {
                // Move the left pointer to the right of the last occurrence of s[right]
                mp[s[left]] = false;
                left++;
            }
            
            // Mark the current character as seen
            mp[s[right]] = true;
            // Update the length of the current substring
            length = right - left + 1;
            // Update the maximum length
            ans = max(ans, length);
        }
        
        return ans;
    }
};
