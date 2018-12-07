#include<string>
#include<stdio.h>

int main()
{
	char str[20]="char to string.";
	printf("%s\n%s\n",str,std::string(str).substr(0,4).c_str());

	return 0;
}
