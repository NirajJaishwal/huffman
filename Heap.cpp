#include "Heap.hpp"

//Add an element to the tree
void Heap::enqueue(HNode* node)
{
    if(position + 1 == tree.size())
    {
        tree.resize(tree.size() * 2);
    }
    tree[++position] = node;
    fix_up(position);
    count++;
}

// Fix the heap from a specific index up
void Heap::fix_up(const int& index)
{
    int i = index;
    while(i > 1 && *tree[i] < *tree[i/2])
    {
        std::swap(tree[i], tree[i/2]);
        i/=2;
    }
}

//Remove the smallest element
HNode * Heap::dequeue()
{
    if(count > 0)
    {
        HNode* root = tree[1];
        tree[1] = tree[position--];
        fix_down(1);
        count--;
        return root;
    }
    else
    {
        return nullptr;
    }
}

//fix the tree after replacing the smallest element
void Heap::fix_down(const int & index)
{
    int i = index;
    while(2 * i <= position)
    {
        int child = 2 * i;
        if(child + 1 <= position && *tree[child + 1] < *tree[child])
        {
            ++child;
        }
        if(*tree[child] < *tree[i])
        {
            std::swap(tree[child], tree[i]);
            i = child;
        }
        else
        {
            break;
        }
    }
}

//clear the Heap
void Heap::clear()
{
    tree.clear();
    tree.resize(2);
    position = 0;
    count = 0;
}
