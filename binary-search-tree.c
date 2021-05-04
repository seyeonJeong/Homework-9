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
		return;
	}

}

void preorderTraversal(Node* ptr)
{	//root를 가장 먼저 방문하고 왼쪽, 오른쪽의 순으로 값이 출력된다. 재귀함수를 이용해서 나머지 순회방식과 순서를 다르게하여 구현할 수 있다.
	if (ptr != NULL)
	{
		printf("[%d]", ptr->key); //ptr의 key값을 출력함
		preorderTraversal(ptr->left); //ptr의 left값을 재귀함수에 보냄
		preorderTraversal(ptr->right); //ptr의 rigth값을 재귀함수에 보냄
		return ;
	}

}

void postorderTraversal(Node* ptr)
{	//왼쪽, 오른쪽, root의 순으로 값이 출력됨
	if (ptr != NULL)
	{
		postorderTraversal(ptr->left); //ptr의 left값을 재귀함수에 보내줌
		postorderTraversal(ptr->right); //ptr의 right값을 재귀함수에 보내줌
		printf("[%d]", ptr->key); // ptr의 key값을 출력함
		return ;
	}

}


int insert(Node* head, int key)
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->key = key;
	Node* root = head->left;

	if (head->left == NULL) //헤더노드의 left가 NULL이면 (트리에 노드가 없음, 첫노드를 삽입)
	{
		head->left = n1; //헤더노드의 left 가 n1이 된다.
		n1->left = NULL; //n1의 left와 right를 NULL값으로 설정
		n1->right = NULL;
		return 0;
	}
	while (root != NULL) // root의 값이 NULL일 때까지
	{
		if (key < root->key) //root의 key값보다 key값이 작을경우
		{
			if (root->left == NULL) // root의 left가 NULL일 경우
			{
				root->left = n1; //n1은 root의 left
				n1->left = n1->right = NULL; //n1의 left와right를 NULL로 초기화
				break; //반복문을 나감
			}
			else {
				root = root->left; //root의 left값이 NULL이 아니라면 root의 값을 root의 왼쪽노드로 이동

			}

		}
		else if (key > root->key) // root의 key값보다 key값이 클경우
		{
			if (root->right == NULL) { // root의 right가 NULL일 경우
				root->right = n1; //root의 right는 n1이 됨
				n1->left = n1->right = NULL; //n1의 left와 right를 NULL로 초기화
				break;
			}
			else {
				root = root->right; //root의 right값이 NULL이 아니라면 root의 값을 root의 오른쪽노드로 이동

			}

		}
	}
	return 0;

}

