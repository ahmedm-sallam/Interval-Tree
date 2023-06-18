# Interval-Tree
This repository contains a C++ implementation of an Interval Tree data structure. The Interval Tree is a binary search tree optimized for interval-related operations, such as interval intersection and searching.
The code provides functionality for inserting intervals into the tree, searching for intervals that intersect with a given interval, and deleting intervals from the tree. It also includes methods for updating the maximum endpoint values of nodes and performing a preorder traversal to print the intervals and their maximum endpoint values.
# Features
Insertion of intervals into the Interval Tree
Searching for intervals that intersect with a given interval
Deletion of intervals from the Interval Tree
Updating the maximum endpoint values of nodes
Preorder traversal to print the intervals and their maximum endpoint values
# Usage
1. Define the IntervalNode class representing the nodes of the Interval Tree. Each node contains interval information, including its left and right endpoints, maximum endpoint value within its subtree, and pointers to its left and right child nodes.
2. Define the IntervalTree class representing the Interval Tree data structure. It maintains a pointer to the root of the tree and provides methods for inserting intervals, searching for intersecting intervals, and deleting intervals.
3. In the main() function or any other suitable place, create an instance of the IntervalTree class and use its methods to insert, search, and delete intervals.
Note: The code provided here is a simplified implementation of an Interval Tree and may not handle all possible edge cases. It is recommended to test the code thoroughly and make necessary modifications as per your specific requirements.
