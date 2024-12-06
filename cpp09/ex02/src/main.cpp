/* Recursively divide into pairs of numbers, pairs of pairs of numbers, 
pairs of pairs of pairs of numbers... etc, and sort them by the biggest number, 
until we can't form any pair anymore. If there is an unpaired odd element, leave it be.

Create a sequence (also referred to as S or the main chain) 
out of the smallest element of the smallest pair (b1) and the rest of as. If the first step was done
correctly, this sequence will be sorted. Create the sequence that consists of the rest 
of bs (also referred to as the pend).

Binary insert the elements from the pend into the main, in the order based on Jacobsthal numbers.

If we can't insert elements into the main using Jacobsthal numbers anymore, we insert them normally, in order, 
using binary insertion.

Insert the odd element that didn't fit into any pair.  

Insertion sort (better for smaller data sets, no additional memory allocation required but slower): 
    -Time complexity (worst case): O(n^2)
    -Space complexity: O(1)

Merge sort (better for large datasets, more memory required but faster):
    -Time complexity: O(NLog(N)
    -Space complexity: O(N)

Merge-Insertion sort (Ford-Johnson algorithm): 
    -Time complexity (worst case): NK + N*log(N/K)
    -Space complexity: O(1)

K parameter: boundary where the algorithm switches from the overhead of merge sort to the 
simplicity of insertion sort.
*/

