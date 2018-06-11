#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;
        
}
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i) {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}

class MyString {

friend const MyString 
    operator+(const MyString &lhs, const MyString &rhs);
friend ostream& operator<<(ostream& out, const MyString &ms);
friend bool operator<(const MyString &lhs, const MyString &rhs);
friend bool operator>(const MyString &lhs, const MyString &rhs);
friend bool operator==(const MyString &lhs, const MyString &rhs);

public:
    MyString(const char *str = nullptr) { copyStr(str); }
    MyString(const MyString &ms) { copyStr(ms._str); }
    ~MyString() { if(_str) delete[] _str; }
    MyString& operator=(const char *str) 
    {
        if (_str) delete[] _str;
        copyStr(str);
        return *this;
    }
    MyString& operator=(const MyString &ms)
    {
        if (_str) delete[] _str;
        copyStr(ms._str);
        return *this;
    }
    char& operator[](int r) const { return _str[r]; }
    MyString& operator+=(const MyString &ms)
    {
        return *this = *this + ms;
    }
    const MyString operator()(int pos, int len)
    {
        char str[len+1];
        for (int i = 0; i < len; ++i)
            str[i] = _str[pos+i];
        str[len] = '\0';
        return MyString(str);
    }
    void swap(MyString &ms) {
        char *tmpS = ms._str;
        ms._str = _str;
        _str = tmpS;
    }

private:
    char *_str;
    void copyStr(const char *str) {
        if (!str) { _str = nullptr; return; }
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
    }
};

ostream& operator<<(ostream& out, const MyString &ms)
{
    if (ms._str) out << ms._str;
    return out;
}

const MyString operator+(const MyString &lhs, const MyString &rhs) 
{
    int llen = strlen(lhs._str);
    int rlen = strlen(rhs._str);
    char str[llen+rlen+1];
    strcpy(str, lhs._str);
    strcpy(str+llen, rhs._str);
    return MyString(str);
}

bool operator<(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs._str, rhs._str) == -1;
}
bool operator==(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs._str, rhs._str) == 0;
}
bool operator>(const MyString &lhs, const MyString &rhs)
{
    return strcmp(lhs._str, rhs._str) == 1;
}

void qsort(MyString *start, int len, int sz, 
          bool(*func)(const void*, const void*)) {
    for (int i = 1; i < len; ++i) {
        int t = i;
        while (t > 0 && func(start+sz*(t-1) , start+sz*t) == 1) {
            start[t].swap(start[t-1]);
            t = t-1;
        }
    }
}

int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
        return -1;
    else if( *s1 == *s2)
        return 0;
    else if( *s1 > *s2 )
        return 1;
}

int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
    cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
