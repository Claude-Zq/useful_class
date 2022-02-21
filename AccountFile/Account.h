#pragma once
#include<string>

class Account {
public:
	Account(std::string id = "", std::string name = "", std::string pwd = "") :m_id(id), m_name(name), m_pwd(pwd) {}
	std::string m_id, m_name, m_pwd;
};