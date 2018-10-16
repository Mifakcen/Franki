#include "stdafx.h"

int menu()
{
	setlocale(0, "RUS");
	system("CLS");
	cout << "\nПрограмма реализации товарного чека.\n";
	char flag = question("Продолжить ? " );
	Goods * catalog_root = NULL;
	Goods * catalog_lien = NULL;
	Receipt * rep_root = NULL;
	Receipt * rep_lean = NULL;
	Receipt chek;
	while (flag == 'Y' || flag == 'y')
	{
		system("CLS");
		cout << "\nПрограмма реализации товарного чека.\n";
		//catalog = new Goods;
		cout << "\nВыберите требуемое дейсвие :\n"
			<< "Работа с каталогом товаров. (1)\n"
			<< "Работа с товарным чеком(2)\n"
			<< "Выход(3)\n";
		int f_l = 0;
		cin >> f_l;
		while (f_l != 1 && f_l != 2 && f_l != 3 )
		{
			cout << "\nВыберите требуемое дейсвие :\n";
				cin >> f_l;
		}

		switch (f_l)
		{
		case 1:
		{
			work_goods(catalog_root, catalog_lien);
			break;
		}
		case 2:
		{
			catolog_receipt(catalog_root, chek);
			break;
		}
		case 3: {flag = question("Продолжить работу в программе?");; break; };
		default:
			break;
		}		
		
		
	}
	delete_fill_catalog(catalog_root);
	//delete_fill_catalog(catalog);
	return 0;
}