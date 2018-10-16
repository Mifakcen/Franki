#include "stdafx.h"

Goods::Goods()
{
	next = NULL;
	last = NULL;
	number = 0;
	name[20] = ' ';
	price = 0;
	quantity = 0;

	cout << "������� ����� ������\n";
	cin >> number;
	cout << "������� ���\n";
	cin >> name;
	cout << "������� ����\n";
	cin >> price;
	cout << "������� ����������\n";
	cin >> quantity;
}

Goods::Goods(Goods * &Mycatalog)
{
	cout << "\n������� ����������� 2\n";
	next = NULL;
	last = Mycatalog;
	Mycatalog->next = this;
	Mycatalog = this;
	cout << "������� ����� ������\n";
	cin >> number;
	cout << "������� ���\n";
	cin >> name;
	cout << "������� ����\n";
	cin >> price;
	cout << "������� ����������\n";
	cin >> quantity;
}

Goods::Goods(Goods * &Mycatalog, int i)
{
	number = Mycatalog->number;
	price = Mycatalog->price;
	quantity = Mycatalog->quantity;
	next = NULL;
	last = NULL;
}

Goods::Goods(Goods * &Mycatalog, Goods *&copi)
{
	next = NULL;
	last = Mycatalog;
	Mycatalog->next = this;
	Mycatalog = this;
	number = copi->number;
	price = copi->price;
	quantity = copi->quantity;
}

Goods::~Goods()
{
	cout << "\n������� ����������\n";
}


void push(Goods * &Mycatalog,Goods * &root)
{
	if (root==NULL)
	{
		root = new Goods;
		Mycatalog = root;
	}
	else
	{
		Goods * next_catalog = new Goods(Mycatalog);
	}
	//Mycatalog = next_catalog;
}

void input_catalog(Goods * Mycatalog)
{
	
	while (Mycatalog != NULL)
	{
		cout << endl;
		cout <<"����� ������ :" <<"{" << Mycatalog->number << "}" << endl;
		cout << "���� �� ����� :" << "{" << Mycatalog->price << "}" << endl;
		cout << "����������: " << "{" << Mycatalog->quantity << endl;
		//cout << "{" << Mycatalog->name << "}";
		

		Mycatalog = Mycatalog->next;
	}
}

void delete_fill_catalog(Goods *&Mycatalog_l)
{
	if (Mycatalog_l != NULL)
	{
		while (Mycatalog_l != NULL)
		{
			Goods * copi_cat = Mycatalog_l;
			Mycatalog_l = Mycatalog_l->next;
			delete copi_cat;
		}
	}
	else
	{
		cout << "\n������� ������\n";
	}
}

void delete_element_catolog(Goods * &Mycatalog_l, int i, Goods * &Mycatalog_r)
{
	Goods * root = NULL;
	root = chek(Mycatalog_r, i);
	if (root)
	{
		if ((root->next != NULL) & (root->last != NULL))//���� � ��� �� ������
		{
			cout << "\n�� ������\n";
			root->last->next = root->next;
			root->next->last = root->last;
			delete root;
		}
		else if (root->next == NULL && root->last!=NULL)
		{
			cout << "\n������\n";
			root->last->next = NULL;
			Goods *copi_cat = root;
			root = root->last;
			delete copi_cat;
			Mycatalog_l = root;
		}
		else if (root->last == NULL && root->next!=NULL)
		{
			cout << "\n������\n";
			root->next->last = NULL;
			Goods *copi_cat = root;
			root = root->next;
			delete copi_cat;
			Mycatalog_r = root;
		}
		else if (root->last==NULL && root->next==NULL)
		{
			delete Mycatalog_r;
			Mycatalog_r = NULL;
		}
	}
	else
	{
		cout << "\n�������� �������� ���������� ��� ��� ��� ��� � ������\n";
	}
}

Goods * chek(Goods * Mycatalog, int i)
{
	bool flag = false;
	while (Mycatalog != NULL)
	{
		if (Mycatalog->number == i)
		{
			flag = true;
			break;
		}
		Mycatalog = Mycatalog->next;
	}
	return Mycatalog;
}
