#pragma once
#include "stdafx.h"
struct Data
{
	int day;
	int month;
	int year;
};

class Receipt
{
public:
	Receipt();
	~Receipt();
//	input_receipt();
	/*номер товарного чека, дата и время его создания, список покупаемых товаров*/
	void input_receipt();//вывод чека
	void enter_receipt(Goods *&);//создание нового чека + добавление товаров
	void enter_element_receipt(Goods  *&);//Добавление элемента в уже готовый чек
	Goods * root;
private:
	bool flag;
	long code;
	Data data;
	
	Goods* last; //список покупаемых товаров
public :
	friend Goods;
	friend void delete_fill_catalog(Goods *&Mycatalog_l);
};
void catolog_receipt(Goods *, Receipt &);