# Custom Malloc & Free
Implementation of malloc() and free() libray calls calls for dynamic memory allocation, using a first fit algorithm, with common error checking.

Errors include: freeing addresses that are not pointers, freeing pointers that were not allocated by malloc, redundant freeing of the same pointer, and saturation of dynamic memory.

Testing both in memgrind.c
