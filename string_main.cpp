#include"header.h"
int main(){
int op,num;
char ch;
str a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u;
while(1){
cout<<"******Option Menu******\n";
cout<<"1)Print a string\n2)String length\n3)String reverse\n4)Sub-string\n5)Upper case\n6)Lower case\n7)First occurance of a character in a string\n";
cout<<"8)Last occurance of a character in a string\n9)Concatenate strings\n10)Concatenate strings no.of characters\n11)Strings compare\n";
cout<<"12)Strings compare no.of characters\n13)String copy\n14)String copy no.of characters\n0)exit\n";
cout<<"Enter your option\n";
cin>>op;
switch(op){

case 1:
cout<<"Enter a string to print\n";
cin>>a;
cout<<"String: "<<a;
break;

case 2:
cout<<"Enter a string to find the length\n";
cin>>b;
cout<<"The length of the string is: "<<str_len(b)<<endl;
break;

case 3:
cout<<"Enter the string to reverse \n";
cin>>c;
str_rev(c);
cout<<"Reversed string: "<<c<<endl;
break;

case 4:
cout<<"To find the sub string\n";
cout<<"Enter a string :\n";
cin>>d;
cout<<"Enter a sub string:\n";
cin>>e;
if(str_sub(d,e))
cout<<"Sub string is present\n";
else
cout<<"Sub string is not present\n";
break;

case 5:
cout<<"Enter a string to convert lower case characters to upper case\n";
cout<<"Enter a string:\n";
cin>>f;
str_upper(f);
cout<<"Converted string: "<<f;
break;

case 6:
cout<<"Enter a string to convert upper case characters to lower case\n";
cin>>g;
str_lower(g);
cout<<"Converted string: "<<g;
break;

case 7:
cout<<"To find the character first occurance position in a string\n";
cout<<"Enter a string:\n";\
cin>>h;
cout<<"Enter a character\n";
cin>>ch;
str_char(h,ch);
break;

case 8:
cout<<"To find the character last occurance position in a string\n";
cout<<"Enter  a string:\n";
cin>>i;
cout<<"Enter a character\n";
cin>>ch;
str_rchar(i,ch);
break;
case 9:
cout<<"To concatenate two strings\n";
cout<<"Enter 1st string:\n";
cin>>j;
cout<<"Enter 2nd string:\n";
cin>>k;
j=j+k;
cout<<"After concatenate: "<<j;
break;

case 10:
cout<<"To concatenate two string upto some no.of characters\n";
cout<<"Enter 1st string:\n";
cin>>l;
cout<<"Enter 2nd string:\n";
cin>>m;
cout<<"No.of letters to copy:\n";
cin>>num;
strn_cat(l,m,num);
cout<<"After concatenate: "<<l;
break;

case 11:
cout<<"To compare two strings\n";
cout<<"Enter 1st string:\n";
cin>>n;
cout<<"Enter 2nd string:\n";
cin>>o;
if(str_cmp(n,o))
cout<<"Strings are unequal\n";
else
cout<<"Strings are equal\n";
break;

case 12:
cout<<"To comapre two strings upto certain no.of characters\n";
cout<<"Enter 1st string:\n";
cin>>p;
cout<<"Enter 2nd string:\n";
cin>>q;
cout<<"Enter no.of letters to compare:\n";
cin>>num;
if(strn_cmp(p,q,num))
cout<<"Strings are unequal\n";
else
cout<<"Strings are equal\n";
break;

case 13:
cout<<"To copy a string into another string\n";
cout<<"Enter a string:\n";
cin>>r;
str_cpy(r,s);
cout<<"Copied string: "<<s;
break;

case 14:
cout<<"To copy a string into another string upto no.of characters\n";
cout<<"Enter a string:\n";
cin>>t;
cout<<"Enter no.of letters to copy:\n";
cin>>num;
strn_cpy(t,u,num);
cout<<"Copied string: "<<u;
break;

case 0:exit(0);

default:cout<<"Unknown option\n";
}
}
} 