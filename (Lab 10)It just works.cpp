#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <conio.h>

#include <errno.h>

struct contact
{
	char name[100];
	char surename[100];
	char tel[10];
};

struct contact person[100];
FILE* DB;

int Create() {
	system("cls");
	DB = fopen("DataBase.txt", "a");
	while (true) {
		int bla;
		printf("Add User '1' || End task '0' || -> ");
		scanf("%d", &bla);
		if (bla != 1) {
			break;
		}
		struct contact user;

		printf("Name: ");
		scanf("%s", &user.name);
		fprintf(DB, "%s ", user.name);
		printf("Surename: ");
		scanf("%s", &user.surename);
		fprintf(DB, "%s ", user.surename);
		printf("Phone number: ");
		scanf("%s", &user.tel);
		fprintf(DB, "%s\n", user.tel);
	}
	fclose(DB);
	return 0;
}
void Update() {
	system("cls");
	char counter[20];
	int i = 0;
	int position = 0;
	char Name[20];
	char Surename[20];
	char tel[10];
	DB = fopen("DataBase.txt", "r");

	while (fscanf(DB, "%s", &counter) != EOF) {
		fscanf(DB, "%s", &counter);
		fscanf(DB, "%s", &counter);
		i++;
	}
	if (i == 0)
	{
		printf("No users in database\n");
	}
	else {
		printf("Choose postion to edit from 0 to %d: ", i - 1);
		scanf("%d", &position);
		if (0 <= position && position < i)
		{
			printf("%s %s tel. %s\n", person[position].name, person[position].surename, person[position].tel);
			printf("Change Name to: ");
			scanf("%s", &Name);

			printf("Change Surename to: ");
			scanf("%s", &Surename);

			printf("Change phone number to: ");
			scanf("%s", &tel);

			strcpy(person[position].name, Name);
			strcpy(person[position].surename, Surename);
			strcpy(person[position].tel, tel);

			fclose(DB);

			int j = 0;
			DB = fopen("DataBase.txt", "w");
			for (; j < i; j++) {
				fprintf(DB, "%s ", &person[j].name);
				fprintf(DB, "%s ", &person[j].surename);
				fprintf(DB, "%s\n", &person[j].tel);
			}
			system("cls");
			fclose(DB);
		}
		else {
			system("cls");
			printf("Position out of avilable range, try again\n");
			return;
		}
	}
}
void Read() {
	int i = 0;
	system("cls");
	DB = fopen("DataBase.txt", "r");
	while (fscanf(DB, "%s", &person[i].name) != EOF)
	{
		fscanf(DB, "%s", &person[i].surename);
		fscanf(DB, "%s", &person[i].tel);
		i++;
	}
	if (i == 0)
	{
		printf("No users in database\n");
	}
	else {
		for (int j = 0; j < i; j++) {
			printf("%s %s tel. %s\n", person[j].name, person[j].surename, person[j].tel);

			printf("\n");
		}
		fclose(DB);
	}
}
void Delete() {
	char counter[20];
	int position;
	int i = 0;
	int Confirmation;
	DB = fopen("DataBase.txt", "r");
	system("cls");
	
	while (fscanf(DB, "%s", &counter) != EOF) {
		fscanf(DB, "%s", &counter);
		fscanf(DB, "%s", &counter);
		i++;
	}
	if (i == 0)
	{
		printf("No users in database\n");
	}
	else {
		if (i < 15) {
			Read();
		}
		printf("Choose position to delte from 0 to %d: ", i - 1);
		scanf("%d", &position);
		if (0 <= position && position < i)
		{
			printf("%s %s tel. %s\n", person[position].name, person[position].surename, person[position].tel);
			printf("Are you sure?  1-Yes || 0-No: ");
			scanf("%d", &Confirmation);
			if (Confirmation != 1) {
				return;
			}
			fclose(DB);
			int a = 0;

			DB = fopen("DataBase.txt", "w");
			for (; a < i; a++) {
				if (position != a) {
					fprintf(DB, "%s ", &person[a].name);
					fprintf(DB, "%s ", &person[a].surename);
					fprintf(DB, "%s\n", &person[a].tel);
				}
			}
			fclose(DB);
		}
		else {
			printf("Position out of avilable range, try again\n");
			return;
		}
	}
}

void startup()
{
	char n;
	for (;;)
	{
		printf("(Chose mode):\n\n[Create 'C' || Read 'R' || Update 'U' || Delete 'D' || Wipe screen 'c' || End program '#']\n");
		printf("\n");
		n = _getch();
		fflush(stdin);
		switch (n)
		{
		case 'C':Create();
			break;
		case 'R':Read();
			break;
		case 'U':Update();
			break;
		case 'D':Delete();
			break;
		case 'c':system("cls");
			break;

		case '#' :exit(0);
		default:
			system("cls");
			printf("Wrong Command!! Try Again\n\n");
			continue;
		}
	}
}
void filecheck()
{
	if ((DB = fopen("DataBase.txt", "r")) != NULL)
	{
		fclose(DB);
	}
	else
	{
		char fileName[100];
		sprintf_s(fileName, "DataBase.txt");
		FILE* outputFile;
		fopen_s(&outputFile, fileName, "w");
		fclose(outputFile);
	}
	return;
}
int main(void)
{
	filecheck();
	startup();
}
