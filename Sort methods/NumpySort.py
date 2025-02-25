import numpy as np
import time

# Constants
TOTAL_RUNS = 10
LINES = 10
NUMBERS_PER_LINE = int(1e6)
input_filename = "input.inp"
output_filename = "NumPySortResult.out"

# Initialize timing storage
running_time_sum = np.zeros(LINES)

for epoch in range(1, TOTAL_RUNS + 1):
    try:
        with open(input_filename, "r") as inputFile:
            print(f"Epoch {epoch}")
            for line in range(LINES):
                # Read 1,000,000 numbers into NumPy array
                data = np.fromfile(inputFile, count=NUMBERS_PER_LINE, sep=" ")

                # Sort using NumPy's sort() and measure time
                start_time = time.time()
                np.sort(data)  # NumPy's optimized sorting
                end_time = time.time()

                # Store elapsed time in milliseconds
                elapsed_time = (end_time - start_time) * 1000
                running_time_sum[line] += elapsed_time

                print(f"Line {line + 1} done")
    except FileNotFoundError:
        print("Error: Cannot open input file.")
        exit(1)

# Write average sorting times to output file
with open(output_filename, "w") as outputFile:
    outputFile.write("NumPySortResult\n")
    for avg_time in running_time_sum / TOTAL_RUNS:
        outputFile.write(f"{avg_time:.3f} ms\n")

print("Sorting completed and results saved.")
