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
	/*����� ��������� ����, ���� � ����� ��� ��������, ������ ���������� �������*/
	void input_receipt();//����� ����
	void enter_receipt(Goods *&);//�������� ������ ���� + ���������� �������
	void enter_element_receipt(Goods  *&);//���������� �������� � ��� ������� ���
	Goods * root;
private:
	bool flag;
	long code;
	Data data;
	
	Goods* last; //������ ���������� �������
public :
	friend Goods;
	friend void delete_fill_catalog(Goods *&Mycatalog_l);
};
void catolog_receipt(Goods *, Receipt &);