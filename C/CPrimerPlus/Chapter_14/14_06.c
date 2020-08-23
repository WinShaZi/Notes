#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 19

struct message
{
	int num;
	char first[LEN];
	char last[LEN];
	int count;
	int beat;
	int home;
	int rbi;
	float rate;
};

int main()
{
	FILE *fp = NULL;
	int number = 0;
	int i = 0, mode = 0;
	int t_count = 0, t_beat = 0, t_home = 0, t_rbi = 0;
	struct message grade[LEN] =
	{
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
		{ 0, "", "", 0, 0, 0, 0 },
	};

	fopen_s(&fp, "Project6", "r");
	if (fp == NULL)
	{
		printf("Can't open \"Project6\"\n");
		exit(EXIT_FAILURE);
	}

	printf("Input number : ");
	scanf("%d", &number);
	while (1)
	{
		fscanf_s(fp, "%d %s %s %d %d %d %d", &grade[i].num, grade[i].first, LEN, grade[i].last, LEN,
			&grade[i].count, &grade[i].beat, &grade[i].home, &grade[i].rbi);
		if (grade[i].first[0] == '\0')
			break;
		if (grade[i].num != number)
		{
			grade[i].first[0] = '\0';
			continue;
		}
		grade[i].rate = (float)grade[i].beat / grade[i].count;
		i++;
	}

	while (getchar() != '\n')
		continue;


	for (int n = 0; n < i; n++)
		if (number == grade[n].num)
		{
			t_count += grade[n].count;
			t_beat += grade[n].beat;
			t_home += grade[n].home;
			t_rbi += grade[n].rbi;
			mode = n;
		}

	if (mode > 0)
	{
		printf("%d %s %s ", number, grade[mode].first, grade[mode].last);
		printf("%d %d %d %d\n", t_count, t_beat, t_home, t_rbi);
		printf("Rate : %.2f\n", (float)t_beat / t_count);
	}
	else
		printf("No number.\n");

	fclose(fp);

	system("pause");
	return 0;
}