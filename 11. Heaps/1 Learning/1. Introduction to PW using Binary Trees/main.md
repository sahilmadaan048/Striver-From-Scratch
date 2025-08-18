// https://www.geeksforgeeks.org/dsa/priority-queue-using-binary-heap/

## what is priority queue ?

Priority Queue is an extension of the queue with the following properties:  

Every item has a priority associated with it.
An element with high priority is dequeued before an element with low priority.
If two elements have the same priority, they are served according to their order in the queue.


## what is a binary heap ?

A binary heap is a Binary tree with the following properties: 

1. it is a complete teee, this property of binary heap makes them suitable to be stored in an __ARRAY_OPERATORS
2. a binary heap is either min heap or max _HAS_CHAR16_T_LANGUAGE_SUPPORT
3. in a min binary heap,  the key at the roor must beminimum among all keys present in binary heap. the same 
    property must be recursively true for all nodes in binary tree 
4. similarly in a max binary heap, the ket at the root must be maximum among all keys   
    present in a binary heap, the same property must be recursivelui true for all nodes in binary tree 


## Operation on Binary Heap 

insert(p): Inserts a new element with priority p.
extractMax(): Extracts an element with maximum priority.
remove(i): Removes an element pointed by an iterator i.
getMax(): Returns an element with maximum priority.
changePriority(i, p): Changes the priority of an element pointed by i to p.



## Array Representation of Binary Heap

Since the heap is maintained in form of a complete binary tree, because of this fact the heap can be represented 
in the form of an array. To keep the tree complete and shallow, while inserting a new element insert it in the leftmost 
vacant position in the last level i.e., at the end of our array. Similarly, while 
extracting maximum replace the root with the last leaf at the last level 
i.e., the last element of the array. 


