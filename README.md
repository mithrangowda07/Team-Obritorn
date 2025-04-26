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
```

#### 🧾 Dependencies
Only standard C++ libraries are used:
1. `<iostream>` – For input/output operations.
2. `<fstream>` – For file handling (reading and writing files).
3. `<vector>` – For using dynamic arrays.
4. `<cmath>` – For mathematical functions (e.g., `sqrt`, `pow`).
5. `<algorithm>` – For algorithms like `next_permutation`, `reverse`.
6. `<limits>` – For constants like `numeric_limits<double>::max()`.
No additional installations or external libraries are required.


# Simulation

We built a 3D simulation using the Three.js library within the Next.js framework to visually represent the spacecraft navigating through the optimized path of waypoints. The simulation offers a dynamic view of how the path is traversed in 3D space, enhancing understanding of the optimization result.


https://github.com/user-attachments/assets/fcb0b776-e1fb-4d8a-9727-b7fb1df96632

#### How to Run the 3D Simulation Code

```bash
Install dependencies:
npm install

Start the development server:
npm run dev
```

Go to http://localhost:3000 to view the 3D simulation.

#### 📦 Dependencies

Package | Description
next@15.3.1 | React framework for server-side rendering, routing, and building web apps.
react@^19.0.0 | Core JavaScript library for building interactive UIs.
react-dom@^19.0.0 | Enables React components to be rendered into the DOM.
three@^0.176.0 | JavaScript 3D library to render interactive 3D content in the browser.

##### 🛠️ Dev Dependencies

Package | Description
@eslint/eslintrc@^3 | ESLint internal utility for managing shared config definitions.
@tailwindcss/postcss@^4 | Tailwind CSS plugin for integrating with PostCSS.
@types/node@^20 | TypeScript definitions for Node.js APIs.
@types/react@^19 | TypeScript definitions for React components and hooks.
@types/react-dom@^19 | TypeScript definitions for React DOM methods.
eslint@^9 | Linting tool for maintaining code quality and catching errors.
eslint-config-next@15.3.1 | Official ESLint configuration used in Next.js projects.
tailwindcss@^4 | Utility-first CSS framework for rapid UI development.
typescript@^5 | Superset of JavaScript adding strong typing and modern tooling features.
