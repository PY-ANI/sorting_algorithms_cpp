#include "algos.h"

// globals
bool IsAborted = 0;
bool IsThreadAlive = 0;
bool IsVectorSorted = 0;
const int algo_count = 4;

fn algo_defs[algo_count] = {
    selection_sort,
    bubble_sort,
    insertion_sort,
    merge_sort
};

std::vector<std::string> algo_types = {
    "Selection Sort",
    "Bubble Sort",
    "Insertion Sort",
    "Merge Sort"
};

// static vars
static int sleep_time = 600;

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

static void merge(std::vector<int> &vec, int high, int mid, int low){
    if (IsAborted) return;

    int n1 = mid - low + 1 ,n2 = high - mid;
    int i = 0, j = 0, k = low;

    std::vector<int> left_vec(vec.begin()+low, vec.begin()+(low+n1)), right_vec(vec.begin()+(mid+1), vec.begin()+(mid+1+n2));

    while( (i < n1) && (j < n2) ){
        nanosec_sleep(sleep_time);
        if(left_vec[i] > right_vec[j]){
            vec[k++]=right_vec[j++];
        }
        else{
            vec[k++]=left_vec[i++];
        }
    }

    while (i < n1){
        nanosec_sleep(sleep_time);
        vec[k++] = left_vec[i++];
    }

    while (j < n2){
        nanosec_sleep(sleep_time);
        vec[k++] = right_vec[j++];
    }
}

static void merge_sort_subsection(std::vector<int> &vec, int high, int low){
    if ((high > low) && !IsAborted){

        int mid = low+(high-low)/2;
        merge_sort_subsection(vec, mid, low);
        merge_sort_subsection(vec, high, mid+1);
        merge(vec, high, mid, low);

    }
}

// functions
int getSleepTime(){
    return sleep_time;
}

void upSleepTimeBy(int unit){
    sleep_time += unit;
}

void downSleepTimeBy(int unit){
    if(sleep_time-unit > 100) sleep_time -= unit;
}

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

// Sorting Functions
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
                nanosec_sleep(sleep_time);
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
            nanosec_sleep(sleep_time);
            vec[j+1] = vec[j];
            j--;
        }
        nanosec_sleep(sleep_time);
        vec[j+1] = key;
    }
    ResetGlobalFlags();
}

void merge_sort(std::vector<int> &vec){
    int vec_size = vec.size()-1;
    merge_sort_subsection(vec, vec_size, 0);
    ResetGlobalFlags();
}