#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include "ITEM.h"

#define NULLitem 0
#define BOOLEAN_YES 1
#define BOOLEAN_NO  0

typedef int BOOL;
typedef struct TREEnode *link;
struct TREEnode
{
 Item data;
 link left;
 link right;
 int nodeCount;
};

typedef struct TREE *T;
struct TREE
{
 link root;
 link leaf_null;
};

link NEW(Item item ,link left, link right, int count);
T TREEinit();
int TREEnodeCount(T tree);
int TREEempty(T tree);
void TREEinsert(T tree, Item item);
link TREEinsertR(link x, Item item, link);
link TREEsearch(T tree, Item item);
link TREEsearchR(link x, Item item);
void TREEsort(T tree, void (*visit)(Item));
void TREEsortR(link x, void (*visit)(Item), link);
int TREEcountRecursive(T tree);
int countRecursive(link x, link leaf_null);
int TREEheight(T tree);
int TREEheightR(link x, link leaf_null);
int countupdate(link x);
link rotR(link x );
link rotL(link x);
void TREEinsertroot(T tree, Item item);
link TREEinsertrootR(link x, Item item, link leaf_null);
Item TREEselect(T tree, int k);
Item TREEselectR(link x, int k, link leaf_null);
link TREEpartition(link x, int k);
link TREEjoinLR(link a, link b, link leaf_null);
void TREEdelete(T tree, Item item);
link TREEdeleteR(link x, Item item, link leaf_null);
void TREEclear(T tree);
void TREEdestroy(T tree);

Item TREEminvalue(T tree);
Item TREEminvalueR(link x, link leaf_null);

Item TREEmaxvalue(T tree);
Item TREEmaxvalueR(link x, link leaf_null);


BOOL TREEhaspathsum(T tree, int sum);
BOOL TREEhaspathsumR(link x, int sum, link leaf_null);

void TREEmirror(T tree);
void TREEmirrorR(link x, link leaf_null);

BOOL TREEissame(T tree1, T tree2);
BOOL TREEissameR(link x, link leaf_null_x, link y, link leaf_null_y);

#endif
