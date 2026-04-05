#include <iostream>
#include <vector>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using namespace std;

// Stalin Sort: removes elements that break non‑decreasing order
void stalinSort(vector<int>& vec) {
    if (vec.empty()) return;

    int left_index = 1;   // first element (vec[0]) always survives

    for (int next_index = 1; next_index < vec.size(); next_index++) {
        // Compare current element with the last kept element
        if (vec[next_index] >= vec[left_index - 1]) {
            // Loyal – keep it in place
            vec[left_index] = vec[next_index];
            left_index++;
        }
        else {
            // Enemy of order – execute (print and discard)
            cout << vec[next_index] << ": shoot" << endl;
        }
    }
    // Resize to the number of survivors
    vec.resize(left_index);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int N;
    cout << "Enter size: ";
    cin >> N;

    vector<int> data(N);

    cout << "Original array: (";
    for (int i = 0; i < N; i++) {
        data[i] = rand() % 201;   // random numbers from 0 to 200
        cout << data[i] << " ";
    }
    cout << ")" << endl;

    stalinSort(data);

    cout << "\nAfter Stalin sort: (";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << ")" << endl;

    return 0;
}