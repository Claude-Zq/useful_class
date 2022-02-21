#include<iostream>
using namespace std;
#include"AccountFile.h"
#include<fstream>

int main() {


	AccountFile af("test.txt");
	if (af.addAccount(Account("8", "张三", "123"))) std::cout << "成功" << std::endl;
	else std::cout << "失败" << std::endl;


	system("pause");
	return 0;
}