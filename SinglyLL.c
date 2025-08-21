#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)       //case1
    {
        *head = newn;
    }
    else            //case 2
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if(*head == NULL)       
    {
        *head = newn;
    }
    else            
    {
        temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void DeleteLast(struct node** head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }

}


int CountNode(struct node* head)
{
    int iCount = 0;

    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }

    return iCount;
}


void Display(struct node* head)
{
    while(head != NULL)
    {
        printf("| %d |->\t", head->data);
        head = head->next;
    }
    printf("NULL\n");

}

void InsertAtPos(struct node** head, int no, int iPos)
{
    int iCount = CountNode(*head);
    PNODE newn = NULL;
    PNODE temp = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(head, no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(head, no);
    }
    else
    {
        newn = (struct node*)malloc(sizeof(struct node));
        newn->data = no;
        newn->next = NULL;

        temp = *head;

        for(int i = 0; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}


void DeleteAtPos(struct node** head, int iPos)
{
    int Count = 0;
    PNODE temp = NULL;
    PNODE target = NULL;

    Count = CountNode(*head);

    if(iPos < 1 || iPos > Count)
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(head);
    }
    else if(iPos == Count)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;

        for (int i = 0; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }

}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertLast(&first, 101);
    InsertLast(&first, 121);
    InsertLast(&first, 151);

    Display(first);
    iRet = CountNode(first);
    printf("Linkedlist nodes count : %d\n", iRet);

    InsertAtPos(&first, 23, 4);
    InsertAtPos(&first, 11, 5);

    Display(first);
    iRet = CountNode(first);
    printf("Linkedlist nodes count : %d\n", iRet);


    DeleteFirst(&first);
    Display(first);
    iRet = CountNode(first);
    printf("Linkedlist nodes count : %d\n", iRet);

    DeleteLast(&first);
    Display(first);
    iRet = CountNode(first);
    printf("Linkedlist nodes count : %d\n", iRet);

    DeleteAtPos(&first, 5);
    Display(first);
    iRet = CountNode(first);
    printf("Linkedlist nodes count : %d\n", iRet);


    return 0;
}
