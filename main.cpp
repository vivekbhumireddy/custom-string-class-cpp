#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
class str
{
char *ptr;
public:
str(){ // def cons
    ptr=0;
}
str(const char *s){  /// para cons
ptr=new char[strlen(s)+1];
strcpy(ptr,s);
}
str(const str &obj){ /// copy cons
ptr=new char(strlen(obj.ptr)+1);
strcpy(ptr,obj.ptr);
}
~str(){ // destructor
if(p1!=0)
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
     if(this != &s)
     {
         delete[] ptr;
         ptr=new char[strlen(s.ptr)+1];
         strcpy(ptr,s.ptr);
     }
     return *this;
}
char &operator [](int i)
{
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
///////////////////////////////////////////////////////////////////////////////////////////
int f=0;
istream& operator>>(istream& in,str& s) // input
 {
     int i=0;
     char ch;
if(f)
ch=in.get();
f=1;
     fstream file("string",ios::out);
     while((ch=in.get())!='\n' && in)
         file.put(ch);

     file.close();

     file.open("string",ios::in);
     file.seekg(0,ios::end);
     int c=file.tellg();
     file.seekg(0,ios::beg);

     delete[] s.ptr;
     s.ptr=new char[c+1];

     while(file.get(ch))
         s.ptr[i++]=ch;

     s.ptr[i]='\0';
    file.close();

    return in;
}
ostream& operator <<(ostream&  out,str& s)  // output
{
out<<s.ptr<<endl;
return out;
}
int str_len(str &s) // string length
{
int i;
for(i=0;s.ptr[i];i++);
return i;
}
void str_rev(str &s){ /// string reverse
char t;
int i,j,len=str_len(s);
for(i=0,j=len-1;i<j;i++,j--)
 t=s[i],s[i]=s[j],s[j]=t;
}
int str_sub(str &s, str &sub)// sub string
{
    int i,j;

    for(i=0; s[i]; i++)
    {
        for(j=0; sub[j]; j++)
        {
            if(s[i+j] != sub[j])
                break;
        }

        if(sub[j] == '\0')
            return 1;
    }

    return 0;
}
void str_upper(str &s){ /// stirng upper
int i;
for(i=0;s[i];i++)
if(s[i]>='a'&&s[i]<='z')
s[i]=s[i]-32;
}
void str_lower(str &s){ /// string lower
int i;
for(i=0;s[i];i++)
if(s[i]>='A'&&s[i]<='Z')
s[i]=s[i]+32;
}
void str_char(str &s,char ch){ /// char in string first occurance
int i;
for(i=0;s[i];i++)
if(s[i]==ch){
cout<<"char first occurance in pos: "<<i<<endl;
return;
}
cout<<"char not presrent\n";
}
void str_rchar(str &s,char ch){ /// char in string last occurance
int i,len=str_len(s);
for(i=len-1;i>=0;i--)
if(s[i]==ch){
cout<<"char last occurance in pos: "<<i<<endl;
return;
}
cout<<"char not present\n";
}
int str_cmp(str &a,str &b){ /// string compare
int i,j;
for(i=0,j=0;a[i];i++){
if(a[i]==b[j])
j++;
else if(a[i]!=b[j])
j=0;
}
if(b[j]=='\0')
return 0;
else
return 1;
}
int strn_cmp(str &a,str &b,int n){ /// string compare
    int i;

    for(i=0; i<n; i++)
    {
        if(a[i] != b[i])
            return 1;

    }

    return 0;
}
void str_cpy(str &s,str &d){ /// string copy
int i;
d.ptr=new char[str_len(s)+1];
for(i=0;s[i];i++)
d[i]=s[i];
d[i]='\0';
}
void strn_cpy(str &s,str &d,int n){ /// string copy
int i;
d.ptr=new char[str_len(s)+1];
for(i=0;s[i]&&i<n;i++)
d[i]=s[i];
d[i]='\0';
}
//////////////////////////////////////////////////////////////
int main(){
int op,num;
char ch;
str a,b,c;
cout<<"Enter a string: ";
cin>>a;
while(1){
cout<<"******Option Menu******\n";
cout<<"1)Print a string\n2)String length\n3)String reverse\n4)Sub-string\n5)Upper case\n6)Lower case\n7)First occurance of a character in a string\n";
cout<<"8)Last occurance of a character in a string\n9)Concatenate strings\n10)Concatenate strings no.of characters\n11)Strings compare\n";
cout<<"12)Strings compare no.of characters\n13)String copy\n14)String copy no.of characters\n0)exit\n";
cout<<"Enter your option\n";
cin>>op;
switch(op){

case 1:
cout<<"String: "<<a;
break;

case 2:
cout<<"The length of the string is: "<<str_len(a)<<endl;
break;

case 3:
str_rev(a);
cout<<"Reversed string: "<<a<<endl;
break;

case 4:
cout<<"To find the sub string\n";
cout<<"Enter a sub string:";
cin>>b;
if(str_sub(a,b))
cout<<"Sub string is present\n";
else
cout<<"Sub string is not present\n";
break;

case 5:
str_upper(a);
cout<<"Converted string: "<<a;
break;

case 6:
str_lower(a);
cout<<"Converted string: "<<a;
break;

case 7:
cout<<"Enter a character: ";
cin>>ch;
str_char(a,ch);
break;

case 8:
cout<<"Enter a character ";
cin>>ch;
str_rchar(a,ch);
break;

case 9:
cout<<"To concatenate two strings\n";
cout<<"Enter 2nd string:\n";
cin>>b;
b=a+b;
cout<<"After concatenate: "<<b;
break;

case 10:
cout<<"To concatenate two string upto some no.of characters\n";
cout<<"Enter 2nd string:\n";
cin>>b;
cout<<"No.of letters to copy:\n";
cin>>num;
b[num]='\0';
b=a+b;
cout<<"After concatenate: "<<b;
break;

case 11:
cout<<"To compare two strings\n";
cout<<"Enter 2nd string:\n";
cin>>b;
if(str_cmp(a,b))
cout<<"Strings are unequal\n";
else
cout<<"Strings are equal\n";
break;

case 12:
cout<<"To comapre two strings upto certain no.of characters\n";
cout<<"Enter 2nd string:\n";
cin>>b;
cout<<"Enter no.of letters to compare:\n";
cin>>num;
if(strn_cmp(a,b,num))
cout<<"Strings are unequal\n";
else
cout<<"Strings are equal\n";
break;

case 13:
cout<<"To copy a string into another string\n";
str_cpy(a,b);
cout<<"Copied string: "<<b;
break;

case 14:
cout<<"To copy a string into another string upto no.of characters\n";
cout<<"Enter no.of letters to copy:\n";
cin>>num;
strn_cpy(a,b,num);
cout<<"Copied string: "<<b;
break;

case 0:exit(0);

default:cout<<"Unknown option\n";
}
}
}
