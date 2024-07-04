#ifndef LIKEDLIST_H_
#define LIKEDLIST_H_

typedef struct node
{
    int data;
    struct node *next;
}struct_t;

typedef enum
{
    FUNC_OK,
    FUNC_EROR
}errorState_e;


struct_t *Create_Node(int data);

errorState_e Add_Node_To_Head(int data);
errorState_e Remove_From_Head(void);

errorState_e Add_Node_To_Tail(int data);
errorState_e Remove_From_Middle(int data);

errorState_e Print_LinkedList(void);

#endif