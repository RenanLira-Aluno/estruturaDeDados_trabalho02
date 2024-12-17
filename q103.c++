#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <stdio.h>
#include <iostream>

typedef int Item;
typedef struct no
{
    Item item;
    struct no *prox;
} *Lista;

Lista no(Item x, Lista p)
{
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
};

void ins(Item x, Lista *L)
{
    while (*L != NULL && (*L)->item < x)
    {
        L = &(*L)->prox;
    }

    *L = no(x, *L);
};

void insSR(Item x, Lista *L)
{
    while (*L != NULL && (*L)->item < x)
    {
        L = &(*L)->prox;
    }

    if (*L == NULL || (*L)->item != x)
    {
        *L = no(x, *L);
    }
};

void exibe(Lista L)
{
    while (L != NULL)
    {
        std::cout << L->item << " ";
        L = L->prox;
    };
    std::cout << std::endl;
};

int main()
{
    Lista L = NULL;
    insSR(3, &L);
    insSR(12, &L);
    insSR(6, &L);
    insSR(12, &L);

    exibe(L);

    return 0;
};