#include<iostream>
#include<set>
using namespace std;

int main()
{
set<int> s;
for (int i = 0; i < 5; i++)
{
    int a;
    cin >> a;
    s.insert(a);
}
s.erase(s.find(5));
// s.erase(5);
for (auto i = s.begin(); i != s.end(); ++i)
{
    cout << *i << " ";
}

    return 0;
}

/*

the differences between s.erase(value) and s.erase(iterator) in terms of usage. Here’s a quick breakdown:

s.erase(value):

If you know exactly which element (like 5) you want to delete, s.erase(value) is straightforward.
It finds the element and erases it in one step, so you don’t need to manually locate it with find().
s.erase(iterator):

When you're working directly with iterators, especially in loops where you're examining each element, using s.erase(iterator) is more efficient.
This approach prevents an additional lookup, saving time and memory.
It also allows you to increment the iterator more smoothly if you're deleting items conditionally within a loop.
For example:

for (auto it = s.begin(); it != s.end(); ) {
    if (*it == someCondition) {
        it = s.erase(it); // erase returns the next iterator
    } else {
        ++it; // advance only if not erased
    }
}

This makes iterator-based deletion ideal for complex situations and conditional deletions within a loop, whereas erase(value) is cleaner when you simply need to remove a single known value.

*/