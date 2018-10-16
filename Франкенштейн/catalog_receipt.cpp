#include "stdafx.h"

void catolog_receipt(Goods * googs_root,Receipt &chek)
{
	char flag = 'y';	
	while (flag == 'Y' || flag == 'y')
	{	
		system("CLS");
		cout << "Работа с чеком :\n"
			<<"Создание нового чека(1)\n"
			<< "Вывести товарный чек(2)\n"
			<< "Добавление товара в чек(3)\n"
			<< "Удаление товара из чека(4)\n"
			<< "Удаление чека(5)\n"
			<<"Получение информации о товаре(6)\n"
			<< "Выход(7)\n";
		int f_l = 0;
		cin >> f_l;
		while (f_l != 1 && f_l != 2 && f_l != 3 && f_l != 4 && f_l != 5 && f_l != 6 && f_l != 7)
		{
			cout << "\nВыберите требуемое дейсвие :\n";
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
		flag = question("Продолжить работу с чеком? ");
	}	
}