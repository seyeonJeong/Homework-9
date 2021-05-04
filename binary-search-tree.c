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

	printf("----- [2018038027]  [������] -----");

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
{	//���ʿ��� root �������� ������ ����Լ��� �̿��Ͽ� ���� ���, ������ ���·� ���� ��µ�.
	if (ptr != NULL) // ���� ptr�� NULL�� �ƴ϶��
	{
		inorderTraversal(ptr->left); //ptr�� left�� ����Լ��� ������
		printf("[%d]", ptr->key); //ptr�� key���� �����
		inorderTraversal(ptr->right); //ptr�� right�� ����Լ��� ������
		return;
	}

}

void preorderTraversal(Node* ptr)
{	//root�� ���� ���� �湮�ϰ� ����, �������� ������ ���� ��µȴ�. ����Լ��� �̿��ؼ� ������ ��ȸ��İ� ������ �ٸ����Ͽ� ������ �� �ִ�.
	if (ptr != NULL)
	{
		printf("[%d]", ptr->key); //ptr�� key���� �����
		preorderTraversal(ptr->left); //ptr�� left���� ����Լ��� ����
		preorderTraversal(ptr->right); //ptr�� rigth���� ����Լ��� ����
		return ;
	}

}

void postorderTraversal(Node* ptr)
{	//����, ������, root�� ������ ���� ��µ�
	if (ptr != NULL)
	{
		postorderTraversal(ptr->left); //ptr�� left���� ����Լ��� ������
		postorderTraversal(ptr->right); //ptr�� right���� ����Լ��� ������
		printf("[%d]", ptr->key); // ptr�� key���� �����
		return ;
	}

}


int insert(Node* head, int key)
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->key = key;
	Node* root = head->left;

	if (head->left == NULL) //�������� left�� NULL�̸� (Ʈ���� ��尡 ����, ù��带 ����)
	{
		head->left = n1; //�������� left �� n1�� �ȴ�.
		n1->left = NULL; //n1�� left�� right�� NULL������ ����
		n1->right = NULL;
		return 0;
	}
	while (root != NULL) // root�� ���� NULL�� ������
	{
		if (key < root->key) //root�� key������ key���� �������
		{
			if (root->left == NULL) // root�� left�� NULL�� ���
			{
				root->left = n1; //n1�� root�� left
				n1->left = n1->right = NULL; //n1�� left��right�� NULL�� �ʱ�ȭ
				break; //�ݺ����� ����
			}
			else {
				root = root->left; //root�� left���� NULL�� �ƴ϶�� root�� ���� root�� ���ʳ��� �̵�

			}

		}
		else if (key > root->key) // root�� key������ key���� Ŭ���
		{
			if (root->right == NULL) { // root�� right�� NULL�� ���
				root->right = n1; //root�� right�� n1�� ��
				n1->left = n1->right = NULL; //n1�� left�� right�� NULL�� �ʱ�ȭ
				break;
			}
			else {
				root = root->right; //root�� right���� NULL�� �ƴ϶�� root�� ���� root�� �����ʳ��� �̵�

			}

		}
	}
	return 0;

}

