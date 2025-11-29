#include <stdio.h>
#include <ctype.h>
#include "valid.h"

int main(int argc ,char *argv[])
{
    if(argc < 4)
    {
        errorprint();
        return 0;
    }
    char *ptrop1=argv[1];
    if( isvalid(ptrop1)  != 0)
    {
        errorprint();
        puts("operand 1 is not a digit");
        return 0;
    }
    char *ptrop2=argv[3];
    if(isvalid(ptrop2) != 0)
    {
        errorprint();
        puts("operand 2 is not a digit");
        return 0;
    }
    char *ptrop=argv[2];
    if( operator_check(ptrop) != 0)
    {
        puts("operators should be '+','-','x','/'");
        return 0;
    }
    
    Dlist *op1_head=NULL,*op1_tail=NULL,*op2_head=NULL,*op2_tail=NULL,*res_head=NULL,*res_tail=NULL;

    while(*ptrop1 != '\0')
    {
        insert_at_last(&op1_head,&op1_tail,(*ptrop1 -48));
        ptrop1++;
    }

    while(*ptrop2 != '\0')
    {
        insert_at_last(&op2_head,&op2_tail,( *ptrop2 - 48));
        ptrop2++;
    }
    print_list(op1_head);
    printf(" %s ",ptrop);
    print_list(op2_head);
    printf(" = ");

    switch (*ptrop)
    {
	case '+':
        if(addition(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS) 
        {
            print_list(res_head);
            printf("\n");
        }
        else
        puts("Addition not Possible");
	    break;

	case '-':	
        if(subtraction(&op2_head,&op2_tail,&op1_head,&op1_tail,&res_head,&res_tail) == SUCCESS && compare(op1_head,op2_head) == SMALLER) 
        {
            printf("-"); 
            print_list(res_head);
            printf("\n");
        }
        else
        {
            if(subtraction(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
            {
                print_list(res_head);
                printf("\n");
            }
        }
	    break;

	case 'x':
        if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
          print_list(res_head);
          printf("\n");
        }
	    break;

    case 'X':	
    if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
            print_list(res_head);
            printf("\n");
        }
	    break;

    case '*':	
    if(multiplication(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
            print_list(res_head);
            printf("\n");
        }
	    break;
        
	case '/':	
        if(division(&op1_head,&op1_tail,&op2_head,&op2_tail,&res_head,&res_tail) == SUCCESS)  
        {
            print_list(res_head);
            printf("\n");
        }
	    break;
	default:
	    printf("Invalid Input:-( Try again...\n");
    }
}