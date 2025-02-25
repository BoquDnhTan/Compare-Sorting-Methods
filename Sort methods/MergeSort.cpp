#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// Merge function for mergeSort
void merge(vector<double> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<double> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// MergeSort function
void mergeSort(vector<double> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("MergeSortResult.out");
    outputFile << "MergeSortResult\n";

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
            mergeSort(arr, 0, arr.size() - 1);
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
