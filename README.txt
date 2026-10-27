RAM RESCUE — MEMORY CRISIS SIMULATOR
=====================================
OSY Mini-Project | C++17 | Console Application

FILES
- main.cpp: complete C++ source code
- REPORT.md: project report draft
- README.txt: setup and test instructions

HOW TO RUN
1. Open an online C++ compiler.
2. Select C++17 (C++14 should also work).
3. Paste main.cpp into the editor and click Run.
4. Enter simulated RAM size, e.g. 1024.
5. Use the menu to allocate/release memory, view the memory map, and view status.

QUICK TEST
Enter RAM size 1024. Choose option 1, process name Browser, memory 300.
Choose option 3 to view the map: Browser should occupy 300 MB and 724 MB should remain free.
Choose option 2 and release Browser. The memory should become free again.

NOTES
- This simulates memory; it does not inspect or modify actual computer RAM.
- Uses First Fit allocation.
- Memory is stored only while the program runs.
- Enter process names without spaces.
