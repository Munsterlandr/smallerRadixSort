# Smaller Radix Sort
Proof of concept for a modified version of base 2 radix sort that optimizes RAM usage. I'm using C because it's really low level, so I can guarentee its doing exactly what I want it to do. I'm also not gonna use any pointer stuff because I barely know C and doing stack only should actually result in no memory leaks.

The program sorts integers from greatest to least, because that seems to be the most ideal for a lot of things. Also requires said list of integers to be unsigned, because I decided to optimize it even more with some bit shift trickery.

## What makes this one unique?
Normally, radix sort uses lists for the buckets so memory usage is more optimal compared to making a bunch of arrays that are the same size as the inputted array. Instead, this uses 1 array of the same size as the inputted one, and a count of how many have 0 in the bit currently focused on. The ones with 0 in the bit are put on the back, while the ones with 1 are put at the front. Then, the section at the back's order is reversed, before the values are copied over to the input array.

I'm gonna use a few extra variables too, though, such as the array length, and the number of iterations needed to cover each digit.
