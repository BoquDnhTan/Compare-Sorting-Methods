import numpy as np
import matplotlib.pyplot as plt

# Sorting methods and their corresponding runtimes
methods = ["QuickSort", "HeapSort", "MergeSort", "C++ sort()", "NumPy sort()"]

# Updated data for each method (order: QuickSort -> HeapSort -> MergeSort -> C++ sort -> NumPy sort)
runtimes = [
    [16.3888, 37.2482, 80.7479, 80.3387, 84.0643, 83.7631, 312.89, 81.8626, 81.5749, 79.1131],  # QuickSort (Updated)
    [81.090, 87.258, 274.448, 238.588, 246.903, 232.831, 187.729, 206.155, 198.284, 205.817],  # HeapSort
    [183.972, 193.994, 272.749, 278.33, 273.913, 280.995, 238.87, 274.505, 278.232, 269.02],  # MergeSort
    [17.089, 13.863, 75.776, 77.585, 75.117, 74.181, 47.041, 74.423, 75.663, 75.625],  # C++ sort()
    [13.899, 13.238, 14.065, 13.294, 13.505, 12.335, 7.074, 13.479, 13.307, 13.743],  # NumPy sort()
]

# Number of tests
num_tests = len(runtimes[0])

# Split tests into two rows: first 5 and last 5
fig, axes = plt.subplots(2, 1, figsize=(14, 10))  # Larger figure size

# Softer pastel colors for each sorting method
colors = ['#FFADAD', '#FFC3A0', '#FFDAC1', '#B5EAD7', '#A0E7E5']

# Bar width
bar_width = 0.15

for row in range(2):  # Loop over two rows
    ax = axes[row]
    start_idx = row * 5
    end_idx = start_idx + 5
    x = np.arange(5)  # X-axis positions (5 tests per row)

    for i, method in enumerate(methods):
        bars = ax.bar(x + i * bar_width, runtimes[i][start_idx:end_idx], bar_width, label=method, color=colors[i])
        
        # Add labels on top of each bar
        for bar in bars:
            height = bar.get_height()
            ax.text(bar.get_x() + bar.get_width() / 2, height, f'{height:.1f}', ha='center', va='bottom', fontsize=10)

    # Labels and title for each row
    ax.set_ylabel("Runtime (ms)", fontsize=12)
    ax.set_title(f"Sorting Algorithm Performance (Tests {start_idx+1} - {end_idx})", fontsize=14, fontweight='bold')
    ax.set_xticks(x + bar_width * 2)
    ax.set_xticklabels([f"Test {i+1}" for i in range(start_idx, end_idx)], fontsize=11)
    ax.legend(fontsize=10)

# Adjust layout for better spacing
plt.tight_layout()
plt.show()