int deleteLeafNode(Node* head, int key)
{
	Node* node = head->left;
	Node* parents = NULL; //������ ���� �θ��带 ����ų �����͸� �����ϰ� �ʱ�ȭ

	if (node == NULL) // ��� ���� root��尡 NULL�̶�� ��尡 �������� �ʴ´�.
	{
		printf("������ ��尡 �������� �ʽ��ϴ�.\n");
		return 0;
	}
	while (node != NULL) // node�� NULL���� �ƴ� ������ �ݺ�
	{
		if (node->key > key) //node�� key���� key������ ū���
		{
			parents = node; // node�� ����Ű�� ��带 �θ��尡 ����Ű�� ��
			node = node->left; //node�� ����Ű�� ��带 ���ʳ��� �̵�
		}
		else if (node->key < key) //node�� key���� key������ �������
		{
			parents = node; //node�� ����Ű�� ��带 �θ��尡 ����Ű����
			node = node->right; //node�� ����Ű�� ��带 �����ʳ��� �̵�
		}
		else //node�� key���� key���� �������(�ϴ� ������ ��带 ã�Ƴ´�)
		{
			if (node->right == NULL && node->left == NULL)//���� node�� right���� NULL �̰� node�� left���� NULL�̸� ���ǹ��� ����(���� ����� ����)
			{
				if (node == head->left) //���� node�� ������� left���? �ش� ���� root����̴�. root����� right=left=NULL�̶�� ���� root����� �������� ����
				{
					free(node); //node�� �ش��ϴ� ��带 ���������ְ� �ݺ����� ������(�����Ϸ�)
					break;
				}
				else if(parents->right == node) //�θ����� �������� node���
				{
					parents->right = NULL; // �θ����� right�� ����Ű�� ���� NULL�� ��ȯ(�����Ϸ��� ���� �̾��� ����Ʈ ������ ����)
					free(node);//node�� ���������ְ� �ݺ����� ������(�����Ϸ�)
					break;
				}
				else if (parents->left == node) //�θ����� left�� ����Ű�� ���� node���
				{
					parents->left = NULL; //�θ����� left�� ����Ű�� ���� NULL�� ��ȯ(�����Ϸ��� ���� �̾��� ������ ������ ����)
					free(node); //node�� ���������ְ� �ݺ����� ������(�����Ϸ�)
					break;
				}

			}
			printf("�ش� ���� ���� ��尡 �ƴմϴ�.\n"); //node�� key���� key���� ������ right�� left�� ���� NULL�� �ƴѰ��(���� ����� ���ǿ� �������� ����) �ȳ������� ����� ���ǹ��� ����
			break;

		}
	}
	if (node == NULL) // node�� NULL�� �Ǿ����� ���ǿ� �����ϴ� ��尡 �������� �ʴ� ���(������ ��尡 �������� �ʴ� ���)
	{
		printf("������ ��尡 �������� �ʽ��ϴ�.\n"); //�ȳ������� ���
		return 0;
	}


	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
	if (ptr == NULL) // ��尡 �������� �ʰų�, ����Լ��� �ݺ��� ��� key���� ��ġ�ϴ� ��尡 �������� ������� ���.
	{
		printf("key���� ��ġ�ϴ� ��尡 �������� �ʽ��ϴ�.\n");
		return 0;
	}
	else if (ptr->key == key) // ����� ��� ptr�� key ���� key���� ���ų�, root����� key���� key���� ��ġ�� ��� ptr�� ��ȯ
	{
		return ptr;
	}
	else if (ptr->key > key) // ptr�� key���� key������ ū���
	{
		searchRecursive(ptr->left, key); //ptr�� ���ʳ��� �Ű��ְ� ����Լ��� ����
	}
	else // ptr�� key���� key������ ū���
	{
		searchRecursive(ptr->right, key); //ptr�� �����ʳ��� �Ű��ְ� ����Լ��� ����
	}

}

Node* searchIterative(Node* head, int key)
{
	Node* root = head->left;
	if (root == NULL) //���� root�� NULL�̶�� (��尡 �������� ����)
	{
		printf("��尡 �������� �ʽ��ϴ�.\n"); //��尡 �������� �ʴٴ� ���� ���
		return 0;
	}
	while (root != NULL) //root�� NULL���� �ɶ����� �ݺ�
	{
		if (root->key == key) //���� root�� key���� key���� ���ٸ�
		{
			return root; //root�� ��ȯ (�˻��� �Ϸ���)
			break;
		}
		else if (root->key > key) // root�� key���� key������ ũ�ٸ�
		{
			root = root->left; // root�� root�� ���ʳ��� �ű�
		}
		else if(root->key < key) //root�� key���� key������ �۴ٸ�
		{
			root = root->right; //root�� root�� �����ʳ��� �ű�
		}

	}
	if (root == NULL) //root�� NULL���� �Ǿ��µ� key���� �������
	{
		printf("key���� �ش��ϴ� ��尡 �������� �ʽ��ϴ�.\n"); //�ȳ������� ���
		return 0;
	}
	return 0;
}



int freeBST(Node* head)
{
	if (head == NULL) // head�� NULL�� ���
	{
		return 0; //����
	}
	else if (head != NULL && head->left != NULL) // head�� NULL�� �ƴϰ� head�� left�� NULL�� �ƴҰ��
	{
		freeBST(head->left); //����Լ��� head�� left���� ��
	}
	else if (head != NULL && head->right != NULL && head->right != head) // head�� NULL�� �ƴϰ� head�� right�� NULL�� �ƴϰ� head�� right���� head�� �ƴҰ�� (����° ������ ������ �����带 �ʱ�ȭ�� �� ������� �ڱ��ڽ��� ����Ű�Ƿ� ����Լ��� �ٽ� ���� ���� �����ϱ� ���� ����)
	{
		freeBST(head->right); //����Լ��� head�� right���� ��
	}
	free(head); // head��带 ������


	return 0;
}
