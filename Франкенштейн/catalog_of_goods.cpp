#include "stdafx.h"

void work_goods(Goods *& catalog_root,Goods*& catalog_lien)
{
	system("CLS");
	char flag = 'y';
	
	while (flag == 'Y' || flag == 'y')
	{
		system("CLS");
		cout << "Работа с каталогом товаров : \n"
			<< "Вывести список товаров(1)\n"
			<< "Ввести новый элемент (2) \n"
			<< "Удалить элемент списка (3)\n"
			<< "Получить информацию о товаре(цена, количесво, сумма оплаты)(4)\n"//четвертый пункт пусть сделает Денис 
			<< "Удалить весь список(5)\n";
		int f_l = 0;
		cin >> f_l;
		while (f_l != 1 && f_l != 2 && f_l != 3 && f_l != 4 && f_l != 5)
		{
			cout << "\nВыберите требуемое дейсвие :\n";
			cin >> f_l;
		}
		switch (f_l)
		{
		case 1:{
					   input_catalog(catalog_root);
			    break;
		};
		case 2:
		{char flag = 'y';
		while (flag == 'Y' || flag == 'y')
				  {
					  push(catalog_lien,catalog_root);
					  flag = question("Ввести еще элемент ?");
				  }
						  ;
				   break;
		};
		case 3:{ 
				   input_catalog(catalog_root);
				   cout << endl;
				   cout << "Введите номер удаляемого товара :";
				   int i = 0;
				   cin >> i;
				   delete_element_catolog(catalog_lien, i,catalog_root);
				   break; 
		};
		case 4:{ ; break; };
		case 5:{ delete_fill_catalog(catalog_root); break; };
		default:
			break;
		}
		flag = question("Продолжить работу с каталогом товаров? ");
	}
}