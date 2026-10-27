# RAM Rescue: Memory Crisis Simulator

## 1. Abstract
RAM Rescue is a C++ console-based mini-project that simulates basic operating-system memory management. It allows users to allocate memory to named processes, release allocated memory, inspect a memory map, and view total, used, and available memory. It displays a low-memory warning when available memory is at or below 25% of total memory.

## 2. Introduction
An operating system manages main memory so programs can execute. RAM Rescue provides an interactive model of memory allocation and deallocation.

## 3. Problem Statement
Memory allocation and fragmentation can be difficult to visualize. This project models memory as a sequence of blocks and shows how process requests change the memory layout.

## 4. Objectives
- Simulate memory allocation and deallocation.
- Display occupied and free memory blocks.
- Report total, used, and available RAM.
- Demonstrate First Fit allocation.
- Merge adjacent free blocks after deallocation.

## 5. Requirements
Hardware: A computer capable of running a modern browser or C++ compiler.
Software: Online or local C++ compiler.
Language: C++14 or later; C++17 recommended.

## 6. Operating System Concepts
- Memory allocation and deallocation
- First Fit allocation
- Free and occupied memory blocks
- External fragmentation
- Merging adjacent free blocks

## 7. Data Structures Used
- `struct Block`: stores start position, size, free/used status, and process name.
- `vector<Block>`: stores blocks and allows blocks to be inserted or removed when memory is split or merged.

## 8. Algorithms
### First Fit Allocation
1. Read process name and requested memory size.
2. Scan blocks from the beginning.
3. Select the first free block large enough.
4. Mark the requested portion as occupied.
5. If the block is larger than needed, create a remaining free block.
6. If no suitable block exists, report failure.

### Deallocation
1. Read the process name.
2. Mark its allocated block(s) as free.
3. Merge adjacent free blocks.
4. Display updated status.

## 9. Time Complexity
Let `n` be the number of memory blocks.
- Allocation search: O(n) worst case.
- Memory map display: O(n).
- System status calculation: O(n).
- Releasing a process requires scanning blocks in O(n), plus possible vector-shift costs of O(n).

## 10. Testing
Run these tests and record actual results:
1. Enter valid RAM size such as 1024 MB.
2. Allocate 300 MB to `Browser`; expect 300 MB used and 724 MB available.
3. View the memory map; expect one used block and one free block.
4. Release `Browser`; expect all 1024 MB to be free.
5. Request more memory than any free block; expect allocation failure.
6. Enter a non-positive RAM size; expect an error message.

## 11. Advantages
- Simple menu-driven interface.
- Demonstrates a core OS concept.
- Shows memory changes immediately.
- Can be compiled in an online C++ environment.

## 12. Limitations
- Simulates memory rather than managing actual RAM.
- Models contiguous memory blocks, not paging or virtual memory.
- Data is not saved after the program ends.
- Process names should be entered without spaces.

## 13. Future Enhancements
- Add Best Fit and Worst Fit algorithms.
- Add a graphical memory map.
- Save simulation logs to a file.
- Add paging and page-replacement demonstrations.

## 14. Conclusion
RAM Rescue demonstrates memory allocation and release using First Fit. It helps learners visualize occupied/free blocks, memory usage, and fragmentation in an interactive C++ program.

## 15. References
- C++ reference: https://en.cppreference.com/
- Operating Systems course notes and textbooks used in class.
