#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
//#include<string.h>
char* my_strcat(char* chu, const char* mo)
{
	char* c = chu;
	assert(chu && mo);
	while (*chu != '\0')
	{
		chu++;
	}
	while (*chu++ = *mo++)
	{
		;
	}
	return c;
}
int main()
{
	char name[20] = { "hello " };
	my_strcat(name, "word");
	printf("%s\n", name);
	return 0;
}