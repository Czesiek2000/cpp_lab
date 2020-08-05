#include <iostream>

using namespace std;

size_t length(const char* cstr)
{
	int length = 0;
	while(cstr[length] != '\0')
	{
		length++;
	}

	return length;
}

bool isLetter(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return true;
	}
	
	else if (c >= 'a' && c <= 'z')
	{
		return true;
	}

	else
	{
		return false;
	}
}


char* reverse(char* cstr)
{
	for (int i = 0; cstr[i] != '\0'; i++) {
		if (cstr[i + 1] == '\0') {
			char* newText;
			newText = new char[i - 1];
			for (int n = 0, j = i; n <= i, j >= 0, newText[n] != '\0'; n++, j--) {
				newText[n] = cstr[j];
			}
			return newText;
		}
	}
}


size_t words(const char* cstr)
{
	int size = length(cstr);
	int i = 0;
	int przed = 0;
	int po = 0;
	int wyst = 0;
	while (cstr[i] != size) 
	{
		if (cstr[przed] == ' ' && cstr[po] == ' ' || cstr[przed] == '\.' && cstr[po] == '\.')
		{
			wyst += 1;
		}

		i++;
		przed = i - 1;
		po = i + 1;
	}

	
	return wyst;
}


size_t words2(const char* cstr)
{
	int size = length(cstr);
	int i = 0;
	int przed = 0;
	int po = 0;
	int wyst = 0;
	while (i != size)
	{
		
		if (cstr[przed] != ' '  && cstr[po] != ' ' && cstr[przed] >= 'a' && cstr[przed] <= 'z' && cstr[po] >= 'a' && cstr[po] <= 'z')
		{

			if (cstr[i] >= 'A' && cstr[i] <= 'Z' || cstr[i] >= 'a' && cstr[i] <= 'z')
			{
			
				wyst++;
			
			}

		}

		i++;
		po = i + 1;
		przed = i - 1;
		
	}
	
	return wyst;
}


char* concat(char* t, const char* s)
{
	int i, j;
	for (i = 0; t[i] != '\0'; ++i);
	
	j = 0;

	while (s[j] != '\0') {
		t[i] = s[j];
		i++;
		j++;
	}
	
	return t;
}

int main() {
	char s1[] = "Alice in Wonderland";
	cout << "Length "<< length(s1) << endl;
	cout << "isLetter " << isLetter(s1[0]) << endl;
	cout << "Reverse " << reverse(s1) << " " << endl;

	char s2[] = " ... for (int i = 0; i < n; ++i){...} ...";
	cout << "words: " << words(s2) << endl;
	cout << "words2: " << words2(s2) << endl;
	
	char s3[100] = "Hello";
	cout << "concat " << concat(concat(s3, ", world"), "!");
	return 0;
}