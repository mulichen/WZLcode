#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strstr(const char* st1, const char* st2)
{
	assert(st1&&st2);
	char* s1 = st1;
	char* s2 = st2;
	char* p = s1;

	while (*p)
	{
		s1 = p;
		s2 = st2;
		while (*s1 != '\0'&& *s2 != '\0'&&*s1== *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return p;
		}
		p++;
	}
	return NULL;
}
int main()
{
	char s[30] = "abcdddefg";
	char t[] = "ddef";
	char*str=my_strstr(s,t);
	if (*str == NULL)
		printf("ц╩спур╣╫\n");
	else
		printf("%s\n", str);
	return 0;
}