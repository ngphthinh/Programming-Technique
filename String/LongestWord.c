#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int find_position(char *str, char *word)
{
	int i, j;
	while (str[0] == ' ')
	{
		for (i = 0; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}
	}
	// duyet tung phan tu trong xau
	for (i = 0; i < strlen(str); i++)
	{
		// kiem tra ki tu i trong xau str co phai kt dau tien trong xau word khong
		if (str[i] == word[0])
		{
			// kiem tra cac phan tu tiep theo
			for (j = 1; j < strlen(word); j++)
			{
				if (str[i + j] != word[j])
				{
					break;
				}
			}
			// kiem tra xem co duyet het chuoi word ch
			if (j == strlen(word))
			{
				return i;
			}
		}
	}
	// neu khong co tra ve -1;
	return -1;
}
void LongestWord(char str[])
{
	const char *delim = " \r\n"; // dung ngat chuoi

	int max = 0, start_max = -1;
	int current_max = 0;
	// tao chuoi tam
	char tmp[100];
	strcpy(tmp, str);

	char *token = strtok(str, delim);

	while (token != NULL)
	{
		// max hien hanh bang chieu dai chuoi duoc cat
		current_max = strlen(token);
		if (token[0] != ' ' && max < current_max)
		{
			start_max = find_position(tmp, token);
			max = current_max;
		}
		token = strtok(NULL, delim);
	}

	printf("%d %d\n", start_max, max);
}

int main()
{

	char S[1000];
	gets(S);
	LongestWord(S);
}