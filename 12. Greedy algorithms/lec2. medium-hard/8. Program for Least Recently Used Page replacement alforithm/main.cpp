// https://www.geeksforgeeks.org/program-for-least-recently-used-lru-page-replacement-algorithm/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

int LRU_Page_Replacement(vector<int>& pages, int capacity) {
    unordered_set<int> memory;  // Set to store current pages
    unordered_map<int, list<int>::iterator> page_map;  // Map page to its position in list
    list<int> lru_list;  // Doubly linked list for LRU order
    int page_faults = 0;

    for (int page : pages) {
        // Page Hit
        if (memory.find(page) != memory.end()) {
            // Move the accessed page to front (most recently used)
            lru_list.erase(page_map[page]);
            lru_list.push_front(page);
            page_map[page] = lru_list.begin();
        }
        // Page Miss
        else {
            page_faults++;

            // If memory is full, remove LRU page
            if (memory.size() == capacity) {
                int lru_page = lru_list.back();
                lru_list.pop_back();
                memory.erase(lru_page);
                page_map.erase(lru_page);
            }

            // Insert new page
            lru_list.push_front(page);
            memory.insert(page);
            page_map[page] = lru_list.begin();
        }
    }

    return page_faults;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4};
    int frames = 3;

    int faults = LRU_Page_Replacement(pages, frames);

    cout << "Total Page Faults: " << faults << endl;

    return 0;
}
