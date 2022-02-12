#include"date.h"


/*判断是否是闰年*/
bool is_leap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? true : false;
}

date::date(int Year , int Month , int Day) :day(Day), month(Month), year(Year){
	/*合法性检查*/
	bool legal = true;
	if (Month < 1 || Month >12) legal = false; /*判断月份*/
	else { /*判断日*/
		if (Day <= 0) legal = false;
		else {
			if (Month != 2) legal = (Day <= DAYS[Month - 1] ? true : false);
			else legal = (Day <= (is_leap(Year) ? 29 : 28) ? true : false);
		}
		
	}
	/*提示*/
	if (!legal) {printf("error:illegal date:%04d-%02d-%02d\n",Year,Month,Day);}
}

int date::getYear() {return year;}
int date::getMonth() { return month; }
int date::getDay() { return day;}

bool date::operator<(const date& d) {
	if (year != d.year) return year < d.year;
	if (month != d.month) return month < d.month;
	if (day != d.day) return day < d.day;
	return false;
}
bool date::operator>(const date& d) {
	if (year != d.year) return year > d.year;
	if (month != d.month) return month > d.month;
	if (day != d.day) return day > d.day;
	return false;
}
bool date::operator==(const date& d) {
	if (year == d.year && month == d.month && day == d.day) return true;
	return false;
}
bool date::operator!=(const date& d) {
	if (year == d.year && month == d.month && day == d.day) return false;
	return true;
}
date& date::operator=(const date& d) {
	this->year = d.year;
	this->month = d.month;
	this->day = d.day;
	return *this;
}

date date::operator+(int n) {
	date ret = *this;
	ret.day += n;
	while (true) {
		int D = ret.getDays();
		if (ret.day <= D) break;
		ret.day -= D; ret.month++;
		if (ret.month > 12) { ret.month = 1; ret.year++; }
	}
	return ret;
}

date& date::operator+=(int n) {
	this->day += n;
	while (true) {
		int D = getDays();
		if (day <= D) break;
		day -= D; month++;
		if (month > 12) { month = 1; year++; }
	}
	return *this;
}

date date::operator-(int n) {
	date ret = *this;
	ret.day -= n;
	while (true) {
		if (ret.day > 0) break;
		if (ret.month == 1) { ret.year--; ret.month = 13; }
		if (ret.month == 3) ret.day += is_leap(ret.year) ? 29 : 28;
		else ret.day += DAYS[ret.month - 2];
		ret.month--;
	}
	return ret;
}

date& date::operator-=(int n) {
	this->day -= n;
	while (true) {
		if (day > 0) break;
		if (month == 1) { year--; month = 13; }
		if (month == 3)day += is_leap(year) ? 29 : 28;
		else day += DAYS[month - 2];
		month--;
	}
	return *this;
}


date& date::operator++() {
	if (day < this->getDays()) day++;
	else { day = 1; if (++month > 12) month = 1, year++; }
	return *this;
}

date date::operator++(int) {
	date temp = *this;
	if (day < this->getDays()) day++;
	else { day = 1; if (++month > 12) month = 1, year++; }
	return temp;
}


date& date::operator--(){
	if (this->day != 1) { this->day--; return *this; }
	if (this->month == 1) { this->year--; this->month = 12;}
	this->day = getDay();
	return *this;
}


date date::operator--(int) {
	date ret = *this;
	if (this->day != 1) { this->day--; return ret; }
	if (this->month == 1) { this->year--; this->month = 12; }
	this->day = getDay();
	return ret;
}


void date::swap(date& d) {
	date temp = d;
	d = *this;
	*this = temp;
	return;
}


int date::getDays() {
	if (month < 1 || month>12) return -1;
	else if (month == 2) return is_leap(year) ? 29 : 28;
	else return DAYS[month - 1];
}


int date::getWeek() {
	date base(2000, 1, 2);/*基准(星期日)*/
	int ret = *this - base;
	while (ret < 0) ret += 7;
	ret %= 7;
	return ret;
}

int date::operator-(const date& d) {
	int ret = 0;
	date late, early;
	*this > d ? (late = *this, early = d) : (early = *this, late = d);
	/*跳年*/
	while (late.year - early.year > 1) {
		if (early.month <= 2) {
			if (early.month == 2 && early.day == 29) { ret += 365; early.day = 28; }
			else ret += is_leap(early.year) ? 366 : 365;
		}
		else if (early.month > 2) ret += is_leap(early.year + 1) ? 366 : 365;
		early.year++;
	}
	/*跳到次月一日*/
	if (late.year > early.year || (late.year == early.year && late.month > early.month)) {
		ret += early.getDays() - early.day + 1; early.day = 1;
		if (++early.month > 12) early.month = 1, early.year++;
	}
	/*跳日*/
	while (early < late) { ++early; ++ret; }
	return *this > d ? ret : -ret;
}

