#include <iostream>
using namespace std;

struct Node 
{
	int key;
	Node* next;
};

//добавление узла в начало списка
void Add(Node* &Head, int k) {
	Node* NewNode = new Node; 
	NewNode->next = Head; 
	NewNode->key = k;
	Head = NewNode;
}

//удаление списка
void Del(Node* &Head) {
	while (Head != nullptr) {
		Node* PNode = Head;
		Head = PNode->next;
		delete PNode;
	}
}

//ввод списка
void input(Node* &Head) {
	Node* PNode = new Node;
	int k = 0;
	cin >> k;
	PNode->key = k;
	PNode->next = new Node;
	Head = PNode;
	PNode = PNode->next;
	while (PNode->next != nullptr) {
		cin >> k;
		if (k == 0) {
			PNode->next = nullptr;
			return;
		}
		PNode->key = k;
		PNode->next = new Node;
		PNode = PNode->next;
	}
}

//вывод списка
void output(Node* &Head) {
	Node*PNode = Head;
	while (PNode->next != nullptr) {
		cout << PNode->key << " ";
		PNode = PNode->next;
	}
}

//добавление узла по возрастанию в сортированном по возрастанию списке
void sort(Node*& Head, int x) {
	int i = 0;
	Node* PNode = Head;
	while (PNode->next != nullptr) {
		if (x <= PNode->key) {
			Add(PNode, x);
			return;
		}
		if (x <= PNode->next->key && PNode->key <= x) {
			Node* NewNode = new Node;
			NewNode->key = x;
			NewNode->next = PNode->next;
			PNode->next = NewNode;
			return;
		}
		if (PNode->next->next == nullptr) {
			Node* NewNode = new Node;
			NewNode->key = x;
			NewNode->next = PNode->next;
			PNode->next = NewNode;
			return;
		}
		PNode = PNode->next;
	}

}

//удаление узла по заданному ключу
void del_by_key(Node*& Head, int k) {
	Node* PNode = Head;
	Node* p = nullptr;
	while (PNode->next != nullptr) {
		if (PNode->key == k) {
			if (PNode == Head) {
				p = PNode;
				Head = Head->next;
				PNode = Head;
				delete p;
			}
			else {
				p->next = PNode->next;
				delete PNode;
				PNode = p->next;
			}
		}
		else {
			p = PNode;
			PNode = PNode->next;
		}
	}
}

int main()
{
	Node* Head = nullptr;
	input(Head);
    //sort(Head, 5);
	//del_by_key(Head, 4);
	output(Head);
	return 0;
}