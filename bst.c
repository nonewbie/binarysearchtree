#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isnull(const struct BSTnode* pt)
{
	if(pt == NULL){
		return 1;
	}
	return 0;
}
struct BSTnode* newnode(const DataType value)
{
	struct BSTnode * pbst = (struct BSTnode*)  malloc(sizeof(struct BSTnode));
	pbst->data = value;
	pbst->pnode = NULL;
	pbst->lnode = NULL;
	pbst->rnode = NULL;	
	return pbst;
}

int BSTadd(struct BSTnode * pbst,const DataType value)
{
	if( isnull(pbst) ){
		return -1;
	}

	if(value == pbst->data){// already had the member data==value
		return 0;
	}

	while(1) {
//__WHERE__;
		if(value == pbst->data)// already had the member data==value
			return 0;
		if(value < pbst->data){
			if(pbst->lnode == NULL){
				pbst->lnode = newnode(value);
				pbst->lnode->pnode = pbst;
				//pbst->lnode = (struct BSTnode *) malloc(sizeof(struct BSTnode));
				//memset(pbst->lnode,0x00,sizeof(struct BSTnode));
				//pbst->lnode->data = data;
				//printf("%d\n",pbst->lnode->data);
				break;
 			}else{
				pbst = pbst->lnode;
			}
		}else{
			if(pbst->rnode == NULL){
				pbst->rnode = newnode(value);
				pbst->rnode->pnode = pbst;
				//printf("%d\n",pbst->rnode->data);
				//pbst->rnode = (struct BSTnode *) malloc(sizeof(struct BSTnode));
				//memset(pbst->rnode,0x00,sizeof(struct BSTnode));
				//pbst->rnode->data = data;
				break;
 			}else{
				pbst = pbst->rnode;
			}
		}//enif
	}//endwhile
	return 1;
}
int BSTsearch(const struct BSTnode * pt,const DataType key)// recurency implementation
{
	static int recdeep = 0;// count the recerency deepth
	recdeep ++;
	if( isnull(pt) ){
		if(1 == recdeep){
			recdeep = 0;
			return -1;// the intput (pt) is null;
		}
		else{
			recdeep = 0;
			return 0;// the pt doesn't contain the key;
		}
	}
	const struct BSTnode * pbst = pt;
	if( key == pbst->data){
		printf("[deepth: %d]\t",recdeep);
		BSTsearch(pbst->rnode,key);//keep searching
		recdeep = 0;
		return 1;//the pt does constain the key;
	}else if(key < pbst-> data){
		//printf("%d\t",pbst->data);
		return BSTsearch(pbst->lnode,key);
	}else{
		//printf("%d\t",pbst->data);
		return BSTsearch(pbst->rnode,key);
	}
}
int BSTvisit(struct BSTnode* pt,const VisitOrder vo,VisitFunc vf)
{
	static int recdeep = 0;//recurency deepth
	recdeep++;
	if( isnull(pt) ){
		if(1 == recdeep){
			recdeep--;
			return -1;
		}
		else{
			recdeep--;
			return 1;
		}
	}
	switch(vo){
		case(PREORDER):
			printf("[deepth : %d]\t",recdeep);
			vf(pt);	
			BSTvisit(pt->lnode,vo,vf);
			BSTvisit(pt->rnode,vo,vf);
			break;
		case(INORDER):
			BSTvisit(pt->lnode,vo,vf);
			printf("[deepth : %d]\t",recdeep);
			vf(pt);	
			BSTvisit(pt->rnode,vo,vf);
			break;
		case(POSTORDER):
			BSTvisit(pt->lnode,vo,vf);
			BSTvisit(pt->rnode,vo,vf);
			printf("[deepth : %d]\t",recdeep);
			vf(pt);	
			break;
	}
	recdeep--;
	return 1;
}

void printdata(struct BSTnode * pt)
{
	if( isnull(pt) )//it will not print the data when the pt is NULL;
		return ;
	printf("[addr:%p \tdata : %d]\n",pt,pt->data);
	return ;
}

/**
 * @brief 	: free the one node of space;(the function is passed to the BSTvisit();
 *
 * @param pt	: the node to be free;the pt is not NULL
 */
void freenode(struct BSTnode *pt)
{
	free(pt);	
	pt=NULL;
	return ;
}

int freebst(struct BSTnode * pt)
{
	return	BSTvisit(pt,POSTORDER,freenode);
}

int delnode(struct BSTnode *pt)
{
	if( isnull(pt)){
		return -1;
	}
	
}
int BSTdel(struct BSTnode *pt,const DataType key)
{
	if( isnull(pt) ){
		return -1;
	}

	while(!(isnull(pt)) ) {
		if(key == pt->data){
			if( isnull(pt->lnode) && isnull(pt->rnode) ) {//neither has rchild nor the lchild;
				if( !isnull(pt->pnode) ){//pt is not the root node.
					if(pt->pnode->lnode == pt){
						pt->pnode->lnode = NULL;
					}
					else{
						pt->pnode->rnode = NULL;	
					}
				}else{// pt is the root node;return -1,cause the heap space can't free;
					return -1;
				}
				free(pt);
				return 1;
			}//if( isnull(pt->lnode) && isnull(pt->rnode) )
			else if( !isnull(pt->rnode) ){//has the rchild;
				struct BSTnode * temp = pt->rnode;//search the pt's rchild's farstest lchild;
				while( !isnull(temp->lnode) ) {
					temp = temp->lnode;
				}
				pt->data = temp->data;
				if(temp->pnode == pt){
					pt->rnode = temp->rnode;
					if( !isnull(temp->rnode) ){
						temp->rnode->pnode = pt;
					}
				}else{
					temp->pnode->lnode = NULL;
				}
				free(temp);
				return 1;
			}
			else{//has the lchild;
				struct BSTnode * temp = pt->lnode;
				while( !isnull(temp->rnode) ) {//search the pt's lchild's farstest rchild;
					temp = temp->rnode;
				}
				pt->data = temp->data;
				if(temp->pnode == pt){
					pt->lnode = temp->lnode;
					if( !isnull(temp->lnode) ){
						temp->lnode->pnode = pt;
					}
				}else{
					temp->pnode->rnode = NULL;
				}
				free(temp);
				return 1;
			}
		}//if(key == pt->data)
		else if(key < pt->data){
			pt = pt->lnode;	
		}
		else{
			pt = pt->rnode;	
		}
	}//	while(!(isnull(pt)) )
	return 0;//the bstree has no node'member data == key;
}
