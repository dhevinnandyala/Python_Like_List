#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int **list;
    int size;
    int capacity;
} intList;

void init(intList *list) {
    list -> list = calloc(1, sizeof (int *));
    list -> size = 0;
    list -> capacity = 1;
}

void append(intList *list, int num ) {
    if (list->capacity - list->size < 2) {
        int *tempArray[list->capacity * 2];
        for (int i = 0; i < list->size; i++) {
            tempArray[i] = list->list[i];
        }
        free(list->list);
        list -> list = calloc(list->capacity * 2, sizeof(int *));
        for (int i = 0; i < list->size; i++) {
            list->list[i] = tempArray[i];
        }
        list->capacity *= 2;
    }
    list->size++;
    list->list[list->size - 1] = num;
}

int getIndex(intList *list, int value) {
    if (list->size == 0) {
        return -1;
    }

    for (int i = 0; i < list->size; i++) {
        if (list->list[i] == value) {
            return i;
        }
    }
    return -1;
}

int peek(intList *list, int index) {
    if (index+1 > list->size) return -1;

    return list->list[index];
}

int removeAt(intList *list, int index) {
    list->size--;
    if (index > list->size || index < 0) return -1;
    int value = list->list[index];
    for (int i = index; i < list->size-1; i++) {
         list->list[i] = list->list[i+1];
    }
    list->list[list->size] = NULL;
    return value;
}

void removeVal(intList *list, int value) {
    int index = getIndex(&list, value);
    removeAt(&list, index);
}

int main() {
    intList list;
    init(&list);

    append(&list, 0);
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);
    append(&list, 4);
    append(&list, 5);

    printf("%d \n",peek(&list, 0));
    printf("%d \n",peek(&list, 3));
    printf("%d \n",peek(&list, 5));

    printf("%d \n", removeAt(&list, 2));
    printf("%d \n",peek(&list, 2));
    removeVal(&list, 2);
    removeVal(&list, 3);
    printf("%d \n", peek(&list, 3));
    printf("%d \n", peek(&list, 2));
    printf("%d \n", peek(&list, 4));












    return 0;
}
