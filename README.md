# My-Malloc-Free
Implementation of malloc() and free() libray calls calls for dynamic memory allocation, using a first fit algorithm, that detect common errors.
Errors include: freeing addresses that are not pointers, freeing pointers that were not allocated by malloc, redundant freeing of the same pointer, and saturation of dynamic memory.
Testing- memgrind.c
