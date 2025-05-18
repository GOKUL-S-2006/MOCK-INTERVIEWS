#include <unordered_map>
#include <string>
using namespace std;

class Solution {
 public:
  bool canConstruct(string s, int k) {
    // If s has fewer characters than k, it's impossible to make k non-empty palindromes.
    if (s.length() < k)
      return false;

    unordered_map<char, int> freq;

    // Count frequency of each character
    for (char c : s) {
      freq[c]++;
    }

    // Count how many characters have odd frequency
    int oddCount = 0;
    for (const auto& pair : freq) {
      if (pair.second % 2 != 0)
        oddCount++;
    }

    // We need at least 'oddCount' palindromes
    return oddCount <= k;
  }
};
