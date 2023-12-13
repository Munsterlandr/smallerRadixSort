# Smaller Radix Sort
Proof of concept for a modified version of base 2 radix sort that optimizes RAM usage. I wrote it in C because it lets me force integers to be unsigned, and I've wanted to learn it for a while. The algorithm does not use the heap at all, so no memory leaks.

The program sorts integers from greatest to least, because that seems to be the most ideal for a lot of things. Also requires said list of integers to be unsigned, because I decided to optimize it even more with some bit shift trickery.

This should also prove to teach about radix sort, too.

## What's Radix Sort?
Radix Sort is a sorting algorithm that uses no comparisons. Instead, it uses a set of "buckets", ie lists. It works like this (in the case of sorting greatest to least):

1. Check the value of each number at the lowest position (in the case of base 10, that would be the 1s place).
2. Add it to the list for other numbers with the same value in the given position.
3. After all numbers have been sorted by position, append all the lists together so the numbers in the highest list are in front and numbers in the lowest list are in the back.
4. Repeat steps 1 through 3 with the next position.
5. Repeat step 4 until all numbers are sorted.

What makes this algorithm interesting it that the big O Notation of it is linear, which essentially means that the time taken scales at a linear rate, unlike even Quick Sort. The main thing that holds it back from being commonplace, though, is that it takes far more memory than most commonplace comparison sorts, making it so that you can't put in a big enough dataset for the lower complexity to result in faster times.

## What makes this implementation (potentially) more efficient?
This is a result of the distinction between arrays and lists. While an array can only have values of a set type and must have a set length, lists don't have a set length and can be appended to with more values. Computer memory works much like a giant array, though, so while it's easy to allocate memory for an array, allocating memory for a list (or any data structure with an unset amount of elements) is tricky. A lot of languages implement lists as Linked Lists, which store the data as nodes with pointers to the next value; this means, though, that if a List has the same number of elements as an array, the array will take up less space in memory. The only other option for lists requires you to also use the heap, this time by rewriting an array each time an element is appended to the list, and that's not much better.

Instead of using lists for buckets, though, this algorithm uses one array along with some extra variables to sort into buckets. It works like this:

1. If a number has 1 in the position, it is put at the lowest unassigned index (which is stored in a variable).
2. If a number has 0 in the position, it is put at the highest unassigned index (which is stored in another variable).
3. After the numbers have all been put in the array, the order of the ones with 0 in the currently focused on position are flipped, resulting in the same outcome as stitching together all buckets would give.
4. The holding array is copied over to the array to be sorted.

This is only possible due this radix sort being base 2; if it was in any other base, this method wouldn't work.

## Compilation Instructions
### Linux
If you're a fellow linux NERD, you're in luck: the files in this repo without any extension are linux binaries. Please run in the terminal, though, because that's the most gui I'm putting on this project.
### Other
Open up this project in an IDE, and have it handle compilation of the file. You can also use a compiler if you want, but the program is still CLI, so if you're scared of using the terminal, an IDE's you're best choice. 
