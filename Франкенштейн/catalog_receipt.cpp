#include "stdafx.h"

void catolog_receipt(Goods * googs_root,Receipt &chek)
{
	char flag = 'y';	
	while (flag == 'Y' || flag == 'y')
	{	
		system("CLS");
		cout << "������ � ����� :\n"
			<<"�������� ������ ����(1)\n"
			<< "������� �������� ���(2)\n"
			<< "���������� ������ � ���(3)\n"
			<< "�������� ������ �� ����(4)\n"
			<< "�������� ����(5)\n"
			<<"��������� ���������� � ������(6)\n"
			<< "�����(7)\n";
		int f_l = 0;
		cin >> f_l;
		while (f_l != 1 && f_l != 2 && f_l != 3 && f_l != 4 && f_l != 5 && f_l != 6 && f_l != 7)
		{
			cout << "\n�������� ��������� ������� :\n";
			cin >> f_l;
		}
		switch (f_l)
		{
		case 1: {chek.enter_receipt(googs_root); break; };
		case 2: {chek.input_receipt(); break; };
		case 3: {chek.enter_element_receipt(googs_root); break; };
		case 4: {; break; };
		case 5: {delete_fill_catalog(chek.root); break; };
		case 6: {; break; };
		default:
			break;
		}
		flag = question("���������� ������ � �����? ");
	}	
}