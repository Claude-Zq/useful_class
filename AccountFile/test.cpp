#include<iostream>
using namespace std;
#include"AccountFile.h"
#include<fstream>

int main() {


	AccountFile af("test.txt");
	if (af.addAccount(Account("8", "����", "123"))) std::cout << "�ɹ�" << std::endl;
	else std::cout << "ʧ��" << std::endl;


	system("pause");
	return 0;
}