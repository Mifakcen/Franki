#include "stdafx.h"

Receipt::Receipt()
{
	cout << "\nЗапущен коструктор\n";
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
	cout << "\nЗапущен деструктор\n";
	delete_fill_catalog(root);
}

void Receipt:: input_receipt()
{
	cout << "Чек номер " << code;
	cout << "Дата :" << data.day << "." << data.month << "." << data.year << endl;
	cout << "Список товаров :";
	input_catalog(root);
} 

void push_rep(Goods* &root,Goods *&Mycatalog,Goods * copi_element) //Mycatalog - последний активный элемент, ГОЛОВА
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
		cout << "Добавление товара в чек : \n";
		*/
		input_catalog(catalog_root);//функции реализованы в другом файле к ним вопросов нет
		cout << "Введите номер добовляемого в список товара\n";
 		int f_l = -1;
		cin >> f_l;
		Goods * flag_1 = chek(catalog_root, f_l);//если мы не найдем товар, то указатель будет нулевым 
		
		if (flag_1)
		{
				push_rep(root,last,flag_1);
		//	flag = question("Ввести еще элемент ?");
			/*if (root == NULL)//если элемент является корнем, не одного элемента пока не вводили 
				root = new Goods(catalog_root, 1);*/
		}
		else
		{
			cout << "Товара с таким номером нет в списке\n";
		}
		/*	else
			{
				root->next = new Goods(catalog_root,root);//////Мы остановились сдесь сюда мы попадаем но дольше не то что хотел
			}
		
		*/
	}
	else
	{
		cout << "Товарный чек не заполнен\n";
	}	
}

void Receipt::enter_receipt(Goods *&catalog_root)
{
	if (catalog_root != NULL) //если список товаров пуст продолжать создавать чек не имеет смысла
	{
		cout << "Введите номер товарного чека\n";
		cin >> code;
		cout << "Введите день\n";
		cin >> data.day;
		cout << "Введите месяц\n";
		cin >> data.month;
		cout << "Введите год\n";
		cin >> data.year;
		flag = true;
		cout << "Заполнить список товаров?(y/n)\n";
		char flag = 'y';
		while (flag == 'Y' || flag == 'y')
		{
			enter_element_receipt(catalog_root);
			flag = question("Продолжить работу со списком товаров? ");
		}
	}
	else
	{
		cout << "Каталог товаров пуст\n Пополните список товаров\n";
	}
}