int deleteLeafNode(Node* head, int key)
{
	Node* node = head->left;
	Node* parents = NULL; //삭제시 사용될 부모노드를 가리킬 포인터를 정의하고 초기화

	if (node == NULL) // 헤드 왼쪽 root노드가 NULL이라면 노드가 존재하지 않는다.
	{
		printf("삭제할 노드가 존재하지 않습니다.\n");
		return 0;
	}
	while (node != NULL) // node가 NULL값이 아닐 때까지 반복
	{
		if (node->key > key) //node의 key값이 key값보다 큰경우
		{
			parents = node; // node가 가리키는 노드를 부모노드가 가리키게 함
			node = node->left; //node가 가리키는 노드를 왼쪽노드로 이동
		}
		else if (node->key < key) //node의 key값이 key값보다 작은경우
		{
			parents = node; //node가 가리키는 노드를 부모노드가 가리키게함
			node = node->right; //node가 가리키는 노드를 오른쪽노드로 이동
		}
		else //node의 key값이 key값과 같은경우(일단 삭제할 노드를 찾아냈다)
		{
			if (node->right == NULL && node->left == NULL)//만약 node의 right값이 NULL 이고 node의 left값이 NULL이면 조건문이 실행(말단 노드의 조건)
			{
				if (node == head->left) //만약 node가 헤드노드의 left라면? 해당 노드는 root노드이다. root노드의 right=left=NULL이라면 노드는 root빼고는 존재하지 않음
				{
					free(node); //node에 해당하는 노드를 해제시켜주고 반복문을 나간다(삭제완료)
					break;
				}
				else if(parents->right == node) //부모노드의 오른쪽이 node라면
				{
					parents->right = NULL; // 부모노드의 right가 가리키는 값을 NULL로 변환(삭제하려는 노드와 이어진 포인트 연결을 해제)
					free(node);//node를 해제시켜주고 반복문을 나간다(삭제완료)
					break;
				}
				else if (parents->left == node) //부모노드의 left가 가리키는 값이 node라면
				{
					parents->left = NULL; //부모노드의 left가 가리키는 값을 NULL로 변환(삭제하려는 노드와 이어진 포인터 연결을 해제)
					free(node); //node를 해제시켜주고 반복문을 나간다(삭제완료)
					break;
				}

			}
			printf("해당 노드는 말단 노드가 아닙니다.\n"); //node의 key값이 key값과 같지만 right와 left의 값이 NULL이 아닌경우(말단 노드의 조건에 부합하지 않음) 안내문구를 출력후 조건문을 나감
			break;

		}
	}
	if (node == NULL) // node가 NULL이 되었지만 조건에 부합하는 노드가 존재하지 않는 경우(삭제할 노드가 존재하지 않는 경우)
	{
		printf("삭제할 노드가 존재하지 않습니다.\n"); //안내문구를 출력
		return 0;
	}


	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
	if (ptr == NULL) // 노드가 존재하지 않거나, 재귀함수의 반복의 결과 key값과 일치하는 노드가 존재하지 않을경우 출력.
	{
		printf("key값과 일치하는 노드가 존재하지 않습니다.\n");
		return 0;
	}
	else if (ptr->key == key) // 재귀의 결과 ptr의 key 값이 key값과 같거나, root노드의 key값이 key값과 일치할 경우 ptr을 반환
	{
		return ptr;
	}
	else if (ptr->key > key) // ptr의 key값이 key값보다 큰경우
	{
		searchRecursive(ptr->left, key); //ptr을 왼쪽노드로 옮겨주고 재귀함수를 실행
	}
	else // ptr의 key값이 key값보다 큰경우
	{
		searchRecursive(ptr->right, key); //ptr을 오른쪽노드로 옮겨주고 재귀함수를 실행
	}

}

Node* searchIterative(Node* head, int key)
{
	Node* root = head->left;
	if (root == NULL) //만약 root가 NULL이라면 (노드가 존재하지 않음)
	{
		printf("노드가 존재하지 않습니다.\n"); //노드가 존재하지 않다는 문구 출력
		return 0;
	}
	while (root != NULL) //root가 NULL값이 될때까지 반복
	{
		if (root->key == key) //만약 root의 key값이 key값과 같다면
		{
			return root; //root를 반환 (검색을 완료함)
			break;
		}
		else if (root->key > key) // root의 key값이 key값보다 크다면
		{
			root = root->left; // root를 root의 왼쪽노드로 옮김
		}
		else if(root->key < key) //root의 key값이 key값보다 작다면
		{
			root = root->right; //root를 root의 오른쪽노드로 옮김
		}

	}
	if (root == NULL) //root가 NULL값이 되었는데 key값이 없을경우
	{
		printf("key값에 해당하는 노드가 존재하지 않습니다.\n"); //안내문구를 출력
		return 0;
	}
	return 0;
}



int freeBST(Node* head)
{
	if (head == NULL) // head가 NULL일 경우
	{
		return 0; //리턴
	}
	else if (head != NULL && head->left != NULL) // head가 NULL이 아니고 head의 left가 NULL이 아닐경우
	{
		freeBST(head->left); //재귀함수에 head의 left값을 줌
	}
	else if (head != NULL && head->right != NULL && head->right != head) // head가 NULL이 아니고 head의 right가 NULL이 아니고 head의 right값이 head가 아닐경우 (세번째 조건은 마지막 헤더노드를 초기화할 때 헤더노드는 자기자신을 가리키므로 재귀함수로 다시 들어가는 것을 방지하기 위한 조건)
	{
		freeBST(head->right); //재귀함수에 head의 right값을 줌
	}
	free(head); // head노드를 해제함


	return 0;
}
