#ifndef VALID_H
#define VALID_H


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define EQUAL 2
#define GREATER 3
#define SMALLER 4




typedef struct node
{
    struct node *prev;
    struct node *next;
    char data;

}Dlist;

void errorprint(void);
void deletelist(Dlist **head,Dlist **tail);
int remove_leading_zeros(Dlist **res_head,Dlist **res_tail);
void copy_list(Dlist *src_head, Dlist **dest_head, Dlist **dest_tail);


int isvalid(char argv[]);
int operator_check(char argv[]);
int insert_at_last(Dlist **op,Dlist **op2,int data);
int insert_at_first(Dlist **head,Dlist **tail,int data);

void print_list(Dlist *head);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

int compare(Dlist *head1, Dlist *head2);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);


#endif
