#ifndef __TAOLIB__
#include "/home/song/taolib/maclib.h"
#endif

/**
 * @brief	: binary search tree struct;
 */
struct BSTnode
{
	DataType data;
	struct BSTnode * pnode;
	struct BSTnode * lnode;
	struct BSTnode * rnode;
};

/**
 * @brief 	:	double link list struct;
 */
struct DouList
{
	DataType data;
	struct	DouList * pnode;
	struct DouList * nnode;
};

/**
 * @brief	: mark the visit order;
 */
typedef enum { PREORDER = 0,INORDER,POSTORDER } VisitOrder;

typedef void (*VisitFunc)(struct BSTnode* );

/**
 * @brief	: create a new node who's member data equals value; 
 *
 * @param value	: the data to be inserted into;
 *
 * @return	:a new BSTnode* point to a new memery BSTnode and it's data member equials value; 
 */
struct BSTnode* newnode(const DataType value);

/**
 * @brief	:  BSTadd() is design to add a new member to the (bstnode) binary search tree 
 *
 * @param bstnode	: the binary tree start node*;
 * @param value		: the data to be inserted to; 
 *
 * @return	(int)	: -1 when the input(bstnode) is NULL, 0 when the bstree already had the member==value, 1 when the input(bstnode) is valide;
 */
int BSTadd(struct BSTnode * pbst,const DataType value);

/**
 * @brief	: search whether the bst has the member(key);
 *
 * @param pt	: the binnary search tree poniter,it can be each one of the binary tree node pointer; 
 * @param key	: the key to referenced;
 *
 * @return	: 0 if the bst has the key, 1 when bst hasn't the key; -1 when the input bst is invalide; 
 */
int BSTsearch(const struct BSTnode * pt,const DataType key);

/**
 * @brief	: visit each node of the pt,whlile call the function func; 
 *
 * @param pt	: the binnary search tree poniter;
 * @param vo	: the visit order;	
 * @param vf	: the operater function;
 *
 * @return	: 0 when the pt is NULL, 1 when the pt is not NULL; 
 */
int BSTvisit(struct BSTnode* pt,const VisitOrder vo,VisitFunc vf);

/**
 * @brief	: print the node's member: data;
 *
 * @param pt	: the bstree to be print. it can be non-head node;the pt is not NULL
 */
void printdata(struct BSTnode * pt);

/**
 * @brief	: free the heap space of the binary search tree; 
 *
 * @param pt	: the binary search tree to be free;
 *
 * @return	: -1 when the input pt is NULL, 1 when the input is not NULL; 
 */
int freebst(struct BSTnode * pt);

/**
 * @brief 	: delete the node whose member equals to the key;
 *
 * @param pt	: the bstree pointer;
 * @param key	: the key;
 *
 * @return 	: -1 when the bstree is NULL, 0 when the bstree is not NULL and has no member==key, 1 when bstree has the member==key and delete successed;
 */
int BSTdel(struct BSTnode *pt,const DataType key);

