#ifndef algo_h
#define algo_h

#include<functional>
#include<iostream>
#include<string>
#include<random>
#include<chrono>
#include<thread>
#include<vector>


// Defning handy macros
#define nanosec_sleep(s) std::this_thread::sleep_for(std::chrono::nanoseconds(s))
#define milisec_sleep(s) std::this_thread::sleep_for(std::chrono::milliseconds(s))
#define sec_sleep(s) std::this_thread::sleep_for(std::chrono::seconds(s))

// Structures
struct label {
    const char *name;
    const int x;
    const int y;
    const int size;
};

typedef void (*fn)(std::vector<int> &);

// Global Vars
extern const int algo_count;
extern bool IsThreadAlive;
extern bool IsAborted;
extern bool IsVectorSorted;
extern fn algo_defs[2];
extern std::vector<std::string> algo_types;

// Static Functions
static void ResetGlobalFlags(void);

// Functions
void swap(int &, int &);

bool IsSorted(std::vector<int> &);

void selection_sort(std::vector<int> &);

void bubble_sort(std::vector<int> &);

void insertion_sort(std::vector<int> &);

void merge_sort(std::vector<int> &);

#endif