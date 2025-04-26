
import matplotlib.pyplot as plt
import numpy as np

# Theoretical time complexities
def brute_force_time_complexity(n):
    return np.math.factorial(n)  # Factorial time complexity (n!)

def dynamic_programming_time_complexity(n):
    return (2 ** n) * n  # Approximate DP complexity

def nearest_neighbor_time_complexity(n):
    return n ** 2  # Nearest neighbor is approximately O(n^2)

# Generate data
num_waypoints = range(2, 21)  # Number of waypoints (2 to 14)
brute_force_times = [brute_force_time_complexity(n) for n in num_waypoints]
dynamic_programming_times = [dynamic_programming_time_complexity(n) for n in num_waypoints]
nearest_neighbor_times = [nearest_neighbor_time_complexity(n) for n in num_waypoints]

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(num_waypoints, brute_force_times, label="Brute Force", marker="o")
plt.plot(num_waypoints, dynamic_programming_times, label="Dynamic Programming", marker="s")
plt.plot(num_waypoints, nearest_neighbor_times, label="Nearest Neighbor", marker="^")

# Logarithmic scaling for better visibility
plt.yscale("log")
plt.xlabel("Number of Waypoints")
plt.ylabel("Time Complexity (log scale)")
plt.title("Comparison of TSP Algorithm Time Complexities")
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.tight_layout()

# Show the plot
plt.show()
