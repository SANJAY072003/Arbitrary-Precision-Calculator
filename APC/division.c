#include "valid.h"

int division(Dlist **dividend_head, Dlist **dividend_tail,
             Dlist **divisor_head, Dlist **divisor_tail,
             Dlist **quot_head, Dlist **quot_tail)
{
    if (!*divisor_head || ((*divisor_head)->data == 0 && !(*divisor_head)->next))
    {
        printf("Error: Dividing any number by 0 is not possible!.\n");
        return FAILURE;
    }

    Dlist *partial_head = NULL, *partial_tail = NULL;
    Dlist *rem_head = NULL, *rem_tail = NULL;
    int count;

    Dlist *temp = *dividend_head;

    while (temp)
    {
        insert_at_last(&partial_head, &partial_tail, temp->data);
        remove_leading_zeros(&partial_head, &partial_tail);
        temp = temp->next;
        count = 0;
        
        while (compare(partial_head, *divisor_head) != SMALLER)
        {
            subtraction(&partial_head, &partial_tail,
                        divisor_head, divisor_tail,
                        &rem_head, &rem_tail);
            
            partial_head = rem_head;
            partial_tail = rem_tail;
            rem_head = rem_tail = NULL;
            count++;
        }

        insert_at_last(quot_head, quot_tail, count);
    }
    remove_leading_zeros(quot_head, quot_tail);
    deletelist(&partial_head, &partial_tail);
    return SUCCESS;
}