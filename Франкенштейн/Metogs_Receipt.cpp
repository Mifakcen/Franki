#include "stdafx.h"

Receipt::Receipt()
{
	cout << "\n������� ����������\n";
	code = 0;
	flag = false;
	data.day = 0;
	data.month = 0;
	data.year = 0;
	root = NULL;
	last = NULL;
}

Receipt::~Receipt()
{
	cout << "\n������� ����������\n";
	delete_fill_catalog(root);
}

void Receipt:: input_receipt()
{
	cout << "��� ����� " << code;
	cout << "���� :" << data.day << "." << data.month << "." << data.year << endl;
	cout << "������ ������� :";
	input_catalog(root);
} 

void push_rep(Goods* &root,Goods *&Mycatalog,Goods * copi_element) //Mycatalog - ��������� �������� �������, ������
{
	if (root == NULL)
	{
		root = new Goods(copi_element,1);
		Mycatalog = root;
	}
	else
	{
		Goods * next_catalog = new Goods(Mycatalog,copi_element);
	}
}

void Receipt::enter_element_receipt( Goods *&catalog_root)
{
	if (flag == true)
	{
	/*	//system("CLS");
		input_receipt();
		cout << "���������� ������ � ��� : \n";
		*/
		input_catalog(catalog_root);//������� ����������� � ������ ����� � ��� �������� ���
		cout << "������� ����� ������������ � ������ ������\n";
 		int f_l = -1;
		cin >> f_l;
		Goods * flag_1 = chek(catalog_root, f_l);//���� �� �� ������ �����, �� ��������� ����� ������� 
		
		if (flag_1)
		{
				push_rep(root,last,flag_1);
		//	flag = question("������ ��� ������� ?");
			/*if (root == NULL)//���� ������� �������� ������, �� ������ �������� ���� �� ������� 
				root = new Goods(catalog_root, 1);*/
		}
		else
		{
			cout << "������ � ����� ������� ��� � ������\n";
		}
		/*	else
			{
				root->next = new Goods(catalog_root,root);//////�� ������������ ����� ���� �� �������� �� ������ �� �� ��� �����
			}
		
		*/
	}
	else
	{
		cout << "�������� ��� �� ��������\n";
	}	
}

void Receipt::enter_receipt(Goods *&catalog_root)
{
	if (catalog_root != NULL) //���� ������ ������� ���� ���������� ��������� ��� �� ����� ������
	{
		cout << "������� ����� ��������� ����\n";
		cin >> code;
		cout << "������� ����\n";
		cin >> data.day;
		cout << "������� �����\n";
		cin >> data.month;
		cout << "������� ���\n";
		cin >> data.year;
		flag = true;
		cout << "��������� ������ �������?(y/n)\n";
		char flag = 'y';
		while (flag == 'Y' || flag == 'y')
		{
			enter_element_receipt(catalog_root);
			flag = question("���������� ������ �� ������� �������? ");
		}
	}
	else
	{
		cout << "������� ������� ����\n ��������� ������ �������\n";
	}
}