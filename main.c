#include <stdio.h>

typedef struct {
    int *list;
    int size;
    int capacity;
} intList;

void init(intList *list);
int getSize(intList *list);
int getCapacity(intList *list);
void clear(intList *list);
void minimize(intList *list);
int getIndex(intList *list, int val);
int contains(intList *list, int val);
void add(intList *list, int val);
int insert(intList *list, int val, int index);
int removeAt(intList *list, int index);
int removeVal(intList *list, int val);
int count(intList *list, int val);
void sort(intList *list);
void reverse(intList *list);
void print(intList *list);


int main() {
    intList list;
    init(&list);

    add(&list, 0);
    add(&list, 19);
    add(&list, 12);
    add(&list, 1);
    add(&list, 12);

    print(&list);

    minimize(&list);

    print(&list);

    clear(&list);

    add(&list, 0);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);

    printf("%d \n", getIndex(&list, 1));
    printf("%d \n", getIndex(&list, 12));

    removeVal(&list, 1);
    print(&list);
    removeVal(&list, 12);
    print(&list);

    removeAt(&list, 1);
    print(&list);

    if (contains(&list, 2)) {
        print(&list);
    }

    insert(&list, 8, 2);
    print(&list);

    add(&list, 2);
    add(&list, 2);

    printf("%d \n", count(&list, 2));

    print(&list);
    sort(&list);
    print(&list);
    reverse(&list);
    print(&list);


}