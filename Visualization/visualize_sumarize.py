import numpy as np
import matplotlib.pyplot as plt

# Sorting methods and their mean runtimes
methods = ["QuickSort (Improved)", "HeapSort", "MergeSort", "C++ sort()", "NumPy sort()"]
runtimes = [
    [16.3888, 37.2482, 80.7479, 80.3387, 84.0643, 83.7631, 312.89, 81.8626, 81.5749, 79.1131],  
    [81.090, 87.258, 274.448, 238.588, 246.903, 232.831, 187.729, 206.155, 198.284, 205.817],  
    [183.972, 193.994, 272.749, 278.33, 273.913, 280.995, 238.87, 274.505, 278.232, 269.02],  
    [17.089, 13.863, 75.776, 77.585, 75.117, 74.181, 47.041, 74.423, 75.663, 75.625],  
    [13.899, 13.238, 14.065, 13.294, 13.505, 12.335, 7.074, 13.479, 13.307, 13.743],  
]

# Compute mean values
mean_runtimes = [np.mean(times) for times in runtimes]

# Define cute colors
colors = ['#FFADAD', '#FFC3A0', '#FFDAC1', '#B5EAD7', '#A0E7E5']

# Plot the chart
plt.figure(figsize=(10, 6))
bars = plt.bar(methods, mean_runtimes, color=colors, edgecolor="black")

# Add values inside the bars, adjusting position dynamically
for bar in bars:
    height = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, height * 0.95,  # Adjust text inside the bar
             f"{height:.2f} ms", ha='center', va='top', fontsize=12, color="black", fontweight="bold")

# Title and labels
plt.title("Mean Sorting Time Comparison", fontsize=14, fontweight="bold")
plt.ylabel("Mean Time (ms)", fontsize=12)
plt.xticks(rotation=15, fontsize=11)

# Show the plot
plt.show()
