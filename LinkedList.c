#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;  
};

struct Node *head;
static int countNode = 0;
void pushOnListAtEnd( int value);
void pushOnListAtStart(int value);
void findIndexOfItem(int value);
void pushOnMiddle(int value);
void printList(int value);
void menu();

int main()
{

    void (*funcPtr[])(int) = {pushOnListAtStart,pushOnListAtEnd,pushOnMiddle,findIndexOfItem,printList};
    head = (struct Node *)malloc(sizeof(struct Node));
    countNode++;
    // menu();
    int choise = 0;
    scanf(" %d",&choise);    if(choise == 1)
    {
        funcPtr[0](5);
        funcPtr[0](6);
        funcPtr[0](7);
        funcPtr[0](8);
        funcPtr[2](4);
        funcPtr[4](1);
    }
    return 0;
}


void pushOnListAtStart(int value)
{
    struct Node *tmp;
    struct Node *insertNode;
    insertNode = (struct Node*)malloc(sizeof(struct Node));
    if(insertNode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    insertNode->data = value;
    insertNode->next = head;
    head = insertNode;
    countNode++;
}
void pushOnListAtEnd(int value)
{        
    struct Node *node = head;
    struct Node *tmpNode;
    tmpNode = (struct Node *) malloc(sizeof(struct Node));
    tmpNode->next = NULL;
    tmpNode->data = value;
    while(node->next!=NULL)
    {
        node = node->next;
    }
    node->next = tmpNode;
    countNode++;
}
void printList(int value)
{
    struct Node *tmpNode;
    tmpNode = head;
    while(tmpNode!=NULL)
    {
        printf("List Values: %d->",tmpNode->data);
        tmpNode = tmpNode->next;
    }
    printf("\n Number of Nodes: %d",countNode);
}

void findIndexOfItem(int value)
{
    struct Node *tmp = head;
    int id=0;
    while(tmp!=NULL)
    {
        if(tmp->data == value)
        {
            printf("The index of the Node is: %d\n", id);
            break;
        }
        id++;
        tmp = tmp->next;
    }
}

void pushOnMiddle(int value)
{
    struct Node *tmp = head;
    struct Node *insertNode;
    insertNode = (struct Node*)malloc(sizeof(struct Node));
    if(insertNode == NULL)
    {
        printf("Problem to allocate Memory");
        return;
    }
    insertNode->data = value;
    int index = ((countNode%2)==0) ? countNode/2 : (countNode+1)/2;
    printf("Index %d" ,index);
    while(index-- >1)tmp = tmp->next;

    insertNode->next = tmp->next;
    tmp->next = insertNode;
}

void menu()
{
    printf("1.Insert at the end of the List\n2.Insert at the start of the List\n3.Display the List");
}