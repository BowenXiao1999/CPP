# Some Toy Written in C++

Record C++ wheels

## sort.cpp
it is a algorithm for high-performance computation (sorting). 
For example, given two sorted array, we want to sort the array concurrently.
To achieve that, we should set a value in array A, and find all value smaller or equal than this value in B.
Now we get two slice, it is safe to use merge sort on this two slices to get a sorted array then.

The file is the algorithm to generate such slices. To describe it, given two sorted array a and b, and a fix number n.
We want to return a pair that indicates the index to truncate for new slices (len of two slice add up to n). 

In new_sort.cpp we implemented a new algorithm by fast choosing index.  