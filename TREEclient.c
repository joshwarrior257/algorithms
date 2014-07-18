#include "ITEM.h"
#include "TREE.h"
#include "HELPER.h"

int main()
{
 int  i;
 Item num;

 T tree1 = TREEinit();
 T tree2 = TREEinit();
 RANDOM_Seed();

 for (i=1; i <= 5; i++)
 {
  num = RANDOM_Integer()%10;
  printf("%d ", num);
  TREEinsert(tree1, num);
 }
 printf("\n");
 for (i=1; i <= 5; i++)
 {
  num = RANDOM_Integer()%10;
  printf("%d ", num);
  TREEinsert(tree2, num);
 }

 printf("\n");

 TREEsort(tree1, ITEMshow);

 printf("\n");

 printf("\n");

 TREEsort(tree2, ITEMshow);

 printf("\n");

#if 0 
 printf("no of nodes %d\n", tree->root->nodeCount);
 printf("is node empty? %d\n", TREEempty(tree)); 

 printf(" does 5 exist? %d\n", (TREEsearch(tree, 5) != NULL));
 printf("no of node count recursive? %d\n", TREEcountRecursive(tree));

 printf("height of tree? %d\n", TREEheight(tree));
 
 /*
 printf("inserting item 8 at root of tree\n");
 TREEinsertroot(tree, 8);

 TREEsort(tree, ITEMshow);

 printf("\n");
 printf("no of nodes %d\n", tree->root->nodeCount);
 printf("root element %d\n", tree->root->data);
  printf("height of tree? %d\n", TREEheight(tree));
 */

 printf("select the kth %d element %d\n", 3, (TREEselect(tree, 3)));
 printf("select the kth %d element %d\n", 0, (TREEselect(tree, 0)));
 printf("select the kth %d element %d\n", 6, (TREEselect(tree, 6) == NULLitem));

 printf("delete item %d\n", 2);
 TREEdelete(tree, 2);
 TREEsort(tree, ITEMshow);
 printf("\n");
  printf("no of nodes %d\n", tree->root->nodeCount);
 printf("root element %d\n", tree->root->data);
  printf("height of tree? %d\n", TREEheight(tree));

  printf("min value %d\n", TREEminvalue(tree));

   printf("man value %d\n", TREEmaxvalue(tree));

   printf("has path of sum %d ? %d\n", 5, TREEhaspathsum(tree,5)); 
 
 printf("printing the TREE mirror\n");
 TREEmirror(tree);
 TREEsort(tree, ITEMshow);
 TREEclear(tree);
 printf("after clear\n");
  printf("no of nodes %d\n", tree->root->nodeCount);
 printf("root element %d\n", tree->root->data);
  printf("height of tree? %d\n", TREEheight(tree));

 TREEdestroy(tree);
#endif

 printf("is tree both same? %d\n", TREEissame(tree1, tree2));
 
 TREEdestroy(tree1);
 TREEdestroy(tree2);

 return 0;
 }
