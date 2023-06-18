# Interval-Tree
This is a C++ code implementation of an Interval Tree data structure. An Interval Tree is a data structure used for efficient interval overlap detection and interval search operations. The code provides functionality for inserting intervals into the tree, searching for intervals that intersect with a given interval, and deleting intervals from the tree.
# Usage
1. Define the IntervalNode class representing the nodes of the Interval Tree. Each node contains interval information, including its left and right endpoints, maximum endpoint value within its subtree, and pointers to its left and right child nodes.
2. Define the IntervalTree class representing the Interval Tree data structure. It maintains a pointer to the root of the tree and provides methods for inserting intervals, searching for intersecting intervals, and deleting intervals.
3. In the main() function or any other suitable place, create an instance of the IntervalTree class and use its methods to insert, search, and delete intervals.
Note: The code provided here is a simplified implementation of an Interval Tree and may not handle all possible edge cases. It is recommended to test the code thoroughly and make necessary modifications as per your specific requirements.
