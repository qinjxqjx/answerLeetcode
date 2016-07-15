#include <iostream>  
using namespace std;

struct Node{
	int   m_nData;
	Node *m_pLeft;
	Node *m_pRight;
};

Node* constructCore(int *pStartPreOrder, int *pEndPreOrder, int *pStartInOrder, int *pEndInOrder)
{
	Node *pRoot = new Node;
	pRoot->m_nData = pStartPreOrder[0];//���ڵ�Ϊǰ�������һ���ڵ�ֵ
	pRoot->m_pLeft = NULL;
	pRoot->m_pRight = NULL;

	/*���ǰ����������������ֻ��һ���ڵ㣬��������Ϊ����ڵ�ڵ�*/
	if (pStartPreOrder == pEndPreOrder){
		if (pStartInOrder == pEndInOrder){
			return pRoot;
		}
		else{
			throw std::exception("Invalid input!");
		}
	}

	/*�ڸ��ڵ�֮ǰ�����ݾ�Ϊ�������Ľڵ�*/
	int *pInOrder = pStartInOrder;
	while (pInOrder <= pEndInOrder && *pInOrder != *pStartPreOrder){
		pInOrder++;
	}

	if (pInOrder == pEndInOrder && *pInOrder != *pStartPreOrder){
		throw std::exception("Invalid input!");
	}

	int iSizeLeft = pInOrder - pStartInOrder;//ͳ���������ڵ���
	int *pLeftChildEndPre = pStartPreOrder + iSizeLeft;//�������ڵ����λ��
	/*�ݹ鹹��������*/
	if (iSizeLeft>0){
		pRoot->m_pLeft = constructCore(pStartPreOrder + 1, pLeftChildEndPre, pStartInOrder, pInOrder - 1);
	}
	/*�ݹ鹹��������*/
	if (pInOrder + 1 <= pEndInOrder){
		pRoot->m_pRight = constructCore(pLeftChildEndPre + 1, pEndPreOrder, pInOrder + 1, pEndInOrder);
	}

	return pRoot;
}

Node* constructBinaryTree(int *pPreOrder, int *pInOrder, int iLength)
{
	if (pPreOrder == NULL || pInOrder == NULL || iLength <= 0){
		return NULL;
	}

	return constructCore(pPreOrder, pPreOrder + iLength - 1, pInOrder, pInOrder + iLength - 1);
}

void preOrderWalk(Node *pRoot)
{
	if (pRoot){
		cout << pRoot->m_nData << " ";
		preOrderWalk(pRoot->m_pLeft);
		preOrderWalk(pRoot->m_pRight);
	}
}

void inOrderWalk(Node *pRoot)
{
	if (pRoot){
		inOrderWalk(pRoot->m_pLeft);
		cout << pRoot->m_nData << " ";
		inOrderWalk(pRoot->m_pRight);
	}
}

void postOrderWalk(Node *pRoot)
{
	if (pRoot){
		postOrderWalk(pRoot->m_pLeft);
		postOrderWalk(pRoot->m_pRight);
		cout << pRoot->m_nData << " ";
	}
}

int main()
{
	int preOrder[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inOrder[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Node *root = constructBinaryTree(preOrder, inOrder, 8);

	cout << "\n Pre-Order Walk:" << endl;
	preOrderWalk(root);

	cout << "\n In-Order Walk:" << endl;
	inOrderWalk(root);

	cout << "\n Post-Order Walk:" << endl;
	postOrderWalk(root);
}