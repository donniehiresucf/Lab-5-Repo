/* Donald Hires
COP3502-0004
Dr. Torosdagli
Lab 4 - Linked Lists and Files
Date: 06/09/2023 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node *next;
} node;

// Returns number of nodes in the linked list
int length(node* head)
{
    int length = 0;
    node *t = head;
    while (t != NULL)
    {
        length++;
        t = t->next;
    }
    return length;
}

// Parses the string in the linked list
// If the linked list is head -> |a|->|b|->|c|
// Then toCString function would return "abc"
char* toCString(node* head)
{
    char *string = (char*) malloc(length(head)*sizeof(char));
    int i = 0;
    node *t = head;
    while (t != NULL) 
    {
        string[i] = t->letter;
        i++;
        t = t->next;
    }
    string[i] = '\0';
    return string;
}

// Insert character to the linked list
// If the linked list is head -> |a|->|b|->|c|
// Then insertChar(&head, 'x') would update the list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node *t;
    node *temp;
    temp = (node*) malloc(sizeof(node));
    temp->letter = c;
    temp->next = NULL;
    if (*pHead == NULL)
        *pHead = temp;
    else
    {
        t = *pHead;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

// Deletes all nodes in the linked list
void deleteList(node** pHead)
{
    node *t = *pHead;
    node *temp;
    
    while (t != NULL)
    {
        temp = t->next;
        free(t);
        t = temp;
    }

    *pHead = NULL;
}

int main(int argc, char **argv)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, "%d\n", &numInputs);

    while (numInputs-- > 0)
    {
        fscanf(inFile, "%d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, "%c", &c);
            insertChar(&head, c);
        }

        str = toCString(head);
        printf("String is: %s\n", str);

        free(str);
        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
    
    return 0;
}

