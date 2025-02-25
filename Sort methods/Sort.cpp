#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("STLSortResult.out");
    outputFile << "STLSortResult\n";

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

            // Sort using STL sort() and measure time
            auto start = high_resolution_clock::now();
            sort(arr.begin(), arr.end());
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
