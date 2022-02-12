#pragma once
#include<cstdio>


/*判断是否是闰年*/
bool is_leap(int year);

class date {


public:
	/*读取年*/
	int getYear();
	/*读取月*/
	int getMonth();
	/*读取日*/
	int getDay();

	date(int Year = 0, int Month = 1, int Day = 1);
	bool operator<(const date& d);
	bool operator>(const date& d);
	bool operator==(const date& d);
	bool operator!=(const date& d);
	date& operator=(const date& d);

	/*计算一个日期加上n(n>=0)天后是什么日期*/
	date operator+(int n);
	/*增加n(n>=0)天*/
	date& operator+=(int n);

	/*计算一个日期减去n(n>=0)天后是什么日期*/
	date operator-(int n);
	/*倒退n(n>=0)天*/
	date& operator-=(int n);

	/*前置递增运算*/
	date& operator++();
	/*后置递增运算*/
	date operator++(int);

	/*前置递减运算符*/
	date& operator--();

	/*后置递减运算符*/
	date operator--(int);

	/*交换两个date*/
	void swap(date& d);

	/*返回所处月份的总天数*/
	int getDays();
	/*返回该是周几(周日:0 周一:1....)*/
	int getWeek();
	/*求两个日期的差,如果两个日期是连续的，规定相差1天*/
	int operator-(const date& d);

private:
	int year, month, day;
	/*二月单独讨论*/
	const int DAYS[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
};
