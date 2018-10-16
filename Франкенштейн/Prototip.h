#include "stdafx.h"

int menu();
char question(char *);

class Goods
{
public:
	Goods();
	Goods(Goods * &);
	Goods(Goods*&, int);
	Goods::Goods(Goods * &, Goods*&);
	~Goods();
	   
private:
	Goods* next;
	Goods* last;

	long number;
	char name[20];
	double price;
	int quantity;

	void chenge();
	void view();
	double sum_price() { return quantity * price; };
public:
	friend void input_catalog(Goods * Mycatalog);
	friend void delete_fill_catalog(Goods *&Mycatalog_l);
	friend void delete_element_catolog(Goods * &Mycatalog_l, int i, Goods * &Mycatalog_r);
	friend Goods * chek(Goods * Mycatalog, int i);

};

void delete_fill_catalog(Goods *&);
void work_goods(Goods *&, Goods*&);
void push(Goods * &,Goods *&);
void input_catalog(Goods *);
void delete_element_catolog(Goods * &, int i, Goods * &);
Goods * chek(Goods *, int );

