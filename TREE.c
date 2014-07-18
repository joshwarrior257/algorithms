#include "TREE.h"

link NEW(Item item ,link left, link right, int count)
{
 link x = malloc(sizeof *x);
 x->data = item;
 x->left = left;
 x->right = right;
 x->nodeCount = count;
 return x;
 }

T TREEinit()
{
 T tree = malloc(sizeof *tree);
 tree->leaf_null = NEW(NULLitem, NULL, NULL, 0);
 tree->root = tree->leaf_null;
 return tree;
}

int TREEnodeCount(T tree)
{
 return (tree->root)->nodeCount;
}

int TREEempty(T tree)
{
 return tree->root == tree->leaf_null;
}

void TREEinsert(T tree, Item item)
{
 tree->root = TREEinsertR(tree->root, item, tree->leaf_null);
 return;
}

link TREEinsertR(link x, Item item, link leaf_null)
{
 if (x == leaf_null)
    return NEW(item, leaf_null, leaf_null, 1);
 if (x->data > item)
    x->left = TREEinsertR(x->left, item, leaf_null);
 else 
    x->right = TREEinsertR(x->right, item, leaf_null);
 
 (x->nodeCount)++;

 return x;
}

link TREEsearch(T tree, Item item)
{
 return TREEsearchR(tree->root, item);
}

link TREEsearchR(link x, Item item)
{
 if (x->data == NULLitem)
	 return NULLitem;
 if (x->data == item)
    return x;
 if (item < x->data)
   x = TREEsearchR(x->left, item);
 else
   x = TREEsearchR(x->right, item);

 return x;
}

void TREEsort(T tree, void (*visit)(Item))
{
 TREEsortR(tree->root, visit, tree->leaf_null);
 return;
}

void TREEsortR(link x, void (*visit)(Item), link leaf_null)
{
 if (x == leaf_null)
    return;
 else
 {
    TREEsortR(x->left, visit, leaf_null);
    visit(x->data);
    TREEsortR(x->right, visit, leaf_null);
 }
}

int TREEcountRecursive(T tree)
{
 return countRecursive(tree->root, tree->leaf_null);
}

int countRecursive(link x, link leaf_null)
{
 if (x == leaf_null)
    return 0;
 else
    return countRecursive(x->left, leaf_null) + countRecursive(x->right, leaf_null) + 1;
}

int TREEheight(T tree)
{
 return TREEheightR(tree->root, tree->leaf_null);
}

int TREEheightR(link x, link leaf_null)
{
 int u, v;

 if (x == leaf_null)
     return -1;
 u = TREEheightR(x->left, leaf_null);
 v = TREEheightR(x->right, leaf_null);
 
 if (u > v)
     return u + 1;
 else 
     return v + 1;
}

/*Internal function to update count at node*/
int countupdate(link x)
{
 return ((x->left->nodeCount) + (x->right->nodeCount) + 1);
}

/*Left or right rotation function*/
link rotR(link x )
{
 link y = x->left;
 x->left = y->right;
 y->right = x;
 x->nodeCount = countupdate(x);
 y->nodeCount = countupdate(y);
 return y;

 }

link rotL(link x)
{
 link y = x->right;
 x->right = y->left;
 y->left = x;
 x->nodeCount = countupdate(x);
 y->nodeCount = countupdate(y);
 return y;
 }

void TREEinsertroot(T tree, Item item)
{
 tree->root = TREEinsertrootR(tree->root, item, tree->leaf_null);
}

link TREEinsertrootR(link x, Item item, link leaf_null)
{
 if (x == leaf_null)
     return NEW(item, leaf_null, leaf_null, 1);
 if ( item < x->data)
    {
     x->left = TREEinsertrootR(x->left, item, leaf_null);
     x = rotR(x);
    }
  else
    {
     x->right = TREEinsertrootR(x->right, item, leaf_null);
     x = rotL(x);
    }
 return x;
}


Item TREEselect(T tree, int k)
{
 return TREEselectR(tree->root, k, tree->leaf_null);
}

