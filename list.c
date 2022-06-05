//
// Created by Dhevin N on 5/6/22.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *list;
    int size;
    int capacity;
} intList;

void init(intList *list) {
    list-> list = calloc(2, sizeof (int));
    list-> capacity = 2;
    list-> size = 0;
}

int getSize(intList *list){
    return list->size;
}

int getCapacity(intList *list) {
    return list->capacity;
}

void clear(intList *list) {
    init(list);
}

void resize(intList *list, int newCap) {
    int tempArray[list->size];
    for (int i = 0; i< list->size; i++) {
        tempArray[i] = list-> list[i];
    }

    free(list->list);
    list->list = calloc(newCap, sizeof(int));

    for (int i = 0; i<list->size; i++) {
        list->list[i] = tempArray[i];
    }

    list->capacity = newCap;
}

void minimize(intList *list) {
    if (list->size == 0) {
        clear(list);
        return;
    }
    resize(list, list->size);
}

void doubleCap(intList*list) {
    resize(list, list->capacity*2);
}

int getIndex(intList *list, int val) {//assumes unsorted, linear search
    for (int i = 0; i < list->size; i++) {
        if (list->list[i] == val) {
            return i;
        }
    }
    return -1;
}

int contains(intList *list, int val) { //returns 1 or 0, boolean
    return (getIndex(list, val) != -1);
}

void add(intList *list, int val) {
    if (list->capacity - list->size < 1) doubleCap(list);

    list->list[list->size - 1] = val;

    list->size++;
}

int insert(intList *list, int val, int index) {
    if (index < 0 || index > list->size) return INT32_MIN; //returns INT32_MIN if fail

    if (index == list->size) {
        add(list, val);
        return INT32_MAX; //returns INT32_MAX if appended,
    }

    int temp = list->list[index];
    list->list[index] = val;
    return temp; //returns initial value if used as intended

}

int removeAt(intList *list, int index) {
    if (index > list->size-1 || index < 0) return INT32_MIN;

    int temp = list->list[index];
    list->size--;

    for (int i = index; i < list->size; i++) {
        list->list[i] = list->list[i + 1];
    }

    if (list->capacity - list->size > list->capacity/2) {
        minimize(list);
    }

    return temp;

}

int removeVal(intList *list, int val) {
    int index = getIndex(list, val);
    if (index == -1) return 0;

    else removeAt(list, index);
    return 1;
}

int count(intList *list, int val) {
    int count = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->list[i] == val) {
            count++;
        }
    }
    return count;
}

void merge(int *arr[], int start, int mid, int end) {
    int n1 = mid-start + 1;
    int n2 = end - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = *arr[start+i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = *arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            *arr[k] = leftArr[i];
            i++;
        } else {
            *arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i<n1) {
        *arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j<n2) {
        *arr[k] = rightArr[j];
        j++;
        k++;
    }

}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
void mergeSort(int *arr[], int start, int end) {
    if (start < end) {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}
#pragma clang diagnostic pop

void sort(intList *list) {
    int *arr[list->size];
    for (int i = 0; i < list->size; i++) {
        *arr[i] = list->list[i];
    }
    mergeSort(arr, 0, list->size-1);

    for (int i = 0; i < list->size; i++) {
        list->list[i] = *arr[i];
    }
}

void reverse(intList *list) {
    int tempArray[list->size];
    for (int i = 0; i < list->size; i++) {
        tempArray[i] = list->list[i];
    }

    for (int i = 0; i < list->size; i++) {
        list->list[i] = tempArray[list->size-1-i];
    }
}

void print(intList *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->list[i]);
    }
    printf("\n length: %d", list->size);
    printf("\n capacity: %d \n", list->capacity);

}