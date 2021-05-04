/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		fflush(stdout);
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			fflush(stdout);
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{	//왼쪽에서 root 오른쪽의 순서로 재귀함수를 이용하여 전부 출력, 정렬의 형태로 값이 출력됨.
	if (ptr != NULL) // 만약 ptr이 NULL이 아니라면
	{
		inorderTraversal(ptr->left); //ptr의 left를 재귀함수에 보내줌
		printf("[%d]", ptr->key); //ptr의 key값을 출력함
		inorderTraversal(ptr->right); //ptr의 right를 재귀함수에 보내줌
		return 0;
	}

}

void preorderTraversal(Node* ptr)
{	//root를 가장 먼저 방문하고 왼쪽, 오른쪽의 순으로 값이 출력된다. 재귀함수를 이용해서 나머지 순회방식과 순서를 다르게하여 구현할 수 있다.
	if (ptr != NULL)
	{
		printf("[%d]", ptr->key); //ptr의 key값을 출력함
		preorderTraversal(ptr->left); //ptr의 left값을 재귀함수에 보냄
		preorderTraversal(ptr->right); //ptr의 rigth값을 재귀함수에 보냄
		return 0;
	}

}

void postorderTraversal(Node* ptr)
{	//왼쪽, 오른쪽, root의 순으로 값이 출력됨
	if (ptr != NULL)
	{
		postorderTraversal(ptr->left); //ptr의 left값을 재귀함수에 보내줌
		postorderTraversal(ptr->right); //ptr의 right값을 재귀함수에 보내줌
		printf("[%d]", ptr->key); // ptr의 key값을 출력함
		return 0;
	}

}


int insert(Node* head, int key)
{
	return 0;
}

int deleteLeafNode(Node* head, int key)
{
	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
	return 0;
}

Node* searchIterative(Node* head, int key)
{
	return 0;
}


int freeBST(Node* head)
{
	return 0;
}
