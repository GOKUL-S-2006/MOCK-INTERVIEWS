#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;          // number -> frequency
    map<int, set<int>> freqToNums;         // frequency -> set of numbers with that frequency

    int left = 0, right = 0;

    while (right < n) {
        int num = arr[right];

        // Remove num from old frequency set
        int oldFreq = freq[num];
        if (oldFreq > 0) {
            freqToNums[oldFreq].erase(num);
            if (freqToNums[oldFreq].empty()) {
                freqToNums.erase(oldFreq);
            }
        }

        // Add num to new frequency set
        freq[num]++;
        freqToNums[freq[num]].insert(num);

        // Check if window is full
        if (right - left + 1 == k) {
            // Get the mode: highest frequency and smallest number
            int maxFreq = freqToNums.rbegin()->first;
            int mode = *freqToNums[maxFreq].begin();  // smallest number with max frequency
            cout << mode << " ";

            // Remove arr[left] as window will slide
            int removeNum = arr[left];
            int removeFreq = freq[removeNum];

            freqToNums[removeFreq].erase(removeNum);
            if (freqToNums[removeFreq].empty()) {
                freqToNums.erase(removeFreq);
            }

            freq[removeNum]--;
            if (freq[removeNum] > 0) {
                freqToNums[freq[removeNum]].insert(removeNum);
            } else {
                freq.erase(removeNum);
            }

            left++;  // move window forward
        }

        right++;
    }

    return 0;
}
