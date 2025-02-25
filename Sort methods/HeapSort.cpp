#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// Heapify function to maintain max-heap property
void heapify(vector<double> &arr, int n, int i) {
    int largest = i; // Root node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) 
        largest = left;

    if (right < n && arr[right] > arr[largest]) 
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// HeapSort function
void heapSort(vector<double> &arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("HeapSortResult.out");
    outputFile << "HeapSortResult\n";

    vector<double> runningTimeSum(11);

    const int totalRunTime = 10;
    for (int epoch = 1; epoch <= totalRunTime; epoch++) {
        ifstream inputFile("input.inp");
        if (!inputFile) {
            cerr << "Error: Cannot open input file.\n";
            return 1;
        }

        cout << "Epoch " << epoch << endl;
        for (int line = 1; line <= 10; ++line) {
            vector<double> arr;
            double num;

            // Read 1,000,000 numbers into vector
            for (int i = 0; i < 1e6; i++) {
                if (!(inputFile >> num)) {
                    cerr << "Error: Not enough numbers in input file.\n";
                    return 1;
                }
                arr.push_back(num);
            }

            // Sort and measure time
            auto start = high_resolution_clock::now();
            heapSort(arr);
            auto end = high_resolution_clock::now();

            // Print time taken
            duration<double, milli> elapsed = end - start;
            runningTimeSum[line] += elapsed.count();
            cout << "Line " << line << " done" << endl;
        }

        inputFile.close();
    }

    for (int i = 1; i <= 10; i++) {
        outputFile << fixed << setprecision(3) << runningTimeSum[i] / totalRunTime << '\n';
    }

    return 0;
}
