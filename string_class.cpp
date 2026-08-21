#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class str
{
char *ptr;
public:
str(){ // def cons
ptr=0;
}
str(const char *s){  /// para cons
ptr=new char(strlen(s)+1);
strcpy(ptr,s);
}
str(const str &obj){ /// copy cons
ptr=new char(strlen(obj.ptr)+1);
strcpy(ptr,obj.ptr);
}
~str(){ // destructor
delete[] ptr;
}
str operator +(str &obj){ // + opr overload
str a;
a.ptr=new char[strlen(ptr)+strlen(obj.ptr)+1];
strcpy(a.ptr,ptr);
strcat(a.ptr,obj.ptr);
return a;
}
str &operator=(const str &s) // = opr overload
{
ptr=new char[strlen(s.ptr)+1];
strcpy(ptr,s.ptr);
return *this;
}
char &operator [](int i){ // [] opr overload
return ptr[i];
}
/******************************************/
bool  operator >(const str &s){
return strcmp(ptr,s.ptr)>0;
}
bool operator <(const str &s){
return strcmp(ptr,s.ptr)<0;
}
bool operator >=(const str &s){
return strcmp(ptr,s.ptr)>=0;
}
bool operator <=(const str &s){
return strcmp(ptr,s.ptr)<=0;
}
bool operator ==(const str &s){
return strcmp(ptr,s.ptr)==0;
}
bool operator !=(const str &s){
return strcmp(ptr,s.ptr)!=0;
}
/*******************************************/
friend istream& operator >>(istream& in,str& ); /// input
friend ostream& operator <<(ostream&  out,str& );  /// output
friend int str_len(str &); /// string length
friend void str_rev(str &); /// string reverse
friend int str_sub(str &,str &); /// sub string
friend void str_upper(str &); /// string upper
friend void str_lower(str &); /// string lower
friend void str_char(str &,char); // char in string first occurance
friend void str_rchar(str &,char); // char in string last occurance
friend void str_cat(str &,str &); // concatenate two strings
friend void strn_cat(str &,str &,int); // concatenate two strings first n characters
friend int str_cmp(str &,str &); /// string compare
friend int strn_cmp(str &,str &,int); /// string compare first n characters
friend void str_cpy(str &,str &);// string copy
friend void strn_cpy(str &,str &,int);// string copy first n characters
};