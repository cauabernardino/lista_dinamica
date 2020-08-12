/*
 ============================================================================
 Name        : list.c
 Author      : Cauã Bernardino
 Version     : 0.1.0
 Copyright   : 
 Description : Dynamic List and Bubble Sort
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Def structure for the linked list and vector
typedef struct node 
{
    int val;
    struct node * next;
} 
node;
#define MAX 100
int numbers[MAX];

// Functions declarations
void print_list(node * item);
node * add_item(node * item, int val);
void add_first(node ** item, int val);
void free_mem(node * item);
void sort(node * item);


// Main function
int main(int argc, char * argv[])
{   
    //Variables
    int number;
    char input[201];
    
    // First item of the list
    node * item = NULL;
    item = (node *) malloc(sizeof(node));

    if (item == NULL) 
    {
        return 1;
    }
		
    //Get command and value from prompt
    //It will repeat until right syntax
    do
    {               
        printf("prompt> ");
        scanf("%201s", input);
        
        // Exit status
        if (strncmp(input, "exit", 4) == 0)
        {
            break;
        }

        // Print list
        if (strncmp(input, "list", 4) == 0)
        {   
            print_list(item);
            printf("\n");
            continue;
        } 

        // Add value to the begin (first)
        if (strncmp(input, "sort", 4) == 0)
        {
            sort(item);
            printf("\n");
            continue;
        }
        
        scanf("%i", &number);

        // Add value (put)
        if (strncmp(input, "put", 3) == 0)
        {
            if (item->val == NULL)
            {
                item->val = number;
            }
            else
            {
                add_item(item, number);
            }
        }

        // Add value to the begin (first)
        if (strncmp(input, "first", 5) == 0)
        {
            add_first(&item, number);
        }

    } 
    while (1);

    free_mem(item);

    if (strncmp(input, "exit", 4) == 0)
    {
        printf("Leaving. Good bye.\n");
        return 2;
    }

}
        

// Function to print the items
void print_list(node * item)
{
    node * current = item;

    while (current != NULL) 
    {  
        printf("%i ", current->val);
        current = current->next;
    }
}


// Function to add items
node * add_item(node * item, int val)
{
    node * current = item;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (node *) malloc(sizeof(node));
    current->next->val = val;
    current->next->next = NULL;
    
    return current;
}

//Add item in the beginning

void add_first(node ** item, int val) 
{
    node * head;
    head = (node *) malloc(sizeof(node));
    
    head->val = val;
    head->next = *item;
    *item = head;  
}


// Free memory
void free_mem(node * item) 
{

    node * current = item;

    while (current != NULL)
    {   
        current = item->next;
        free(item);
        item = current;
    }    
}


// Bubble sort (for simplicity due time)

void sort(node * item) 
{
    node * current = item;
    int n = 0;

    while (current != NULL) 
    {  
        numbers[n] = current->val;
        current = current->next;
        n++;
    }

    int k, j, tmp;

    for (k = 1; k < n; k++) 
    {
        for (j = 0; j < n - k; j++) {

            if (numbers[j] > numbers[j + 1]) {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%i ", numbers[i]);
    }

}