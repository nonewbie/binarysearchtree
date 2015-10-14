#include "../arrdata/arr.h"
#include "bst.h"
#include <stdio.h>
struct BSTnode * createbst()
{
	DataType arr[COUNT];
	createarr(arr,COUNT);
	printarr(arr,COUNT);

	struct BSTnode * bstree = newnode(arr[0]); 
	int i;
	for(i = 1;i < COUNT;i++) {
		BSTadd(bstree,arr[i]);
	}
	return bstree;
}	
void testcreate()
{
	DataType arr[COUNT];
	createarr(arr,COUNT);
	printarr(arr,COUNT);

	__DIVIDING__("test the BSTadd()");	

	struct BSTnode * bstree = newnode(arr[0]); 
	int i ;
	for(i = 1;i < COUNT;i++) {
		printf("valide pstree test.state : %d\n",BSTadd(bstree,arr[i]) );
	}

	struct BSTnode * nullbst = NULL;
	printf("null pointer test.state : %d\n",BSTadd(nullbst,arr[i]) );

	__DIVIDING__("end test BSTadd()");	


	__DIVIDING__("freebst()");	
	freebst(bstree);
	printf("\n");
	__DIVIDING__("freebst()");	
	return ;
}

void testvisit()
{
	struct BSTnode * bstree = createbst(); 

	__DIVIDING__("test the BSTvisit()");
	printf("valide bstree : %d\n",BSTvisit(bstree,INORDER,printdata) );
	struct BSTnode * nullbst = NULL;
	printf("null tree : %d\n",BSTvisit(nullbst,INORDER,printdata) );
	__DIVIDING__("end test the BSTvisit()");


	__DIVIDING__("freebst()");	
	freebst(bstree);
	printf("\n");
	__DIVIDING__("end freebst()");	
	return ;
}

void testsearch()
{
	DataType arr[COUNT];
	createarr(arr,COUNT);
	printarr(arr,COUNT);

	struct BSTnode * pbst = newnode(arr[0]); 
	int i;
	for(i = 1;i < COUNT;i++) {
		BSTadd(pbst,arr[i]);
	}
	__DIVIDING__("test BSTsearch()");	
	for(i = 0;i < COUNT;i++){
		printf ( "arr[%d] is in the bstree ? : %d\n" ,i,BSTsearch(pbst,arr[i]));
	}
	printf ( "-1 is in the bstree ? : %d\n" ,BSTsearch(pbst,-1));
	struct BSTnode * nullbst = NULL;
	printf ( "null tree ,arr[0] is in the bstree ? : %d\n" ,BSTsearch(nullbst,arr[0]));
	__DIVIDING__("end test BSTstart()");	

	__DIVIDING__("freebst()");	
	freebst(pbst);
	printf("\n");
	__DIVIDING__("end freebst()");	
	return ;
}
void testdel()
{
	const int count = 8;
	DataType arr[] = {6,2,10,1,3,9,8,4};
	//DataType arr[count] = {6,2,10,1,3,9,8};
	printarr(arr,count);
	struct BSTnode * pbst = newnode(arr[0]);
	int i = 0;
	for(; i < count;i++) {
		BSTadd(pbst,arr[i]);
	}
	printf("before del:\n");
	BSTvisit(pbst,INORDER,printdata);
	__DIVIDING__("test BSTdel()");
	//printf ( "BST(pbst,-1) : %d\n" ,BSTdel(pbst,-1));
	//printf ( "BST(pbst,1) : %d\n" ,BSTdel(pbst,1));
	//printf ( "BSTdel(pbst,2) : %d\n" ,BSTdel(pbst,2));
//	printf ( "BSTdel(pbst,10) : %d\n",BSTdel(pbst,10));
	for(i = 0;i < count; i++){
		printf ( "BSTdel(pbst,%d) : %d\n",arr[i],BSTdel(pbst,arr[i]));
	}

	printf("after del:\n");
	BSTvisit(pbst,INORDER,printdata);

	__DIVIDING__("end test BSTdel()");
}
int main()
{
	//testcreate();
//	testvisit();
	//testsearch();
	//testdel();
	return 0;
}
