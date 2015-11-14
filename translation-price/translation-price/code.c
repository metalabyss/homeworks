#include<stdio.h> 
#include<string.h> 
#include<math.h>
#include<locale.h>

/*�������� ������ �� 5.10.2015*/

void printHelp()
{
	printf_s("��������� ��� ������� ���� ������������� ������.\n");
	printf_s("\n");
	printf_s("Translate <filename> <price> [mode]\n");
	printf_s("filename - ���� � ���������� �����\n");
	printf_s("price - ����� ��� ������� ������������� �����. ��� ������ \" - w\" - ���� �� �����, � ��� \" - s\" - �� ����, \"-p\" - �� ��������\n");
	printf_s("����� ����� ��� �������� \" - w\" - ��� ����. \" - s\" - ��� ������, \"-p\" - �� �.�. �������� (1800 ������) ���� ����� ��������� ���, �� �� ��������� ��������� \" - s\". ��� ��������� �������� ��� ������ - ������������\n");
}

int isCorrectSymbol(char s)
{
	if (s >= 'a' && s <= 'z') return 1;
	if (s >= 'A' && s <= 'Z') return 1;
	if (s >= '�' && s <= '�') return 1;
	if (s >= '�' && s <= '�') return 1;
	return 0;
}

double countPrice(char *filename, double price, int mode)
{
	FILE *file;
	fopen_s(&file, filename, "r");
	double resultPrice = 0;
	int c;
	char tmp[1800];
	int isPreviousSybmolCorrect = 0;

	switch (mode)
	{
	case 1: //���� ������� ���� �� �����
		while ((c = fgetc(file)) != EOF)
		{
			if (!isCorrectSymbol(c) && isPreviousSybmolCorrect) resultPrice += price;

			if (isCorrectSymbol(c)) isPreviousSybmolCorrect = 1;
			else isPreviousSybmolCorrect = 0;
		}
		if (isPreviousSybmolCorrect) resultPrice += price;
		break;
	case 2: //���� ������� ���� �� ������
		while ((c = fgetc(file)) != EOF)
		{
			if (isCorrectSymbol(c)) resultPrice += price;
		}
		break;
	case 3: //���� ������� ���� �� ��������
		while (fread(tmp, 1, 1800, file)) //� ������� fread ��������� � tmp �� 1800 �������� �� �����
		{
			resultPrice += price;
		}
		break;
	}

	fclose(file);
	return resultPrice;
}

int main(int count, char* args[])
{
	setlocale(LC_ALL, "Russian");

	if (count != 3 && count != 4) {
		printf("�������� ���������� ����������.\n");
		printHelp();
		return 1;
	}

	double price = atof(args[2]); //��������� ������ � double

	int mode; // 1 - w, 2 - s, 3 - p 
	if (count == 3) mode = 2;
	else
	{
		if (strcmp(args[3], "-w") == 0) mode = 1;
		else if (strcmp(args[3], "-s") == 0) mode = 2;
		else if (strcmp(args[3], "-p") == 0) mode = 3;
		else
		{
			printf("����������� ������ ��������� ��������� ������.\n");
			printHelp();
			return 2;
		}
	}

	printf("%lf", countPrice(args[1], price, mode));

	return 0;
}