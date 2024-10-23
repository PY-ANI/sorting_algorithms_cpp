#include "algos.h"

// globals
bool IsAborted = 0;
bool IsThreadAlive = 0;
bool IsVectorSorted = 0;
const int algo_count = 3;
fn algo_defs[algo_count] = {
    selection_sort,
    bubble_sort,
    insertion_sort
};

std::vector<std::string> algo_types = {
    "Selection Sort",
    "Bubble Sort",
    "Insertion Sort",
    "Merge Sort"
};

// Static Functions
static void ResetGlobalFlags(void){
    if (IsAborted){
        IsAborted=0;
    }
    else{
        IsVectorSorted = 1;
    }
    IsThreadAlive = 0;
} 

// functions
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

bool IsSorted(std::vector<int> &vec){
    int prev = vec[0];
    for (int i:vec){
        if (prev > i){
            std::cout<<prev<<" "<<i<<"\n";
            return false;
        }
        prev = i;
    }
    return true;
}

void selection_sort(std::vector<int> &vec){
    const int length = vec.size();
    for (int i=0; i < length; i++){
        if (IsAborted) break;
        int ele_index = i;
        for (int j=i+1; j < length; j++){
            if(vec[ele_index] > vec[j]){
                if (IsAborted) break;
                nanosec_sleep(500);
                ele_index = j;
            }
        }
        
        nanosec_sleep(500);
        swap(vec[i], vec[ele_index]);
    }
    ResetGlobalFlags();
}

void bubble_sort(std::vector<int> &vec){
    const int length = vec.size();
    bool HasSwapped = 0;
    for (int i = 0; i < length-1; i++){
        if(IsAborted) break;
        HasSwapped = 0;
        for (int j = 0; j < length-i-1; j++){
            if(IsAborted) break;
            if (vec[j] > vec[j+1]){
                HasSwapped = 1;
                nanosec_sleep(500);
                swap(vec[j], vec[j+1]);
            }
        }
        if(!HasSwapped) break;
    }
    ResetGlobalFlags();
}

void insertion_sort(std::vector<int> &vec){
    // log("Yes");
    const int length = vec.size();
    for (int i = 1; i < length; i++){
        if(IsAborted) break;
        int j = i-1, key = vec[i];
        while (j >= 0 && vec[j] > key){
            if(IsAborted) break;
            nanosec_sleep(500);
            vec[j+1] = vec[j];
            j--;
        }
        nanosec_sleep(500);
        vec[j+1] = key;
    }
    ResetGlobalFlags();
}