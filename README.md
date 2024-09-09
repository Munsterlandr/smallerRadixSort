# Smaller Radix Sort
Proof of concept for a modified version of base 2 radix sort that optimizes RAM usage. I wrote it in C because it lets me force integers to be unsigned, and I've wanted to learn it for a while. The algorithm does not use the heap at all, so no memory leaks.

The program sorts integers from greatest to least, because that seems to be the most ideal for a lot of things. Also requires said list of integers to be unsigned, because I decided to optimize it even more with some bit shift trickery.

This should also prove to teach about radix sort, too.

## Defining some terms
* List: an ordered series of objects with no set length.
* Array: an ordered series of objects with a set length.
* Linked List: A method for implementing Lists where each value has a pointer to the spot in memory of the next value placed next to it, so a given value can be obtained by going a given number of nodes in.

## Explanation
### What's Radix Sort?
Radix Sort is a sorting algorithm that uses no comparisons. Instead, it uses a series of lists and positional notation. Here's how it works when sorting an array from greatest to least:

1. Initialize a number of Lists equal to the Base you want the numbers to be sorted with. For example, if you wanted it to handle numbers in base 10, you would initialize 10 lists. Each list represents a possible value for a digit - so for base 10, that would be a zeros list, a ones list, a twos list, etc. These lists are referred to as _Buckets_.
2. Go through the input array from the first value to the last, appending it to the Bucket asociated with the digit in the lowest position.
3. Create a new array by Appending each bucket together, highest to least. This ensures that the given position is sorted. The old buckets can now be removed from memory.
4. Repeat the previous three steps using the new array, but this time sorting the next highest position. This causes the sorting of the previous position to still influence the order of things, but the order of the next highest position becomes more important. While the first round would have placed 29 ahead of 51, the second round remedies this.
5. Repeat step 4 until the highest defined position has been sorted.

Despite it being less common, its complexity scales linearly, meaning it could sort extremely large data sets far faster than comparison based sorting algorithms.
### Why is it not used?
The big drawback of Radix Sort is that it uses far more memory than other sorting algorithms. You'd either be using Linked Lists for the buckets, or Arrays the length of the input data. As well as this, the overhead of initializing and clearing the arrays makes it slower in practical terms.

### What makes this implementation more efficient?
Instead of using a series of lists for buckets, it splits one array using one integer to specify where it goes from the high values and the low values.
## Compilation Instructions
### Linux
If you're a fellow linux NERD, you're in luck: the files in this repo without any extension are linux binaries. Please run in the terminal, though, because that's the most gui I'm putting on this project.
### Other
Open up this project in an IDE, and have it handle compilation of the file. You can also use a compiler if you want, but the program is still CLI, so if you're scared of using the terminal, an IDE's you're best choice. 
