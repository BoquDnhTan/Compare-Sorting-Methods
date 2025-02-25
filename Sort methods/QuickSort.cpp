#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// Median-of-three partition function for QuickSort
int partition(vector<double> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);
    swap(arr[mid], arr[high]); // Move median to end as pivot

    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(vector<double> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("QuickSortResult.out");
    outputFile << "QuickSortResult\n";

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
            quickSort(arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();

            // Print time taken
            duration<double, milli> elapsed = end - start;
            runningTimeSum[line] += elapsed.count();
            cout << "Line " << line << " done" << endl;
        }

        inputFile.close();
    }

    for (int i = 1; i <= 10; i++) {
        outputFile << runningTimeSum[i] / totalRunTime << '\n';
    }

    return 0;
}
