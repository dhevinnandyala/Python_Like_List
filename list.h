//
// Created by Dhevin N on 5/6/22.
//

#ifndef PYTHON_LIKE_LIST_LIST_H
#define PYTHON_LIKE_LIST_LIST_H

typedef struct {} intList;

void init(intList *list); //initializes list to empty array, size to 0, capacity to 2
int getSize(intList *list); //returns size
int getCapacity(intList *list); //returns capacity (size of array)
void clear(intList *list); //returns list to initial state (empty array, size 0, capacity 2)
void minimize(intList *list); //resizes array length to list size (capacity -> size)
int getIndex(intList *list, int val); //returns index of the first occurrence of value
int contains(intList *list, int val); //returns 1 if list contains value, 0 if not
void add(intList *list, int val); //appends val to the end of the list
int insert(intList *list, int val, int index); //index must NOT exceed list.getSize(), inserts value at index, returns current value at index
int removeAt(intList *list, int index); //removes element stored at index, minimizes if size is less than half capacity, returns INT32_MIN if index out of bounds
int removeVal(intList *list, int val); //removes first occurrence of value. Returns 0 if value is not contained in list. Returns 1 if successfully removed value.
int count(intList *list, int val); //returns number of times value occurs in list
void sort(intList *list); //sorts list using Quicksort
void reverse(intList *list); //reverses list
void print(intList *list); //prints list, size, and capacity

#endif //PYTHON_LIKE_LIST_LIST_H
