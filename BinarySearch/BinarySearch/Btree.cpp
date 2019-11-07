#include<stdio.h>
#include<Windows.h>
#include"Btree.h"
#define Tree Btree<int>
void main() {


	Tree tree;
	Tree::Node*root = Tree::CreatNode(123);
	tree.Root(root);

	tree.Insert(&root, Tree::CreatNode(22));
	tree.Insert(&root, Tree::CreatNode(999));
	tree.Insert(&root, Tree::CreatNode(424));
	tree.Insert(&root, Tree::CreatNode(17));
	tree.Insert(&root, Tree::CreatNode(3));
	tree.Insert(&root, Tree::CreatNode(98));
	tree.Insert(&root, Tree::CreatNode(34));
	tree.Insert(&root, Tree::CreatNode(759));
	tree.Insert(&root, Tree::CreatNode(320));
	tree.Insert(&root, Tree::CreatNode(1));

	tree.InOrder(root, 0);

	int depth = 0;
	Tree::Node*node = tree.Search(root,98, depth);
	printf("\n\n찾기%d,%d", node->Data, depth);
	node = tree.Remove(root, NULL, 22);
	printf("삭제할 노드:%d\n", node->Data);
	Tree::DestroyNode(node);

	printf("\n\n");
	tree.InOrder(root, 0);
    

	getchar();

	printf("\n\n");
	tree.Insert(&root, Tree::CreatNode(19));
	printf("\n\n");
	tree.InOrder(root, 0);

	//tree.
	//return 0;

	//system("pause");
}