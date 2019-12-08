#include <iostream>

typedef int T;

struct element
{
	T w;
	element* next = nullptr;
	element* prev = nullptr;
};

void dodajNaPoczatek(element *& pHead, const T& wartosc)
{
	element* nowy = new element;
	nowy->w = wartosc;
	nowy->next = pHead;
	if (pHead != nullptr)
		pHead->prev = pHead;
	pHead = nowy;
}

//void sort(element* head)
//{
//	element* temp1 = nullptr;
//	element* temp2 = nullptr;
//	int temp = 0;
//
//	for (temp1 = head; temp1 != head->prev; temp1 = temp1->next) 
//	{
//		for (temp2 = head; temp2 != head->prev; temp2 = temp2->next) 
//		{
//			if (temp1->w < temp2->w) 
//			{
//				temp = temp1->w;
//				temp1->w = temp2->w;
//				temp2->w = temp;
//			}
//		}
//	}
//}
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

void usunListe(element *& pHead, element *& pTail)
{
	element* temp;
	if (pHead == nullptr)
		return;
	while (pHead != nullptr)
	{
		if (pHead->next != nullptr)
		{
			temp = pHead;
			pHead = pHead->next;
			temp->prev = nullptr;
			delete temp;
		}
	}
	pHead = nullptr;
	pTail = nullptr;
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
	dodajNaPoczatek(head,69);
	dodajNaPoczatek(head, 75);
	dodajNaPoczatek(head, 13);
	dodajNaPoczatek(head, 15);

	element* tail = LastElement(head);

	//showList(head);
	//sort(head);
	showList(head);
	std::cout << "--------------------------------------------------" << std::endl;
	reverse(head, tail);
	std::cout << "--------------------------------------------------" << std::endl;
	//reverse(head, tail);
	std::cout << znajdz(head, 15) << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	usunListe(head, tail);
	showList(head);
	
	//showList(head); 
	return 0;
}