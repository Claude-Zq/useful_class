#pragma once
#include"AccountFile.h"


AccountFile::AccountFile(std::string fileName) {

	this->m_fileName = fileName;
	initMap();
}

AccountFile::~AccountFile() {
	saveMap();/*�������е���Ϣͬ�����ļ���*/
}

void AccountFile::initMap() {

	this->m_allAccount.clear();/*�������*/

	std::ifstream ifs;/*���ļ�*/
	ifs.open(this->m_fileName, std::ios::in);

	if (!ifs.is_open()) {
		std::cout << this->m_fileName << "�ļ�ȱʧ" << std::endl; 
		return;
	}
	Account a;
	while (ifs >> a.m_id >> a.m_name >> a.m_pwd)  this->m_allAccount[a.m_id] = a; 

	ifs.close();
}

void AccountFile::saveMap() {

	std::ofstream ofs;
	ofs.open(this->m_fileName, std::ios::out | std::ios::trunc);/*��ɾ��д*/

	/*������д*/
	for (auto it = this->m_allAccount.begin(); it != this->m_allAccount.end(); it++) {
		ofs << it->second.m_id << " " << it->second.m_name << " " << it->second.m_pwd << std::endl;
	}
	ofs.close();
}

bool AccountFile::findId(std::string id) {
	if (this->m_allAccount.count(id)) return true;
	return false;
}


int AccountFile::verify(const Account& a) {
	std::map<std::string, Account>::iterator it = this->m_allAccount.find(a.m_id);

	if (it == this->m_allAccount.end()) return 0;/*�˺Ŷ�û��*/
	if (it->second.m_pwd != a.m_pwd) return -1;/*�������*/
	if (it->second.m_name != a.m_name) return 2;/*��������*/
	return 1;/*��֤�ɹ�*/
}


bool  AccountFile::addAccount(const Account& a) {
	if (this->m_allAccount.count(a.m_id) == 1) return false;
	/*�������˺�*/
	this->m_allAccount.insert(std::make_pair(a.m_id, a));
	/*saveMap();*/
	return true;
}

bool AccountFile::deleteAccount(std::string id) {
	if (this->m_allAccount.erase(id)) return true;
	return false; /*�ļ��б�����û�и�id��*/
}

bool AccountFile::modifyName(std::string id, std::string name) {
	if (this->m_allAccount.count(id) == 0) return false;
	/*�޸�����*/
	this->m_allAccount[id].m_name = name;
}

bool AccountFile::modifyPwd(std::string id, std::string pwd) {
	if (this->m_allAccount.count(id) == 0) return false;
	/*�޸�����*/
	this->m_allAccount[id].m_pwd = pwd;
}
