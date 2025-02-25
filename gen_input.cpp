#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Function to generate a random double in range [low, high]
double randomDouble(mt19937_64 &rng, double low, double high) {
    uniform_real_distribution<double> dist(low, high);
    return dist(rng);
}

// Function to generate a random int in range [low, high]
int64_t randomInt(mt19937_64 &rng, int64_t low, int64_t high) {
    uniform_int_distribution<int64_t> dist(low, high);
    return dist(rng);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream outputFile("input.inp");
    if (!outputFile) {
        cerr << "Error: Cannot open output file.\n";
        return 1;
    }

    mt19937_64 rng(random_device{}()); // 64-bit random number generator

    for (int line = 1; line <= 10; ++line) {
        if (line == 1) { 
        	vector<double> arr(1e6);
            // First line: Sorted in ascending order
            for (int i = 0; i < 1e6; i++) arr[i] = randomDouble(rng, -1e18, 1e18);
            sort(arr.begin(), arr.end());
        	for (auto x : arr) {
        		outputFile << x << ' ';
        	}
        	outputFile << '\n';
        } 
        else if (line == 2) {
        	vector<double> arr(1e6);
            // Second line: Sorted in descending order
            for (int i = 0; i < 1e6; i++) arr[i] = randomDouble(rng, -1e18, 1e18);
            sort(arr.begin(), arr.end(), greater<double>());
        	for (auto x : arr) {
        		outputFile << x << ' ';
        	}
        	outputFile << '\n';
        } 
        else if (line == 3) {
            // Third line: Only int
            for (int i = 0; i < 1e6; i++) {
            	outputFile << randomInt(rng, -1e9, 1e9) << ' ';
            }
            outputFile << '\n';
        }
        else if (line == 4) {
            // Fourth line: Only int64_t
            for (int i = 0; i < 1e6; i++) {
            	outputFile << randomInt(rng, -1e18, 1e18) << ' ';
            }
            outputFile << '\n';
        }
        else if (line == 5) {
            // Fifth line: Only real numbers (double)
            for (int i = 0; i < 1e6; i++) {
            	outputFile << randomDouble(rng, -1e18, 1e18) << ' ';
            }
            outputFile << '\n';
        }
        else if (line == 6) {
        	// Sixth line: Small int
        	for (int i = 0; i < 1e6; i++) {
            	outputFile << randomInt(rng, 0, 1e6) << ' ';
            }
            outputFile << '\n';
        } else if (line == 7) {
        	// Seventh line: Smaller int
        	for (int i = 0; i < 1e6; i++) {
            	outputFile << randomInt(rng, 0, 1e3) << ' ';
            }
            outputFile << '\n';
        }
        else if (line == 8) {
        	// Eighth line: Small real numbers (double)
            for (int i = 0; i < 1e6; i++) {
            	outputFile << randomDouble(rng, -1e6, 1e6) << ' ';
            }
            outputFile << '\n';
        }
        else {
            // Mix of int, int64_t, and double
            for (int i = 0; i < 1e6; i++) {
                int type = randomInt(rng, 0, 2); // Choose number type: int, int64_t, or double

                if (!type) {
                	outputFile << randomDouble(rng, -1e18, 1e18) << ' ';
                }
                else {
                	ll x = randomInt(rng, -1e9, 1e9);
                	if (type == 1) {
                		x = randomInt(rng, -1e18, 1e18);
                	}
                	outputFile << x << ' ';
                }
			}
			outputFile << '\n';                
        }

        cout << "Line " << line << " generated.\n";
    }

    outputFile.close();
    cout << "File input.inp generated successfully.\n";
    return 0;
}
