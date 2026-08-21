#include<iostream>
#include<cstring>
#include<cstdlib>
#include"string_class.cpp"
using namespace std;

istream& operator >>(istream& in,str& s) /// input
{
char st[1000];
in>>st;
s.ptr=new char[strlen(st)+1];
strcpy(s.ptr,st);
return in;
}
ostream& operator <<(ostream&  out,str& s)  // output
{
cout<<s.ptr<<endl;
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
int str_sub(str &s,str &sub){ // sub string
int i,j;
for(i=0;s[i];i++)
{
for(j=0;sub[j];j++)
{
if(s[i+j]!=sub[j])
break;
}
if(sub[j]=='\0')
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
void str_cat(str &s,str &r){ /// concatenate two strings
int i=str_len(s),j=0;
while(r[j])
s[i++]=r[j++];
s[i]='\0';
}
void strn_cat(str &s,str &r,int n){ /// concatenate two strings
int i=str_len(s),j=0;
while(r[j]&&j<n)
s[i++]=r[j++];
s[i]='\0';
}
int str_cmp(str &a,str &b){ /// string compare
int i,j=0;
for(i=0;a[i];i++)
if(a[i]!=b[i])
break;
if(a[i]=='\0')
return 0;
else {
while(1){
if(a[j]>b[j])
return 1;
else if(a[j]<b[j])
return -1;
j++;
}
}
}
int strn_cmp(str &a,str &b,int n){ /// string compare
int i,j=0;
for(i=0;a[i]&&1<n;i++)
if(a[i]!=b[i])
break;
if(a[i]=='\0')
return 0;
else {
while(1){
if(a[j]>b[j])
return 1;
else if(a[j]<b[j])
return -1;
j++;
}
}
}
void str_cpy(str &s,str &d){ /// string copy
int i;
d.ptr=new char(str_len(s)+1);
for(i=0;s[i];i++)
d[i]=s[i];
d[i]='\0';
}
void strn_cpy(str &s,str &d,int n){ /// string copy
int i;
d.ptr=new char(str_len(s)+1);
for(i=0;s[i]&&i<n;i++)
d[i]=s[i];
d[i]='\0';
}