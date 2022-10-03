#ifndef sorting_algos_hpp
#define sorting_algos_hpp

#include <iostream>

using namespace std;

class sorting_algo{
public:
    sorting_algo();
    ~sorting_algo();

    void selection_sort(int arr[],int n);
private:
    int flag_0;

};

#endif