using namespace std;
#include <iostream>
#include <vector>

template<typename T>
int recursive_last(const vector<T>& items, const T& target, size_t pos_last) {
    if (pos_last == -1) { //returns if target is not in vector
        return -1;
    }

    if (items[pos_last] == target) {
        return pos_last;
    }
    else {
        return recursive_last(items, target, pos_last - 1);
    }
}

template<typename T>
int last_occurrence(const vector<T>& items, const T& target) {
    return recursive_last(items, target, items.size() - 1);
}

int main() {
    vector<int> items = { 1, 2, 3, 4, 2, 5, 3 }; //creates list
    int target = 2; //sets target
    int last_index = last_occurrence(items, target); //finds index of last occurrence
    if (last_index != -1) {
        cout << "Last occurrence of " << target << " is at index " << last_index << endl;
    }
    else { //runs if target is not in vector
        cout << target << " not found in the vector" << endl;
    }
    return 0;
}
