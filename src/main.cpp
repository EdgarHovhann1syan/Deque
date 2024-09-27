#include "../include/Deque.h"
#include <cassert>
int main() { 
Deque dq(5); // Deque with capacity 5

// Push elements from the front and back
dq.push_front(1); // [1]
dq.push_back(2);  // [1, 2]
dq.push_front(3); // [3, 1, 2]
dq.push_back(4);  // [3, 1, 2, 4]

// Pop elements from the front and back
assert(dq.get_front() == 3); // Expected Output: 3
dq.pop_front();
assert(dq.get_back() == 4);  // Expected Output: 4
dq.pop_back();
assert(dq.get_front() == 1); // Expected Output: 1
dq.pop_front();
assert(dq.get_back() == 2);  // Expected Output: 2
dq.pop_back();
}