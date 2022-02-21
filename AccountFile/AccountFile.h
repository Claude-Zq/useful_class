#pragma once
#include"Account.h"
#include<map>
#include<string>
#include<iostream>
#include<fstream>


class AccountFile {

public:

	AccountFile(std::string fileName);

	/*ֻ�ж�������ʱ�ű���֮ǰ�ĸ��ģ����������ͬʱʹ�ö������*/
	~AccountFile();

	/*��ʼ��m_allAccount*/
	void initMap();

	/*�������б������Ϣ���浽�ļ���*/
	void saveMap();

	/*�����������Ƿ���ָ��id���˺�*/
	bool findId(std::string id);

	/*��֤�˺�:0-û���˺� 1-��֤�ɹ� -1-������� 2-��������*/
	int verify(const Account& a);

	/*����˺� ������ͬidʱ����false*/
	bool addAccount(const Account& a);

	/*��id��ɾ���˺� �޶�Ӧidʱ����false*/
	bool deleteAccount(std::string id);

	/*�޸��˺�id��Ӧ�������޶�Ӧidʱ����false*/
	bool modifyName(std::string id,std::string name);

	/*�޸��˺�id��Ӧ������  �޶�Ӧidʱ����false*/
	bool modifyPwd(std::string id, std::string pwd);

private:
	std::string m_fileName;
	std::map<std::string, Account> m_allAccount;
};
