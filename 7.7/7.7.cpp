#include <iostream>

typedef int T;

struct element
{
	T w;
	element* next = nullptr;
	element* prev = nullptr;
};

void dodajNaPoczatek(element*& pHead, const T& wartosc)
{
	element* nowy = new element;
	nowy->w = wartosc;
	nowy->next = pHead;
	if (pHead != nullptr)
		pHead->prev = pHead;
	pHead = nowy;
}

void showList(element* head)
{
	while (head != nullptr)
	{
		std::cout << head->w << std::endl;
		head = head->next;
	}
}

element* LastElement(element* head) {
	if (head == nullptr)
		return nullptr;
	while (head->next != nullptr) {
		head = head->next;
	}
	return head;
}

void usunListe(element*& pHead, element*& pTail)
{
	if (pHead == nullptr || pTail == nullptr)
		return;
	element* temp = pHead;
	while (pHead != pTail)
	{
		if (pHead->next != nullptr)
		{
			temp = pHead->next;
			//pHead->prev = nullptr;
			delete pHead;
			pHead = temp;
		}
	}
	delete pHead, pTail;
	temp = nullptr;
	pHead = nullptr;
	pTail = nullptr;
}

int main()
{
	element* head = nullptr;
	dodajNaPoczatek(head, 69);
	dodajNaPoczatek(head, 75);
	dodajNaPoczatek(head, 13);
	dodajNaPoczatek(head, 15);

	element* tail = LastElement(head);

	showList(head);
	std::cout << "--------------------------------------------------" << std::endl;
	usunListe(head, tail);
	showList(head);
	return 0;
}