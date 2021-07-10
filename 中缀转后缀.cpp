#include <iostream>
using namespace std;
#include <string>
#include <regex>
#include <typeinfo>
#include <stack>

void change(string str){
	stack<char> s1;//存一开始计算符 
	char e;
	for(int i=0;i<str.size();i++)
	{
        if(str[i]>='0'&&str[i]<='9'){
        	cout<<str[i];
		}
		else if(str[i]=='(')
		{
			s1.push(str[i]);
			
		}
		else if(str[i]==')')
		{
			while(s1.top()!='(')
			{
				e=s1.top();
				s1.pop();
				cout<<e;
			}
			s1.pop();
		}
		else{
			if(str[i]=='+'||str[i]=='-')
			{
				if(s1.empty())
				{
					s1.push(str[i]);
				}
				else if(s1.top()=='(')
				{
					s1.push(str[i]);
				}
				else
				{
				  while(!s1.empty())
			        {
			           if(s1.top()!='(')
			    	   {
					   e=s1.top();
			    	   s1.pop();
			    	   cout<<e;}
				    }
				    s1.push(str[i]);
				}
			}
		else{
			s1.push(str[i]);
		}
		}
	}
    while(!s1.empty())
    {
    	e=s1.top();
    	s1.pop();
    	cout<<e;
	}
	
}
int main()
{
	string b="9+(3-1)*3+4/2";
	change(b);
}
