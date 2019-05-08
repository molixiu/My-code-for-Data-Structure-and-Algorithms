#include<stdio.h>
#include"binary_sort_tree.h"


int main()
{
	 BTNode *root = NULL;
	 BTNode *parent = NULL;
	 Data data;
	 for(int i = 0; i < 10; i++)
	 {
		data.key = i;
		data.value = 65 + i;
		push(data, &root, &parent);
	 }

	 BTNode *search = NULL;
	 BTNode *searchParent = NULL;
	 int success =searchEle(2, root, parent, &search, &searchParent);
	 printf("%d\n", success);


	 BTNode *max = NULL;
	 BTNode *maxParent = NULL;
	 if(getMax(root,parent, &max, &maxParent));
		printf("%d\t%d\n", max->data.key, maxParent->data.key);


	deleteNode(&root, 0);
	 return 0;
}