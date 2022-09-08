[Problem](https://practice.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1)

# Lessons

- **Can't use the same max_elem_it iterator on a vector after pushing some new element to it.**

PS: Spent much time on debugging just due to this small mistake 😓


# Things used

1. BFS (DFS)
2. Queue (Stack)
3. Vector

# Methods

### Find max element in a vector

- `max_elem_it = max_element(vec.begin(), vec.end());` 
- `max_elem_index = max_elem_it - vec.begin()`
- `max_value = *max_element_it`

Similary for minimum:

- `min_elem_it = min_element(vec.begin(), vec.end());` 
- `min_elem_index = min_elem_it - vec.begin()`
- `max_value = *min_element_it`

### Tree Traversal Methods

Use **Stack (DFS)** or, **Queue (BFS)** to store all the **not null child nodes** while you traverse the top element.

