#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList *l = LinkedList_initialize();

    LinkedList_print(l);
    LinkedList_insert_end(l, 2);
    LinkedList_insert_end(l, 5);
    LinkedList_insert_beginning(l, 3);
    LinkedList_print(l);
    printf("List size: %d\n", LinkedList_length(l));

    int value;
    LinkedList_get(l, 1, &value);
    printf("Index 1: %d\n", value);

    LinkedList_set(l, 2, 6);
    LinkedList_print(l);
    LinkedList_print(LinkedList_copy(l));

    return 0;
}
