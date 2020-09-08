# Some Toy Written in C++

Record C++ wheels

## sort.cpp
it is a algorithm for high-performance computation (sorting). 
For example, given two sorted array, we want to sort the array concurrently.
To achieve that, we should set a value in array A, and find all value smaller or equal than this value in B.
Now we get two slice, and we use merge sort on this two slices to get a sorted array.

The file is the algorithm to generate such slices.  