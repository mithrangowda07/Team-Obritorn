# 🚀 Space Mission Fuel Optimizer

## 👥 Team Information
- **Team Name:** Orbitron  
- **Team ID:** 2 
- **Team Members:**
  - Bharath Kumar M S  
  - Florence Solomon  
  - Mithra N Gowda  
  - Moulya K R  
- **Guide:** Ananth Mallya  
- **Institution:** KVG College of Engineering, Sullia

---

## 🧩 Problem Statement

**Problem Number & Title:**  
**Space Mission Fuel Optimizer**

Efficient fuel usage is crucial in space missions. The objective of this challenge is to determine the shortest path through a sequence of waypoints in 3D space to minimize total fuel consumption. The fuel cost between waypoints is directly proportional to the Euclidean distance traveled. This is modeled as a Traveling Salesman Problem (TSP).

---

## 🛠️ How to Run the Code

### 1. Requirements
Ensure you have a C++ compiler installed (e.g., `g++`).

### 2. Prepare the Input File
Create a file named `waypoints.txt` in the same directory as the code. Each line should represent a 3D waypoint in the following format:


### 3. Compile the Code
Use the following command to compile:

```bash
g++ tsp_solver.cpp -o tsp_solver

./tsp_solver

### Sample Input 

Format :- <id> <x> <y> <z>

### Sample Output

Format :- 0 1 2 0 5.19


### Testcase 1

Input:
1 0.0 0.0 0.0
2 150.0 0.0 0.0
3 0.0 150.0 0.0
4 0.0 0.0 150.0
5 100.0 100.0 100.0
6 -150.0 0.0 0.0
7 0.0 -150.0 0.0
8 -100.0 -100.0 -100.0
9 200.0 200.0 0.0
10 -200.0 -200.0 200.0

Output:
1 6 8 7 10 4 5 2 9 3 1 1886.77