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

void reverse(element*& pHead, element*& pTail)
{
	if (pHead != nullptr)
	{
		reverse(pHead->next, pTail);
		std::cout << pHead->w << std::endl;
	}

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
	reverse(head, tail);

	return 0;
}