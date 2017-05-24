#include "linkedList.h"

/*inserts a skater into linked list of skaters, if head is unassigned, assigns target to head*/
void insertSkater(skater *head, skater *target) {
    skater *ptr;

    if (head == NULL)
        head = target;
    else {
        if (head->next == NULL)
            head->next = target;
        else {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = target;
        }
    }
}
