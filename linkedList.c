#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct_t *head = NULL;

struct_t *Create_Node(int data)
{
    struct_t * new = (struct_t*)malloc(sizeof(struct_t));
    new->data = data;
    new->next = NULL;
    return new;
}

errorState_e Add_Node_To_Head(int data)
{
    struct_t* newNode = Create_Node(data);
    newNode->next = head->next;
    head->next = newNode;
    return FUNC_OK;
}
errorState_e Remove_From_Head(void)
{
    if (head->next == NULL)
    {
        return FUNC_EROR;
    }
    else
    {
        struct_t *temp = head->next;
        head->next = temp->next;
        free(temp);
        return FUNC_OK;
    }
}

errorState_e Add_Node_To_Tail(int data)
{
    struct_t* newNode = Create_Node(data);
    struct_t* currentNode = head;
    while(currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return FUNC_OK;
}

errorState_e Remove_From_Middle(int data)
{
    struct_t*currentNode = head;
    struct_t*previousNode = NULL;
    struct_t*temp = NULL;
    while (currentNode !=NULL)
    {
        if (currentNode->data ==data)
        {
            previousNode->next = currentNode->next;
            free(currentNode);
            return FUNC_OK;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

errorState_e Print_LinkedList(void)
{
    struct_t*currentNode = head;
    while (currentNode !=NULL)
    {
        printf("%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    return FUNC_OK;
}

int main()
{
    head = Create_Node(30);
    Add_Node_To_Head(20);
    Add_Node_To_Head(50);
    Add_Node_To_Head(70);
    Print_LinkedList();
    printf("\n");
    Remove_From_Head();
    Print_LinkedList();
    printf("\n");
    Remove_From_Middle(50);
    Print_LinkedList();
    printf("\n");
    Add_Node_To_Tail(100);
    Print_LinkedList();
    printf("\n");
    return 0;
}