Item TREEselectR(link x, int k, link leaf_null)
{
	int t ;
	if ( x == leaf_null )
		return NULLitem;
	t = x->left->nodeCount;
	if (t > k)
		return TREEselectR(x->left, k, leaf_null);
	if (t < k)
		return TREEselectR(x->right, k - t - 1, leaf_null);
	return x->data;
}


link TREEpartition(link x, int k)
{
 int t = x->left->nodeCount;
 
 if (t > k)
   {
     x->left = TREEpartition(x->left, k);
     x = rotR(x);
   }
 if (t < k)
   {
    x->right = TREEpartition(x->right, k-t-1);
    x = rotL(x);
   }
 return x;
}

link TREEjoinLR(link a, link b, link leaf_null)
{
 if (b == leaf_null)
     return a;
 b = TREEpartition(b, 0);
 b->left = a;
 b->nodeCount = countupdate(b);
 return b;
}

void TREEdelete(T tree, Item item)
{
 tree->root = TREEdeleteR(tree->root, item, tree->leaf_null);
}

link TREEdeleteR(link x, Item item, link leaf_null)
{
 link temp;

 if (x == leaf_null)
    {
     printf("leaf not found\n");
    return leaf_null;
    }
 if (item < x->data)
    x->left = TREEdeleteR(x->left, item, leaf_null);
 if (item > x->data)
    x->right = TREEdeleteR(x->right, item, leaf_null);
 if (item == x->data)
   {
    temp = x;
    x = TREEjoinLR(x->left, x->right, leaf_null);
    printf("deleted node %d\n", temp->data);
    free(temp);
    }
 if ( x != leaf_null)
     x->nodeCount = countupdate(x);
 return x;
}

void TREEclear(T tree)
{
 while (tree->root != tree->leaf_null)
      TREEdelete(tree, tree->root->data);
}

void TREEdestroy(T tree)
{
 TREEclear(tree);
 printf("Tree clear\n");
 free(tree);
 printf("Tree destroy\n");
}

Item TREEminvalue(T tree)
{
 return TREEminvalueR(tree->root, tree->leaf_null);
}

Item TREEminvalueR(link x, link leaf_null)
{
    if (x->left == leaf_null)
        return x->data;
    else
        return TREEminvalueR(x->left, leaf_null);
}

Item TREEmaxvalue(T tree)
{
 return TREEmaxvalueR(tree->root, tree->leaf_null);
}

Item TREEmaxvalueR(link x, link leaf_null)
{
    if (x->right == leaf_null)
        return x->data;
    else
        return TREEmaxvalueR(x->right, leaf_null);
}

BOOL TREEhaspathsum(T tree, int sum)
{
 return TREEhaspathsumR(tree->root, sum, tree->leaf_null);
}

BOOL TREEhaspathsumR(link x, int sum, link leaf_null)
{
 if (x == leaf_null)
    return (sum == 0);
 else
    return (TREEhaspathsumR(x->left, sum - x->data, leaf_null)||\
            TREEhaspathsumR(x->left, sum - x->data, leaf_null));
}

void TREEmirror(T tree)
{
 TREEmirrorR(tree->root, tree->leaf_null);
}

void TREEmirrorR(link x, link leaf_null)
{
 link temp;
 if (x == leaf_null)
   return;
 else
  {
   TREEmirrorR(x->left, leaf_null);
   TREEmirrorR(x->right, leaf_null);
   temp = x->left;
   x->left = x->right;
   x->right = temp;
  }
 return;
}

BOOL TREEissame(T tree1, T tree2)
{
 return TREEissameR(tree1->root, tree1->leaf_null,\
                    tree2->root, tree2->leaf_null);
}

BOOL TREEissameR(link x, link null_x, link y, link null_y)
{
 static BOOL bit = BOOLEAN_YES;

 if ((x == null_x)||(y == null_y))
    return (x->data == y->data);
 else
   {
    bit = bit && (TREEissameR(x->left, null_x, y->left, null_y));
    bit  = bit && (x->data == y->data);
    bit = bit && (TREEissameR(x->right, null_x, y->right, null_y));
   }
  return bit;
}

