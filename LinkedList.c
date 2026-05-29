#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
Initializes and returns a new Node.
Returns NULL if fails.
O(1)
*/
Node *Node_initialize(int value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = value;
        new_node->next = NULL;
    }
    return new_node;
}

/*
Initializes and returns a new LinkedList.
Returns NULL if fails.
O(1)
*/
LinkedList *LinkedList_initialize() {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list != NULL) list->first = NULL;
    return list;
}

/*
Returns 1 if LinkedList is empty, 0 otherwise.
O(1)
*/
int LinkedList_is_empty(LinkedList *l) {
    return l->first == NULL;
}

/*
Returns the Node of the LinkedList at index 'index'.
O(n)
*/
Node *LinkedList_find_node(LinkedList *l, int index) {
    // Add the length to negative indices so that they access the list backwards
    if (index < 0) {
        index += LinkedList_length(l); // Note that this could be optimized, since we're looping once for this line and another time later in this function. However, the time complexity wouldn't change.
        if (index < 0) {
            return NULL;
        }
    }

    // Find the node and return NULL if the index is too big
    Node *current = l->first;
    int i = 0;
    while (current != NULL) {
        if (i == index) {
            break;
        }
        current = current->next;
        i++;
    }
    return current;
}

/*
Inserts a new element at the beginning of the LinkedList.
Returns 1 if successful, 0 otherwise.
O(1)
*/
int LinkedList_insert_beginning(LinkedList *l, int value) {
    Node *new = Node_initialize(value);
    if (new == NULL) return 0;

    new->next = l->first;
    l->first = new;

    return 1;
}

/*
Inserts a new element at the end of the LinkedList.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_insert_end(LinkedList *l, int value) {
    Node *new = Node_initialize(value);
    if (new == NULL) return 0;

    if (LinkedList_is_empty(l)) l->first = new;
    else LinkedList_find_node(l, -1)->next = new;

    return 1;
}

/*
Inserts a new element before the element at the given index of the LinkedList.
For example, index=0 inserts at the beginning.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_insert_at(LinkedList *l, int index, int value) {
    if (index < 0) {
        index += LinkedList_length(l) + 1;
        if (index < 0) {
            return 0;
        }
    }

    Node *new = Node_initialize(value);
    if (new == NULL) return 0;

    if (index == 0) return LinkedList_insert_beginning(l, value);
    else {
        Node *prev_node = LinkedList_find_node(l, index - 1);
        if (prev_node == NULL) {
            free(new);
            return 0;
        }
        new->next = prev_node->next;
        prev_node->next = new;
        return 1;
    }
}

/*
Removes the first element of the LinkedList.
Assigns its value to the parameter value.
Returns 1 if successful, 0 otherwise.
O(1)
*/
int LinkedList_remove_beginning(LinkedList *l, int *value) {
    if (LinkedList_is_empty(l)) return 0;

    *value = l->first->data;

    Node *temp = l->first;
    l->first = l->first->next;
    free(temp);

    return 1;
}

/*
Removes the last element of the LinkedList.
Assigns its value to the parameter value.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_remove_end(LinkedList *l, int *value) {
    if (LinkedList_is_empty(l)) return 0;

    if (l->first->next == NULL) {
        *value = l->first->data;
        free(l->first);
        l->first = NULL;
    } else {
        Node *second_last = LinkedList_find_node(l, -2);
        *value = second_last->next->data;

        free(second_last->next);
        second_last->next = NULL;
    }
    
    return 1;
}

/*
Removes the element at the given index of the LinkedList.
Assigns its value to the parameter value.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_remove_at(LinkedList *l, int index, int *value) {
    if (LinkedList_is_empty(l)) return 0;

    if (index < 0) {
        index += LinkedList_length(l);
        if (index < 0) {
            return 0;
        }
    }

    if (index == 0) return LinkedList_remove_beginning(l, value);
    else {
        Node *prev_node = LinkedList_find_node(l, index - 1);
        if (prev_node == NULL) return 0;
        Node *removed = prev_node->next;
        *value = removed->data;

        prev_node->next = removed->next;
        free(removed);
    }
    
    return 1;
}

/*
Removes the first element of the LinkedList that has the given value.
Assigns its index to the parameter index.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_remove_at_value(LinkedList *l, int value, int *index) {
    if (LinkedList_is_empty(l)) return 0;

    Node *current = l->first;
    int i = 0;
    while (current->next != NULL) {
        if (current->next->data == value) {
            Node *removed = current->next;
            *index = i;

            current->next = removed->next;
            free(removed);
            return 1;
        }

        current = current->next;
        i++;
    }

    return 0;
}

/*
Returns the length of the LinkedList.
O(n)
*/
int LinkedList_length(LinkedList *l) {
    Node *current = l->first;
    int length = 0;
    while (current != NULL) {
        current = current->next;
        length++;
    }

    return length;
}

