#include<stdio.h>
#include<stdlib.h>
#define issue 5
#define rate 10
void record(int, int);
void highest();
void lowest();
float ave(int);
void display();
int response[issue][rate];
const char *topics[issue] = { "Global Warming","The Economy","War","Health Care","Education" };
main() {
	int res;
	do {
		printf("Please rate the following topics on the scale from 1-10"
			"\n 1 = least important, 10 = important\n");
		for (int i = 0; i < issue; i++) {
			do {
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &res);
			} while (res < 1 || res>10);
			record(i, res);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf_s("%d", &res);
	} while (res != 1);
	display();
	system("pause");
}
void record(int iss, int rating) {
	response[iss][rating - 1]++;
}
void highest(void) {
	int highrating = 0;
	int hightopic = 0;
	for (int i = 0; i < issue; i++) {
		int topicrating = 0;
		for (int j = 0; j < rate; j++) {
			topicrating += response[i][j] * (j + 1);
		}
		if (highrating < topicrating) {
			highrating = topicrating;
			hightopic=i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[hightopic]);
	printf(" with a total rating of %d\n", highrating);
}
void lowest(void) {
	int lowrating;
	int lowtopic = 0;
	for (int i = 0; i < issue; i++) {
		int topicrating = 0;
		for (int j = 0; j < rate; j++) {
			topicrating += response[i][j] * (j + 1);
		}
		if (i == 0) {
			lowrating = topicrating;
		}
		if (lowrating > topicrating) {
			lowrating = topicrating;
			lowtopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowtopic]);
	printf(" with a total rating of %d\n", lowrating);
}
float ave(int iss) {
	float total = 0;
	int counter = 0;
	for (int j = 0; j < rate; j++) {
		if (response[iss][j] != 0) {
			total += response[iss][j] * (j + 1);
			counter += response[iss][j];
		}
	}
	return total / counter;
}
void display() {
	printf("%20s", "Topic");
	for (int i = 1; i <= rate; i++) {
		printf("%4d", i);
	}
	printf("%20s\n", "Average Rating");
	for (int i = 0; i < issue; i++) {
		printf("%20s", topics[i]);
		for (int j = 0; j < rate; j++) {
			printf("%4d", response[i][j]);
		}
		printf("%20.2f", ave(i));
		printf("\n");
	}
	highest();
	lowest();
}