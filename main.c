#include <stdio.h>
#include "list.h"

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
    printf("%s", "hi");
    print(&list);

    return 0;
}