#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.length(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                // Move the start position to the right of the previous index of the repeated character
                start = max(start, charIndexMap[s[end]] + 1);
            }
            // Update the character's index in the map
            charIndexMap[s[end]] = end;
            // Calculate the length of the current substring
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    int result = solution.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    
    return 0;
}