# Custom Malloc & Free
Implementation of malloc() and free() libray calls for dynamic memory allocation, using a first fit algorithm for malloc, with common error checking.

Errors include: freeing addresses that are not pointers, freeing pointers that were not allocated by malloc, redundant freeing of the same pointer, and saturation of dynamic memory.

Testing both calls in memgrind.c
