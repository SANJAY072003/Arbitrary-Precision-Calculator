#include "valid.h"

int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **res_head, Dlist **res_tail)
{
    deletelist(res_head, res_tail);
    int borrow = 0;
    int op1, op2;
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    while (t1 || t2)
    {
        op1 = (t1) ? t1->data : 0;
        op2 = (t2) ? t2->data : 0;

        if (borrow) op1--;
        int data = (op1 < op2) ? (10 + op1 - op2) : (op1 - op2);
        borrow = (op1 < op2) ? 1 : 0;
        insert_at_first(res_head, res_tail, data);
        if (t1) 
		t1 = t1->prev;
        if (t2) 
		t2 = t2->prev;
    }
    remove_leading_zeros(res_head, res_tail);
    return SUCCESS;
}