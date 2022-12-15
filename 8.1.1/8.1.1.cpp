#include <iostream>
using namespace std;
int Count(const char* str, const char c)
{
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (c == str[i])
			k++;
	return k;
}
int Count2(const char* str, const char d)
{
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (d == str[i])
			k++;
	return k;
}
int Count3(const char* str, const char f)
{
	int k = 0;
	for (int i = 0; str[i] != '\0'; i++)
		if (f == str[i])
			k++;
	return k;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 2)
		return str;
	size_t maxlen = len;
	char* tmp = new char[maxlen];
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len)
	{
		if ((str[i] == '+' && str[i + 1] == '+') || (str[i] == '='
			&& str[i + 1] == '=') || (str[i] == '-' && str[i + 1] == '-'))
		{
			strcat_s(tmp, maxlen, "***");
			i += 2;
		}
		else
		{
			size_t last = strlen(tmp);
			tmp[last] = str[i++];
			tmp[last + 1] = '\0';
		}
	}
	size_t last = strlen(tmp);
	tmp[last] = str[i++];
	tmp[last + 1] = '\0';
	return tmp;
}
int main()
{
	char str[101];
	char c = '+';
	char d = '-';
	char f = '=';
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contains " << Count(str, c) << " symbols '+'" << endl;
	cout << "String contains " << Count2(str, d) << " symbols '-'" <<
		endl;
	cout << "String contains " << Count3(str, f) << " symbols '='" <<
		endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string: " << dest << endl;
	return 0;
}