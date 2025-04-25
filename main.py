import math

# Step 1: Read waypoints from file
waypoints = []
with open("waypoints.txt") as f:
    for line in f:
        id, x, y, z = map(float, line.strip().split())
        waypoints.append((int(id), x, y, z))

# Step 2: Compute distance matrix
N = len(waypoints)
dist = [[0.0] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        _, x1, y1, z1 = waypoints[i]
        _, x2, y2, z2 = waypoints[j]
        dist[i][j] = round(math.sqrt((x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2), 2)

# Step 3: Nearest Neighbor TSP (Approximate)
def nearest_neighbor():
    visited = [False] * N
    path = [0]  # Start from waypoint 1 (index 0)
    visited[0] = True
    current = 0
    total_cost = 0.0

    for _ in range(N - 1):
        nearest = None
        min_dist = float('inf')
        for j in range(N):
            if not visited[j] and dist[current][j] < min_dist:
                min_dist = dist[current][j]
                nearest = j
        path.append(nearest)
        visited[nearest] = True
        total_cost += dist[current][nearest]
        current = nearest

    # Return to start
    path.append(0)
    total_cost += dist[current][0]

    return path, round(total_cost, 2)

# Run the nearest neighbor algorithm
path, fuel_cost = nearest_neighbor()

# Map path indices to waypoint IDs
path_ids = [waypoints[i][0] for i in path]

# Output results
print("Nearest Neighbor Path:", path_ids)
print("Fuel Cost:", fuel_cost)

# Step 4: Save to path.txt
with open("path.txt", "w") as f:
    f.write(" ".join(map(str, path_ids)) + f" {fuel_cost:.2f}\n")
