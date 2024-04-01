using namespace std;
#include <iostream>
#include <vector>

void insertion_sort(vector<int>& num) {
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < num[i]) {
                num[i + 1] = num[i]; // larger values move right
                insertionNeeded = true;
            }
            else {
                break;
            }
        }
        if (insertionNeeded) {
            num[i + 1] = key; // Put key into its proper location
        }
    }
}

int main() {
    // Creates list of integers
    vector<int> nums = { 4, 2, 8, 1, 9, 3 };

    // Sorts the list
    insertion_sort(nums);

    // Prints the list
    cout << "Sorted list:" << endl;
    for (const auto& element : nums) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
