#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Block {
    int start, size;
    bool free;
    string processName;
};

class MemoryManager {
    int totalMemory;
    vector<Block> blocks;

public:
    explicit MemoryManager(int memory) : totalMemory(memory) {
        blocks.push_back({0, memory, true, ""});
    }

    void showStatus() const {
        int used = 0;
        for (const Block& b : blocks)
            if (!b.free) used += b.size;

        cout << "\n--- SYSTEM STATUS ---\n"
             << "Total RAM: " << totalMemory << " MB\n"
             << "Used RAM: " << used << " MB\n"
             << "Available RAM: " << totalMemory - used << " MB\n";

        if (totalMemory - used <= totalMemory / 4)
            cout << "WARNING: Low memory! Available RAM is 25% or less.\n";
    }

    void showMemoryMap() const {
        cout << "\n--- MEMORY MAP ---\n"
             << left << setw(12) << "Start (MB)"
             << setw(12) << "Size (MB)"
             << setw(14) << "Status" << "Process\n"
             << string(48, '-') << "\n";

        for (const Block& b : blocks)
            cout << left << setw(12) << b.start
                 << setw(12) << b.size
                 << setw(14) << (b.free ? "FREE" : "USED")
                 << (b.free ? "-" : b.processName) << "\n";
    }

    void allocateMemory() {
        string name;
        int amount;
        cout << "Enter process name (no spaces): ";
        cin >> name;
        cout << "Enter memory required in MB: ";

        if (!(cin >> amount) || amount <= 0) {
            cout << "Invalid memory amount.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return;
        }

        // First Fit: choose the first suitable free block.
        for (size_t i = 0; i < blocks.size(); ++i) {
            if (blocks[i].free && blocks[i].size >= amount) {
                Block old = blocks[i];
                blocks[i] = {old.start, amount, false, name};
                if (old.size > amount)
                    blocks.insert(blocks.begin() + i + 1,
                                  {old.start + amount, old.size - amount, true, ""});
                cout << "Allocated " << amount << " MB to " << name << " using First Fit.\n";
                showStatus();
                return;
            }
        }

        cout << "Allocation failed: no single free block is large enough.\n";
        cout << "This may be due to insufficient memory or fragmentation.\n";
    }

    void releaseMemory() {
        string name;
        cout << "Enter process name to release: ";
        cin >> name;
        bool found = false;

        for (Block& b : blocks) {
            if (!b.free && b.processName == name) {
                b.free = true;
                b.processName = "";
                found = true;
            }
        }

        if (!found) {
            cout << "No allocated process found with that name.\n";
            return;
        }

        // Merge adjacent free blocks.
        for (size_t i = 0; i + 1 < blocks.size();) {
            if (blocks[i].free && blocks[i + 1].free) {
                blocks[i].size += blocks[i + 1].size;
                blocks.erase(blocks.begin() + i + 1);
            } else {
                ++i;
            }
        }

        cout << "Memory released for " << name << ". Adjacent free blocks merged where possible.\n";
        showStatus();
    }
};

int main() {
    int totalMemory;
    cout << "===== RAM RESCUE: MEMORY CRISIS SIMULATOR =====\n";
    cout << "Enter total simulated RAM in MB (e.g. 1024): ";
    if (!(cin >> totalMemory) || totalMemory <= 0) {
        cout << "Invalid RAM size. Restart and enter a positive number.\n";
        return 0;
    }

    MemoryManager manager(totalMemory);
    int choice;

    do {
        cout << "\n========== RAM RESCUE MENU ==========\n"
             << "1. Allocate memory to a process\n"
             << "2. Release process memory\n"
             << "3. View memory map\n"
             << "4. View system status\n"
             << "0. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a menu number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: manager.allocateMemory(); break;
            case 2: manager.releaseMemory(); break;
            case 3: manager.showMemoryMap(); break;
            case 4: manager.showStatus(); break;
            case 0: cout << "RAM Rescue closed. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
