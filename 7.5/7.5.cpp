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

element* znajdz(element* pHead, const T& wartosc)
{
	if (pHead != nullptr)
	{
		if (pHead->w == wartosc)
		{
			return *&pHead;
		}
		while (pHead)
		{
			if (pHead->w == wartosc)
			{
				return *&pHead;
			}
			else
				pHead = pHead->next;
		}
		return nullptr;
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
	std::cout << znajdz(head, 15) << std::endl;

	return 0;
}