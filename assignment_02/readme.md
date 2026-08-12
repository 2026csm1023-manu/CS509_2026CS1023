# Assignment 02 - Graph Algorithms

## Objective

Implement and compare Bellman-Ford and Floyd-Warshall shortest path algorithms.

Bellman-Ford uses a CSR graph representation, while Floyd-Warshall uses a dense distance matrix.

## Algorithm / Approach

- Bellman-Ford computes single-source shortest paths using edge relaxation.
- Floyd-Warshall computes all-pairs shortest paths using dynamic programming.
- Bellman-Ford uses adjacency-list input which is converted to CSR before the algorithm runs.
- CSR conversion is treated as preprocessing and is not included in the reported execution time.
- Both algorithms perform negative-cycle detection.

## Input Format

### Bellman-Ford

The input contains the number of vertices and edges, followed by the adjacency list and source vertex.

### Floyd-Warshall

The input contains the number of vertices followed by the distance matrix.

INF represents an unreachable vertex.

## Compilation and Execution

Compile the project using the provided build setup and run:

./assignment2

The assignment can also be executed using:

./comman_wrapper/wrapper

## Test Cases and Results

### Bellman-Ford

| Test File | Vertices | Execution Time | Negative Cycle | Status |
|-----------|----------|----------------|----------------|--------|
| bellman_10 | 10 | 0.0172 ms | No | Pass |
| bellman_100 | 100 | 1.0747 ms | No | Pass |
| bellman_10000 | 10,000 | 11753.3 ms | No | Pass |
| bellman_50000 | 50,000 | 392904 ms | No | Pass |
| bellman_100000 | 100,000 | > 5 min | Not completed | Not completed |

The bellman_100000 test was stopped after running for more than 5 minutes and therefore no execution time was recorded.

### Floyd-Warshall

| Test File | Vertices | Execution Time | Negative Cycle | Status |
|-----------|----------|----------------|----------------|--------|
| floyd_10 | 10 | 0.0219 ms | No | Pass |
| floyd_100 | 100 | 18.9238 ms | No | Pass |
| floyd_500 | 500 | 2182.28 ms | No | Pass |
| floyd_1000 | 1,000 | 17102.2 ms | No | Pass |
| floyd_2000 | 2,000 | 134194 ms | No | Pass |

## Complexity

- Bellman-Ford: O(V × E)
- Floyd-Warshall: O(V³)
- CSR conversion: O(V + E)
- Floyd-Warshall space complexity: O(V²)

## References

CS509 Assignment Guidelines