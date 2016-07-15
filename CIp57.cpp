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
	pRoot->m_nData = pStartPreOrder[0];//根节点为前序遍历第一个节点值
	pRoot->m_pLeft = NULL;
	pRoot->m_pRight = NULL;

	/*如果前序遍历和中序遍历都只有一个节点，则后序遍历为其根节点节点*/
	if (pStartPreOrder == pEndPreOrder){
		if (pStartInOrder == pEndInOrder){
			return pRoot;
		}
		else{
			throw std::exception("Invalid input!");
		}
	}

	/*在根节点之前的数据均为左子树的节点*/
	int *pInOrder = pStartInOrder;
	while (pInOrder <= pEndInOrder && *pInOrder != *pStartPreOrder){
		pInOrder++;
	}

	if (pInOrder == pEndInOrder && *pInOrder != *pStartPreOrder){
		throw std::exception("Invalid input!");
	}

	int iSizeLeft = pInOrder - pStartInOrder;//统计左子树节点数
	int *pLeftChildEndPre = pStartPreOrder + iSizeLeft;//左子树节点结束位置
	/*递归构建左子树*/
	if (iSizeLeft>0){
		pRoot->m_pLeft = constructCore(pStartPreOrder + 1, pLeftChildEndPre, pStartInOrder, pInOrder - 1);
	}
	/*递归构建右子树*/
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