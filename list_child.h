#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct DataMotor
{
    int tahunMotor;
    string NamaMotor, ID;
};


typedef DataMotor infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
};


void createListChild(List_child &L);
void insertFirstChild(List_child &L, address_child P);
void insertLastChild(List_child &L, address_child P);
void insertAfterChild(List_child &L, address_child Prec, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteLastChild(List_child &L, address_child &P);
void deleteAfterChild(List_child &L, address_child Prec, address_child &P);

void inputDataMotor(infotype_child &x);

address_child alokasiChild(infotype_child x);
void dealokasiChild(address_child &P);
address_child findElmChild(List_child L, infotype_child x);
void printInfoChild(List_child L);

void DataM(List_child &LC);

#endif // LIST_CHILD_H_INCLUDED
