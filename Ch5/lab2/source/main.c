#include<stdio.h>
#include<stdlib.h>
#define stu 3
#define exam 4
void mini(int, int, int);
void maxi(int, int, int);
void ave(int, int, int);
void printarr(int, int, int);
void printmenu(void);
main() {
	void(*process[4])(int[][exam], int, int) = { printarr,mini,maxi,ave };
	int choice = 0;
	int stugrade[stu][exam] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	while (choice != 4) {
		do {
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);
		if (choice != 4) {
			(*process[choice])(stugrade, stu, exam);
		}
		else {
			printf("Program Ended.\n");
		}
	}
	system("pause");
}
void mini(int grade[][exam], int pupils, int test) {
	int lowgrade = 100;
	for (int i = 0; i <= pupils - 1; i++) {
		for (int j = 0; j <= test - 1; j++) {
			if (grade[i][j] < lowgrade) {
				lowgrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe lowest garde is %d\n", lowgrade);
}
void maxi(int grade[][exam], int pupils, int test) {
	int highgrade = 0;
	for (int i = 0; i <= pupils - 1; i++) {
		for (int j = 0; j <= test - 1; j++) {
			if (grade[i][j] > highgrade) {
				highgrade = grade[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d\n", highgrade);
}
void ave(int grade[][exam], int pupils, int test) {
	int total;
	printf("\n");
	for (int i = 0; i <= pupils - 1; i++) {
		total = 0;
		for (int j = 0; j <= test - 1; j++) {
			total += grade[i][j];
		}
		printf("\tThe average for student %d is %.1f\n", i + 1, (double)total / test);
	}
}
void printarr(int grade[][exam], int pupils, int test) {
	printf("\n\t               [0]    [1]    [2]    [3]");
	for (int i = 0; i < pupils; i++) {
		printf("\n\tstudentGrades[%d]", i);
		for (int j = 0; j < test; j++) {
			printf("%-7d", grade[i][j]);
		}
	}
	printf("\n");
}
void printmenu(void) {
	printf("\n\tEnter a choice:\n"
		"\t 0 Print the array of grades\n"
		"\t 1 Find the minimum grade\n"
		"\t 2 Find the maximum grade\n"
		"\t 3 Print the average on all tests for each student\n"
		"\t 4 End program\n"
		"\t?");
}