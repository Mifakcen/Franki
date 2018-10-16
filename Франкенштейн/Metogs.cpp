#include "stdafx.h"

char question(char word[50])
{
	char flag = NULL;
	while (flag != 'Y' && flag != 'N' && flag != 'y' && flag != 'n')
	{
		cout << word << endl;
		cin >> flag;
	}
	return flag;
}

