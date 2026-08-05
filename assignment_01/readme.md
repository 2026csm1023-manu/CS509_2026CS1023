# Assignment 01 - GEMM

## Objective
Implement and compare Simple GEMM and Blocking GEMM for matrix multiplication.

## Algorithm / Approach
- Simple GEMM uses standard matrix multiplication.
- Blocking GEMM divides matrices into smaller blocks to improve cache usage.
- Block size used: 32.

## Input Format
Input contains matrix dimensions followed by matrices A and B.

## Compilation and Execution
```bash
g++ driver/driver.cpp driver/timer.cpp src/gemm.cpp src/blocking_gemm.cpp -o gemm_driver


```bash
./gemm_driver
```

## Test Cases and Results

| Test File | Input Size | Expected Output | Actual Output | Simple Time | Blocking Time | Block Size | Status |
|---|---|---|---|---:|---:|---:|---|
| gemm_test_01.txt | 2×2 | Result matrix | Result matrix | 0.0006 ms | 0.0007 ms | 32 | Pass |
| gemm_test_02.txt | 8×8 | Result matrix | Result matrix | 0.0112 ms | 0.0168 ms | 32 | Pass |
| gemm_large_01.txt | 128×128 | Result matrix | Result matrix | 37.6303 ms | 39.3727 ms | 32 | Pass |
| gemm_large_02.txt | 256×256 | Result matrix | Result matrix | 288.618 ms | 335.140 ms | 32 | Pass |
| gemm_large_03.txt | 1024×1024 | Result matrix | Result matrix | 22514.1 ms | 21837.8 ms | 32 | Pass |

## Complexity
- Simple GEMM: O(n³)
- Blocking GEMM: O(n³)

## References
CS509 Assignment Guidelines