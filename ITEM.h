#ifndef ITEM_H_
#define ITEM_H_

#include <stdio.h>

typedef int Item;

#define less(A, B)   ((A) < (B))
#define exch(A, B)   { Item temp = (A);\
	               (A) = (B);\
	               (B) = temp;\
                      }
void ITEMshow(Item);

#endif

