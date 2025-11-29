/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "valid.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	int op1,op2,zero=0;
	Dlist *temp1 =*tail1;
	Dlist *temp2 = *tail2;

	Dlist *r1_head =NULL, *r1_tail =NULL;
	Dlist *r2_head =NULL, *r2_tail =NULL;
	Dlist *r3_head =NULL, *r3_tail =NULL;
	
	while(temp2 != NULL)
	{
		int carry=0 ,data=0;
		temp1 = *tail1;
		deletelist(&r2_head,&r2_tail);
				
		while(temp1 != NULL)
		{
			op1=temp1->data;
			op2=temp2->data;

			data = carry + (op1 * op2);
		
			carry=data/10;
			data=data%10;				

			insert_at_first(&r2_head,&r2_tail,data);  
			temp1=temp1->prev;
		}

		if(carry)
		insert_at_first(&r2_head,&r2_tail,carry);

		for(int i=0;i<zero;i++)
		insert_at_last(&r2_head,&r2_tail,0);
		
		if(r1_head ==NULL)	
		{
			r1_head= r2_head;
			r1_tail=r2_tail;

			r2_head=NULL;
			r2_tail=NULL;
		}
		else
		{
			addition(&r1_head,&r1_tail,&r2_head,&r2_tail,&r3_head,&r3_tail);
			
				deletelist(&r1_head,&r1_tail);
				deletelist(&r2_head,&r2_tail);
				
				r1_head = r3_head;
				r1_tail = r3_tail;
				r3_head=NULL;
				r3_tail=NULL;
		}
		zero++;
		temp2=temp2->prev;
	}
	*headR=r1_head;
	*tailR=r1_tail;
	
	return SUCCESS;
}
