#pragma once
#include"Account.h"
#include<map>
#include<string>
#include<iostream>
#include<fstream>


class AccountFile {

public:

	AccountFile(std::string fileName);

	/*只有对象析构时才保存之前的更改，所以请避免同时使用多个对象*/
	~AccountFile();

	/*初始化m_allAccount*/
	void initMap();

	/*将容器中保存的信息保存到文件中*/
	void saveMap();

	/*查找容器中是否有指定id第账号*/
	bool findId(std::string id);

	/*验证账号:0-没有账号 1-验证成功 -1-密码错误 2-姓名错误*/
	int verify(const Account& a);

	/*添加账号 已有相同id时返回false*/
	bool addAccount(const Account& a);

	/*按id号删除账号 无对应id时返回false*/
	bool deleteAccount(std::string id);

	/*修改账号id对应的姓名无对应id时返回false*/
	bool modifyName(std::string id,std::string name);

	/*修改账号id对应的密码  无对应id时返回false*/
	bool modifyPwd(std::string id, std::string pwd);

private:
	std::string m_fileName;
	std::map<std::string, Account> m_allAccount;
};
