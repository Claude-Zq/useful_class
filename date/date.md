# date类

为了保证封装性，date类一经构造后不可以直接修改成员变量，要想直接修改，可以新建一个匿名对象，然后直接赋值

## 接口

### 构造函数

```c++
date(int Year = 0, int Month = 1, int Day = 1);
//调用构造函数时会判断日期是否合法，不合法时会输出提示信息
```



### 访问成员变量

```c++
int getYear();/*读取年*/
int getMonth();/*读取月*/
int getDay();/*读取日*/
```



### 关系运算符

```c++
bool operator<(const date& d);
bool operator>(const date& d);
bool operator==(const date& d);
bool operator!=(const date& d);
```



### 赋值运算符

```c++
date& operator=(const date& d);
date& operator+=(int n);     /*增加n(n>=0)天*/
date& operator-=(int n);     /*减去n(n>=0)天*/  
```



### 算数运算符

```c++
date operator+(int n);/*增加n(n>=0)天*/
date operator-(int n);/*减去n(n>=0)天*/
int operator-(const date& d);/*求两个日期的差,如果两个日期是连续的，规定相差1天*/
```



### 递增/递减运算符

```c++
date& operator++();/*前置递增运算*/
date operator++(int);/*后置递增运算*/
date& operator--();/*前置递减运算符*/
date operator--(int);/*后置递减运算符*/
```



### 交换

```c++
void swap(date& d);/*交换两个date*/
```



### 查星期

```
int getWeek();/*计算该天是星期几(周日：0 周一：1以此类推)*/
```

