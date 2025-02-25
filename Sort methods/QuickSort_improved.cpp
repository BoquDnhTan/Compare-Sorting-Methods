#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

double medianOfThree(double a, double b, double c) {
    if ((a > b) != (a > c)) return a;  // a is the median if it is between b and c
    if ((b > a) != (b > c)) return b;  // b is the median if it is between a and c
    return c;  // Otherwise, c must be the median
}

int partition(vector<double> &arr, int left, int right) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(left, right);

    int idx1 = dist(gen), idx2 = dist(gen), idx3 = dist(gen);
    double pivot = medianOfThree(arr[idx1], arr[idx2], arr[idx3]);

    int i = left - 1, j = right + 1;
    while (true) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

// Improved QuickSort with median-of-three pivot selection
void quickSort(vector<double> &arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("QuickSortResult_improved.out");
    outputFile << "QuickSortResult_improved\n";

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

            // Sort using improved QuickSort and measure time
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
        outputFile << fixed << setprecision(3) << runningTimeSum[i] / totalRunTime << " ms\n";
    }

    return 0;
}
