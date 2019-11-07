#pragma once
template<typename T>

class Btree {
public:
	struct Node;
public:
	Btree() {

	}
	~Btree() {
		Destroy(root);
	}
	void Insert(Node**parent, Node*child) {

		if ((*parent)->Data < child->Data)
		{
			if ((*parent)->Right == NULL)
				(*parent)->Right = child;
			else
				Insert(&(*parent)->Right, child);
		}
		else if ((*parent)->Data > child->Data) {
			if ((*parent)->Left == NULL)
				(*parent)->Left = child;
			else
				Insert(&(*parent)->Left, child);

		}

	}

	Node* Search(Node*node, T data, OUT int& depth) {
      
		if (node == NULL) return NULL;

		depth++;
		if (node->Data == data)
			return node;
		else if (node->Data > data)
			return Search(node->Left, data, depth);
		else if(node->Data<data)
			return Search(node->Right, data, depth);

		return NULL;
	}

	Node* SearchMinValue(Node*node) {
		if (node == NULL) return NULL;

		if (node->Left == NULL)
			return node;
		else
			return SearchMinValue(node->Left);

	}

	Node*Remove(Node*node, Node*parent, T data) {
		Node*remove = NULL;
		
		if (node == NULL) return NULL;

		if (node->Data > data) {
			remove = Remove(node->Left, node, data);
		}
		else if (node->Data<data) {

			remove = Remove(node->Right, node, data);
		}
		else {
			remove = node;
			//자식이 검사
			if (node->Left == NULL && node->Right == NULL) {
				if (parent->Left == node)
					parent->Left = NULL;
				else
					parent->Right = NULL;
			}
			else {
				if (node->Left != NULL && node->Right != NULL) {
					Node*minNode = SearchMinValue(node->Right);
					minNode = Remove(node, NULL, minNode->Data);
					node->Data = minNode->Data;
					return minNode;

				}
				else {
					Node*temp = NULL;
					if (node->Left!= NULL)
						temp = node->Left;
					else
						temp = node->Right;


					if (parent->Left == node)
						parent->Left = temp;
					else
						parent->Right = temp;


				}


			}



		}

		return remove;

	}

	void InOrder(Node*node, int depth) {

		if (node == NULL) return;
		          
		depth++;
		InOrder(node->Left,depth);
		printf("  [%d],%d", depth, node->Data);
		InOrder(node->Right, depth);
	}
	void Root(Node*node) { root = node; }


private:
	void Destroy(Node*node){
		if (node == NULL) return;

		Destroy(node->Left);
		Destroy(node->Right);
		DestroyNode(node);
	}



public:
	static Node*CreatNode(T data) {


		Node*node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;
		return node;

	}
	static void DestroyNode(Node*node) {

		delete node;
		node = NULL;
	}

public:
	struct Node {


		T Data;
		Node*Left;
		Node*Right;


	};

private:
	Node*root;




};