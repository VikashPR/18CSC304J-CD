#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include <fstream>
#include <string>
using namespace std;

string arr[] = { "void", "using", "namespace", "int", "include", "iostream", "std", "main",
"cin", "cout", "return", "float", "double", "string" };

bool isKeyword (string a)
{
for (int i = 0; i < 14; i++)
{
if (arr[i] == a)

{
return true;
}
}
return false;
}

int main ()
{

std::ifstream file("prog.txt");
std::string x;
string code="";
while (std::getline(file, x)) {
code+=x;
}

string s="";
for (int i = 0; i < code.size (); i++)
{

if (code[i] != ' ')
s += code[i];

else
{
if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "&&" || s == "||" ||
s == "=" || s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s
== "+=" ||
s == "-=" || s == "/=" || s == "*=" || s == "%=")

{
cout << s <<" is an operator"<<endl;
s = "";
}

else if (isKeyword (s))
{
cout << s <<" is a keyword"<<endl;
s = "";
}

else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" ||
s == ">" || s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#")
{
cout << s <<" is a symbol"<<endl;
s = "";
}

else if (s == "\n" || s == "" || s == "")
{
s = "";
}

else if (isdigit (s[0]))
{

int x = 0;
if (!isdigit (s[x++]))
{
continue;
}
else
{
cout << s <<" is a constant"<<endl;
s = "";
}
}

else
{
cout << s <<" is an identifier"<<endl;
s = "";
}

}
}
}
