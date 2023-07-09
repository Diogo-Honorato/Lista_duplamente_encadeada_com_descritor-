#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
    struct Cell *next;
    struct Cell *prev;
    int key;
}Cell;

typedef struct 
{
    Cell *first;
    Cell *last;
    int size;
}List;

List* AllocateList()
{
    return (List*)malloc(sizeof(List));
} 

int StartList(List *list)
{
    list->first = NULL;
    list->last = NULL; 
    list->size = 0;
    
    return 1;
}

int InsertList(List *list, int key)
{
    Cell *newcell = (Cell*) malloc(sizeof(Cell));
    newcell->key = key;
    newcell->next = NULL;
    newcell->prev = NULL;

    if(list->first == NULL)
    {
        list->first = newcell;
    }
    else
    {
        list->last->next = newcell;
        newcell->prev = list->last;
    }
    list->last = newcell;
    list->size++;

    return 1;
}

int RemoveList(List *list, int key)
{
    if(list->size == 0)
    {
        printf("\n\nEmpty list!\n\n");
        exit(0);
    }
    else if(list->first->key == key)
    {
        Cell *aux = list->first;
        list->first = list->first->next;
        free(aux);
    }
    else if(list->last->key == key)
    {
        Cell *aux = list->last;
        list->last = list->last->prev;
        aux->prev->next = NULL; 
        free(aux);
    }
    else
    {
        Cell *aux = list->first;
        while(aux->key != key && aux->next != NULL)
        {
            aux = aux->next;
        }
        if(aux->key == key)
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
        }
        else
        {
            printf("\n\nKey is not in the list to remove: %d\n\n",key);
        }     
    }
    list->size--;

    return key;
}

int SearchList(List *list,int key)
{
    if(list->size == 0)
    {
        printf("\n\nEmpty list!\n\n");
        exit(0);
    }

    if(list->first->key == key)
    {
        printf("\n\nKey was found: %d\n\n",key);
    }
    else if(list->last->key == key)
    {
        printf("\n\nKey was found: %d\n\n",key);
    }
    else
    {
        Cell *aux = list->first;
        while(aux->key != key && aux->next != NULL)
        {
            aux = aux->next;
        }
        if(aux->key == key)
        {
            printf("\n\nKey was found: %d\n\n",key);
        }
        else
        {
            printf("\n\nKey not found or key is not in the list: %d\n\n",key);
        }
    }
    return key;
}

void PrintList(List *list)
{
    printf("\n\n");
    if(list->size == 0)
    {
        printf("\n\nEmpty list!\n\n");
        exit(0);
    }

    Cell *aux = list->first;

    while(aux != NULL)
    {
        printf("(%d) ",aux->key);
        
        aux = aux->next;
    }
    printf("\n\n");
}

int main()
{
    List *list = AllocateList();
    int vet[] ={3,2,6,35,10,9,7,5,11};
    int tam = sizeof(vet)/sizeof(int);
    StartList(list);

    for(int i = 0; i < tam; i++)
    {
        InsertList(list,vet[i]);
    }
    printf("\n\nList\n");
    PrintList(list);

    RemoveList(list,3);
    RemoveList(list,11);
    RemoveList(list,10);
    RemoveList(list,80);

    SearchList(list,35);
    SearchList(list,74);

    printf("\nList after removals\n");
    PrintList(list);
}


