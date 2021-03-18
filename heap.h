#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    private:
        vector<int> heap;
    public:
        Heap();
        void push(int val);
        int popmin();
        void fix_heap_up(int idx);
        void fix_heap_down(int idx);
        void print();

};

Heap::Heap()
{
    this->heap = {};

}

void Heap::push(int val)
{
    this->heap.push_back(val);
    int idx = this->heap.size()-1;
    this->fix_heap_up(idx);
}

void Heap::fix_heap_up(int idx)
{
    // Index of parent is (idx-1)/2
    // if the parent is root, perform at most one swap and return
    if ((idx-1)/2 == 0)
    {
        int parent_idx = (idx-1)/2;
        // swap if parent is larger than self
        if (this->heap[parent_idx] > this->heap[idx])
        {
            int temp = this->heap[idx];
            this->heap[idx] = this->heap[parent_idx];
            this->heap[parent_idx] = temp;
        }
        return;
    } 
    // else, fix up recursively. 
    else
    {
        int parent_idx = (idx-1)/2;
        //swap if parent is larger than self, recursively
        if (this->heap[parent_idx] > this->heap[idx])
        {
            // swap
            int temp = this->heap[idx];
            this->heap[idx] = this->heap[parent_idx];
            this->heap[parent_idx] = temp;

            // RECOOOOOSE!
            fix_heap_up(parent_idx);
        }
    }
}

void Heap::print()
{
    for (int i = 0; i < this->heap.size(); i++)
    {
        cout << this->heap[i] << " ";
    }
    cout << endl;
}

int Heap::popmin()
{
    int min = this->heap[0];
    int last = this->heap.back();
    this->heap.pop_back();
    if (this->heap.size() > 0)
    {
        this->heap[0] = last;
        this->fix_heap_down(0);
    }
 
    return min;
}

void Heap::fix_heap_down(int idx)
{
    if (2*idx + 2 > this->heap.size()-1)
    {
        return;
    }
    else
    {
        int childl = 2*idx + 1;
        int childr = 2*idx + 2;
        //index of chosen child
        int chosen;
        // chooses a child to potentially swap with 
        // the parent. decision made on which is smaller
        if (this->heap[childl] < this->heap[childr]) chosen = childl;
        else chosen = childr;          
        
        // Swap and recurse if chosen child is smaller than
        // parent.
        if (this->heap[chosen] < this->heap[idx])
        {
            int temp = this->heap[chosen];
            this->heap[chosen] = this->heap[idx];
            this->heap[idx] = temp;
            // recurse!!!!!
            this->fix_heap_down(chosen);
        }
    }
}


#endif