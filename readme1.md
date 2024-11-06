# Open Sourcery 2022 and 2021 Batch - Week 1 Task Solution

This repository contains my solution for the **Open Sourcery Week 1 Task** for the 2022 and 2021 batch. The task involves finding the length of the longest substring without repeating characters in a given string.

---

## Problem Statement

Given a string `s`, find the length of the longest substring that contains no repeating characters.

### Examples
- **Example 1**
  - **Input**: `s = "abcabcbb"`
  - **Output**: `3`
  - **Explanation**: The answer is `"abc"`, with a length of `3`.

- **Example 2**
  - **Input**: `s = "bbbbb"`
  - **Output**: `1`
  - **Explanation**: The answer is `"b"`, with a length of `1`.

- **Example 3**
  - **Input**: `s = "pwwkew"`
  - **Output**: `3`
  - **Explanation**: The answer is `"wke"`, with a length of `3`. (Note that `"pwke"` is a subsequence and not a substring.)

### Constraints
- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.

---

## Solution

The solution is implemented in **C++**. It uses a sliding window technique with an unordered map to keep track of the indices of characters in the current substring.

### Approach

1. Traverse the string with a window defined by `start` and `end` indices.
2. Use an unordered map (`charIndexMap`) to store each character’s latest index.
3. If a character is found in the map and is within the current window, move `start` to one position after the last occurrence of that character.
4. Update `maxLength` to the length of the current substring (`end - start + 1`) whenever a longer substring is found.

### Code
Here’s the C++ code that solves the task:

```cpp
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
                start = max(start, charIndexMap[s[end]] + 1);
            }
            charIndexMap[s[end]] = end;
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
