#include "valid.h"

int isvalid(char *op)
{
    while(*op != '\0')
    {
        if(!isdigit(*op))
        return FAILURE;
        op++;
    }
    return SUCCESS;
}

int operator_check(char argv[])
{
    if(*argv  == '+' || *argv  == '-' ||  *argv  == 'x' || *argv  == 'X' || *argv  == '*' || *argv  == '/')
    return SUCCESS;

    return FAILURE;
}

void errorprint()
{
    puts("Argument should be : ");
    puts("./apc.exc <operand 1> <operator> <operand 2>\n");
    printf("Operations available:\n");
    printf("%-20s %s\n", "1. Addition", "(+)");
    printf("%-20s %s\n", "2. Subtraction", "(-)");
    printf("%-20s %s\n", "3. Multiplication", "(x)");
    printf("%-20s %s\n", "4. Division", "(\\)");
}


void deletelist(Dlist **head, Dlist **tail)
{
    if (head == NULL || *head == NULL)
        return;

    Dlist *temp = *head, *next;
    while (temp)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;
}

void copy_list(Dlist *src_head, Dlist **dest_head, Dlist **dest_tail)
{
    Dlist *temp = src_head;
    while (temp)
    {
        insert_at_last(dest_head, dest_tail, temp->data);
        temp = temp->next;
    }
}

int insert_at_last(Dlist **head,Dlist **tail,int data)
{
    Dlist *new =malloc(sizeof(Dlist));
    if (!new) return FAILURE;
        new->data=data;
        new->prev=NULL;
        new->next=NULL;

    if(*head == NULL && *tail == NULL)
    {
        *head=new;
        *tail=new;
    }
    else
    {
        (*tail)->next=new;
        new->prev= *tail;
        *tail=new;
    }
    return SUCCESS;
}

int insert_at_first(Dlist **head,Dlist **tail,int data)
{
    Dlist *new =malloc(sizeof(Dlist));
    if (!new) return FAILURE;
    new->data=data;
    new->prev=NULL;
    new->next=NULL;

    if(*head == NULL )
    {
        *head=new;
        *tail=new; 
    }

    else
    {
        (*head)->prev=new;
        new->next= *head;
        *head=new;
    }
    return SUCCESS;
}

void print_list(Dlist *head)                       
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        while (head)		
	    {
            printf("%d", head -> data);
		    head = head -> next;
        }
    }
}


int compare(Dlist *head1, Dlist *head2)
{
    // Compare lengths first
    int len1 = 0, len2 = 0;
    Dlist *t1 = head1, *t2 = head2;
    while(t1) 
    {
        len1++;
        t1 = t1->next;
    }
    while(t2)
    {
        len2++;
        t2 = t2->next;
    }

    if(len1 > len2) return GREATER;
    if(len1 < len2) return SMALLER;

    // Compare digit by digit from head
    while(head1 && head2)
    {
        if(head1->data > head2->data) return GREATER;
        if(head1->data < head2->data) return SMALLER;
        head1 = head1->next;
        head2 = head2->next;
    }
    return EQUAL;
}

int remove_leading_zeros(Dlist **res_head,Dlist **res_tail)
{
while (*res_head && (*res_head)->data == 0 && (*res_head)->next != NULL)
	{
    Dlist *temp = *res_head;
	if(!temp) return FAILURE;
    *res_head = (*res_head)->next;
    (*res_head)->prev = NULL;
    free(temp);
	}
    return SUCCESS;
}