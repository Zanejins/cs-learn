#include<iostream>
#include<cstring>
using namespace std;

void test(); //测试函数

class my_string{
    friend std::ostream& operator<<(ostream& os, const my_string& str);
	friend std::istream& operator >>(istream& is, my_string& str);
public:
    my_string(const char * str=NULL); //构造函数
    my_string(const my_string &); //拷贝构造函数
    ~my_string(); //析构函数
    my_string operator=(const my_string &); //重载=运算符
    my_string operator+(const my_string &); //重载+运算符
    my_string operator+=(const my_string &); //重载+=运算符
	bool operator==(const my_string&); //重载==运算符
    bool operator!=(const my_string&); //重载==运算符
    bool operator<(const my_string&); //重载<运算符
    bool operator<=(const my_string&); //重载<=运算符
    bool operator>(const my_string&); //重载>运算符
    bool operator>=(const my_string&); //重载>=运算符
	char& operator[](int); //重载[]运算符
    int length();
    char* c_str();
private:
    char* data; //C-字符串
};

int main() {
    test();
}

my_string::my_string(const char* str)
{
	if (str == NULL)this->data = NULL;
	else
	{
		this->data = new char[strlen(str) + 1];
		strcpy(data,str);
	}
}

my_string::my_string(const my_string& other)
{
	if (other.data == NULL)this->data = NULL;
	else
	{
		this->data = new char[strlen(other.data)+1];
		strcpy(this->data,other.data);
	}
}

my_string::~my_string()
{
	delete[] this->data;
}


my_string my_string::operator=(const my_string& other)
{
	delete[] this->data;
	if (other.data == NULL)this->data = NULL;
	else
	{
		this->data = new char[strlen(other.data)+1];
		strcpy(this->data,other.data);
	}
	return *this;
}

my_string my_string::operator+(const my_string& other)
{
	if (other.data == NULL)return *this;
	else if(this->data == NULL)
	{
		this->data = new char[strlen(other.data) + 1];
		strcpy(this->data, other.data);
		return *this;
	}
	else
	{
		my_string strTmp;
		strTmp.data = new char[strlen(this->data) + strlen(other.data) + 1];
		strcpy(strTmp.data, this->data);
		strcat(strTmp.data, other.data);
		return strTmp;
	}
}

my_string my_string::operator+=(const my_string& other) {
    (*this) = (*this) + other;
    return *this;
}


bool my_string::operator==(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp == 0)return 1;
	else return 0;
}

bool my_string::operator!=(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp != 0)return 1;
	else return 0;
}

bool my_string::operator>(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp > 0)return 1;
	else return 0;
}


bool my_string::operator>=(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp >= 0)return 1;
	else return 0;
}

bool my_string::operator<(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp < 0)return 1;
	else return 0;
}

bool my_string::operator<=(const my_string& other)
{
	int tmp = 0;
	tmp = strcmp(this->data,other.data);
	if (tmp <= 0)return 1;
	else return 0;
}


ostream& operator<<(ostream& os, const my_string& str)
{
	os << str.data;
	return os;
}


istream& operator>>(istream& is, my_string& str)
{
	char buffer[4096];
	is >> buffer;
	str.data = buffer;
	return is;
}


char& my_string::operator[](int index)
{
    if(index<0 || index>=strlen(this->data))  //异常处理
        throw "The index is out of range!";
	return this->data[index];
}

int my_string::length() {
    return strlen(this->data) + 1;
}

char* my_string::c_str() {
    return this->data;
}

//测试函数
void test() {
    //1.测试构造函数
    my_string s1("cpp");
    cout<<"The value of s1 is "<<s1<<endl;
    //2. 测试拷贝构造函数
    my_string s2(s1);
    cout<<"The value of s2 is "<<s2<<endl;
    //3. 测试=运算符
    my_string s3=s1;
    cout<<"The value of s3 is "<<s3<<endl;
    //4. 测试+运算符
    my_string s4="cpp";
    my_string s5="language";
    cout<<"s4 = "<<s4<<" s5 = "<<s5<<" s4 + s5 = "<<s4+s5<<endl;
    //测试+=运算符
    my_string s6="cpp";
    my_string s7="language";
    s6+=s7;
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" after s6+=s7, s6 = "<<s6<<endl;
    //测试>运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 > s7 = "<<(s6>s7)<<endl;
    //测试>=运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 >= s7 = "<<(s6>=s7)<<endl;
    //测试<运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 < s7 = "<<(s6<s7)<<endl;
    //测试<=运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 <= s7 = "<<(s6<=s7)<<endl;
    //测试==运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 == s7 = "<<(s6==s7)<<endl;
    //测试!=运算符
    cout<<"s6 = "<<s4<<" s7 = "<<s5<<" S6 != s7 = "<<(s6!=s7)<<endl;
    //测试[]运算符
    try {
        char c1=s6[0]; //索引合理
        cout<<"s6 = "<<s6<<" s6[0] = "<<c1<<endl;

        char c=s6[-1]; //索引不合理
    }catch(const char *s){
        cout<<s<<endl;
    }
}