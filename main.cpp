#include <iostream>
#include <vector>
#include "heap.h"

using namespace std;

int main()
{
    Heap h;

    // ------------- TEST 1 -- HEAP OPERATIONS ---------------- //  (COMPLETE)

    // h.print();
    // h.push(0);
    // h.print();
    // h.popmin();
    // h.print();

    // ---------------- TEST 2 -- HEAPSORT ---------------------- //  (COMPLETE)

    vector<int> unsorted = {1, 9, 8, 6, 7, 5, 2, 3, 4, 0};
    vector<int> sorted = {};


    // ---------------- TEST 2.1 -- RANDOM VECTOR --------------------- //

    unsorted = {};
    for (int i = 0; i < 1000000; i++)
    {
        unsorted.push_back(i);
    }
    for (int i = 0 ; i < unsorted.size(); i++)
    {
        int remaining = unsorted.size() - i;
        int rand_idx = rand()%remaining + i;
        int temp = unsorted[i];
        unsorted[i] = unsorted[rand_idx];
        unsorted[rand_idx] = temp;
    }

    // ----------------------------------------------------------------- //

    // sort
    for (int i = 0; i < unsorted.size(); i++)
    {   
        h.push(unsorted[i]);
    }
    for (int i = 0; i < unsorted.size(); i++)
    {   
        sorted.push_back(h.popmin());
        //cout << i << endl;
    }



    // print unsorted  
    for (int i = 0; i < unsorted.size(); i++)
    {
        cout << unsorted[i] << " ";
    } cout << endl;
    // print sorted
    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }cout << endl;



    // SORT CHECKER
    for (int i = 1; i < sorted.size(); i++)
    {
        if (sorted[i] < sorted[i-1])
        {
            cout << "failed" << endl;
            return 0;
        }
       
       
    }
    cout << "succeeded" << endl;

    return 0;
}