/*
Assigns the value at the given index of the LinkedList to the parameter value.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_get(LinkedList *l, int index, int *value) {
    Node *node = LinkedList_find_node(l, index);
    if (node == NULL) return 0;

    *value = node->data;
    return 1;
}

/*
Assigns the given value to the element at the given index of the LinkedList.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_set(LinkedList *l, int index, int value) {
    Node *node = LinkedList_find_node(l, index);
    if (node == NULL) return 0;

    node->data = value;
    return 1;
}

/*
Assigns the index of the first element of the LinkedList that has the given value to the parameter index.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_index(LinkedList *l, int value, int *index) {
    Node *current = l->first;
    int i = 0;
    while (current != NULL) {
        if (current->data == value) {
            *index = i;
            return 1;
        }
        current = current->next;
        i++;
    }
    return 0;
}

/*
Returns 1 if the LinkedList contains the given value, 0 otherwise.
O(n)
*/
int LinkedList_contains(LinkedList *l, int value) {
    Node *current = l->first;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

/*
Returns the number of elements in the LinkedList with the given value.
Returns 0 if there are none.
O(n)
*/
int LinkedList_count(LinkedList *l, int value) {
    Node *current = l->first;
    int count = 0;
    while (current != NULL) {
        if (current->data == value) {
            count++;
        }
        current = current->next;
    }

    return count;
}

/*
Clears the LinkedList.
O(n)
*/
void LinkedList_clear(LinkedList *l) {
    Node *current = l->first;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    l->first = NULL;
}

/*
Inserts the elements of the other LinkedList to the end of the LinkedList.
Returns 1 if successful, 0 otherwise.
O(n)
*/
int LinkedList_extend(LinkedList *l, LinkedList *other) {
    int list_started_empty = LinkedList_is_empty(l);

    if (list_started_empty) {
        if (LinkedList_is_empty(other)) return 1;
        if (LinkedList_insert_beginning(l, other->first->data) == 0) return 0;
    }
    
    int last_index = LinkedList_length(l); // Note that this could be optimized, since we're looping once for this line and another time for the next. However, the time complexity wouldn't change.
    Node *last = LinkedList_find_node(l, -1);
    Node *current = other->first;
    while (current != NULL) {
        Node *new = Node_initialize(current->data);
        if (new == NULL) { // If fails to initialize a new node, remove all added nodes.
            current = LinkedList_find_node(l, last_index);
            last = current;
            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp);
            }
            last->next = NULL;
            if (list_started_empty) {
                free(last);
                l->first = NULL;
            }
            return 0;
        }
        last->next = new;

        current = current->next;
        last = last->next;
    }
    return 1;
}

/*
Inserts the elements of the other LinkedList to the end of the LinkedList
and clears and frees the other LinkedList.
O(n)
*/
void LinkedList_combine(LinkedList *l, LinkedList *other) {
    if (LinkedList_is_empty(l)) {
        if (LinkedList_is_empty(other)) return;
        l->first = other->first;
    } else LinkedList_find_node(l, -1)->next = other->first;

    LinkedList_clear(other);
    free(other);
}

/*
Returns a copy of the LinkedList.
Returns NULL if fails.
O(n)
*/
LinkedList *LinkedList_copy(LinkedList *l) {
    LinkedList *copy = LinkedList_initialize();
    if (copy != NULL) {
        copy->first = Node_initialize(l->first->data);
        Node *current_copy = copy->first;
        Node *current = l->first->next;
        while (current != NULL) {
            Node *new = Node_initialize(current->data);
            if (new == NULL) {
                LinkedList_clear(copy);
                free(copy);
                return NULL;
            }
            current_copy->next = new;

            current_copy = current_copy->next;
            current = current->next;
        }
    }

    return copy;
}

/*
Prints the LinkedList.
O(n)
*/
void LinkedList_print(LinkedList *l) {
    printf("[");
    if (l->first != NULL) {
        Node *current = l->first;
        while (current->next != NULL) {
            printf("%d, ", current->data);
            current = current->next;
        }
        printf("%d", current->data);
    }
    printf("]\n");
}

// insert_end implementation without the find_node function
// O(n)
// 
// int LinkedList_insert_end(LinkedList *l, int value) {
//     Node *new = Node_initialize(value);
//     if (new == NULL) return 0;
// 
//     if (l->first == NULL) l->first = new;
//     else {
//         Node *current = l->first;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = new;
//     }
// 
//     return 1;
// }

// insert_at implementation without the find_node function
// O(n)
// 
// int LinkedList_insert_at(LinkedList *l, int index, int value) {
//     if (index < 0) {
//         index += LinkedList_length(l) + 1;
//         if (index < 0) {
//             return 0;
//         }
//     }
// 
//     Node *new = Node_initialize(value);
//     if (new == NULL) return 0;
// 
//     if (l->first == NULL) {
//         if (index == 0) {
//             l->first = new;
//             return 1;
//         }
//         free(new);
//         return 0;
//     } else {
//         Node *current = l->first;
//         int i = 0;
//         while (current->next != NULL) {
//             if (i == index) {
//                 break;
//             }
//             current = current->next;
//             i++;
//         }
//         if (i == index) {
//             new->next = current->next;
//             current->next = new;
//             return 1;
//         }
//         free(new);
//         return 0;
//     }
// }

// get implementation without the find_node function
// O(n)
// 
// int LinkedList_get(LinkedList *l, int index, int *value) {
//     if (index < 0) {
//         index += LinkedList_length(l);
//         if (index < 0) {
//             return 0;
//         }
//     }
// 
//     Node *current = l->first;
//     int i = 0;
//     while (current != NULL) {
//         if (i == index) {
//             *value = current->data;
//             return 1;
//         }
//         current = current->next;
//         i++;
//     }
// 
//     return 0;
// }
