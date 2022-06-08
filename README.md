# Python_Like_List

This is an implementation of a list of integers that has an interface somewhat similar to lists in Python.

Allows functions like add(), removeAt(), and removeVal(), and abstracts away the memory allocation, search, removal.

The main.c file is a test/example file that shows how the list.c file might be used.

list.c contains the actual implementation of the integer list.

list.h contains declarations for all of the public methods from list.c, although of course, private methods are also available for you to look
at by just opening list.c or using #include "list.c"

list.h also contains comments explaining the use of each function.
