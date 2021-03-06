#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int rountDownDivision(int a, int b) {
	return (a - a % b) / b;
}

int isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int getMonthDays(int year, int month) {
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2) {
		int leapYear;
		leapYear = isLeapYear(year);
		if (leapYear == 1) {
			return 29;
		} else {
			return monthDays[1];
		}
	}
	else {
		return monthDays[month - 1];
	}
}

int getMonthStart(int year, int month) {
	int y, c, m, w;
	y = year % 100;
	c = year / 100;
	m = month;
	if (m == 1 || m == 2) {
		y--;
		m += 12;
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5;
	while (w < 0) {
		w += 7;
	}
	w %= 7;
	return w;
}

int isValidDate(int year, int month, int day) {
	int monthDays;
	if (year < 1582 || year > 9999) {
		return 0;
	} else {
		if (year == 1582) {
			if (month < 10 || month > 12) {
				return 0;
			} else {
				if (day < 15 || day > 31) {
					return 0;
				}
			}
		}
	}
	if (month == 0) {
		return 1;
	}
	if (month < 1 || month > 12) {
		return 0;
	}
	if (day == 0) {
		return 1;
	}
	monthDays = getMonthDays(year, month);
	if (day < 1 || day > monthDays) {
		return 0;
	}
	return 1;
}

void printMonthName(int month) {
	int i, frontSpace = 0;
	char *monthList[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
	frontSpace = rountDownDivision(20 - strlen(monthList[month - 1]), 2);
	for (i = 0; i < frontSpace; i++) {
		printf(" ");
	}
	printf("%s", monthList[month - 1]);
	for (i = 0; i < frontSpace + 1; i++) {
		printf(" ");
	}
}

void printMonthNameWithYear(int year, int month) {
	int i, frontSpace = 0;
	char *monthList[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };
	frontSpace = rountDownDivision(20 - (strlen(monthList[month - 1]) + 5), 2);
	for (i = 0; i < frontSpace; i++) {
		printf(" ");
	}
	printf("%s %d\n", monthList[month - 1], year);
}

void printOneDay(int year, int month, int day) {
	int monthStart = getMonthStart(year, month);
	int weekDay;
	weekDay = ((day % 7) + monthStart - 1) % 7;
	switch (weekDay) {
	case 0:
		printf("dimanche");
		break;
	case 1:
		printf("lundi");
		break;
	case 2:
		printf("mardi");
		break;
	case 3:
		printf("mercredi");
		break;
	case 4:
		printf("jeudi");
		break;
	case 5:
		printf("vendredi");
		break;
	case 6:
		printf("samedi");
		break;
	}
	printf(" %d ", day);
	switch (month) {
	case 1:
		printf("janvier");
		break;
	case 2:
		printf("fevrier");
		break;
	case 3:
		printf("mars");
		break;
	case 4:
		printf("avril");
		break;
	case 5:
		printf("mai");
		break;
	case 6:
		printf("juin");
		break;
	case 7:
		printf("juillet");
		break;
	case 8:
		printf("aout");
		break;
	case 9:
		printf("septembre");
		break;
	case 10:
		printf("octobre");
		break;
	case 11:
		printf("novembre");
		break;
	case 12:
		printf("decembre");
		break;
	}
	printf(" %d.\n", year);

}

void printMonthCalendar(int year, int month) {
	int weekday, days, weeks, i, j, day = 1;
	printMonthNameWithYear(year, month);
	weekday = getMonthStart(year, month);
	days = getMonthDays(year, month);
	weeks = (days + weekday) / 7 + 1; /*计算出该月有几周*/
	printf("di lu ma me je ve sa\n");
	for (i = 0; i < 3 * weekday; i++) {
		printf(" ");
	}
	for (i = 0; i < weeks; ++i) {
		if (i == 0) {
			/*打印第1周*/
			for (j = weekday; j < 7; ++j) {
				printf("%2d ", day);
				day++;
			}
			continue;
		}
		/*打印第2周到倒数第2周*/
		if (i < weeks - 1) {
			printf("\n%2d %2d %2d %2d %2d %2d %2d", day, day + 1, day + 2, day
				+ 3, day + 4, day + 5, day + 6);
			day += 7;
			continue;
		}
		/*打印最后一周*/
		printf("\n");
		for (j = 0; j < 7; ++j) {
			if (day <= days) {
				printf("%2d ", day++);
			}
		}
		printf("\n");
	}
}

void printYearCalendar(int year) {
	int weekday[3], days[3], weeks[3], line, lines, i, j[3], k[3], l[3], formonth1, formonth2, month[3] = { 1, 2, 3 }, day[3], z;
	for (i = 0; i < 30; i++) {
		printf(" ");
	}
	printf("%d\n", year);
	for (formonth1 = 0; formonth1 < 4; formonth1++) {
		day[0] = 1;
		day[1] = 1;
		day[2] = 1;
		for (formonth2 = 0; formonth2 < 3; formonth2++) {
			printMonthName(month[formonth2]);
			printf("  ");
		}
		printf("\n");
		for (formonth2 = 0; formonth2 < 3; formonth2++) {
			weekday[formonth2] = getMonthStart(year, month[formonth2]);
			days[formonth2] = getMonthDays(year, month[formonth2]);
			weeks[formonth2] = (days[formonth2] + weekday[formonth2]) / 7 + 1;
			z = weeks[0];
			if (z < weeks[1]) z = weeks[1];
			if (z < weeks[2]) z = weeks[2];
			lines = z;
			printf("di lu ma me je ve sa");
			printf("  ");
		}
		printf("\n");
		for (line = 0; line < lines; line++) {
			for (formonth2 = 0; formonth2 < 3; formonth2++) {
				if (line == 0) {
					for (j[formonth2] = 0; j[formonth2] < 3 * weekday[formonth2]; j[formonth2]++) {
						printf(" ");
					}
					for (j[formonth2] = weekday[formonth2]; j[formonth2] < 7; ++j[formonth2]) {
						printf("%2d ", day[formonth2]);
						day[formonth2]++;
					}
				} else {
					if (line < (weeks[formonth2] - 1)) {
						printf("%2d %2d %2d %2d %2d %2d %2d ", day[formonth2], day[formonth2] + 1, day[formonth2] + 2, day[formonth2] + 3, day[formonth2] + 4, day[formonth2] + 5, day[formonth2] + 6);
						day[formonth2] += 7;
					}
					if (line == (weeks[formonth2] - 1)) {
						l[formonth2] = 0;
						for (j[formonth2] = 0; j[formonth2] < 7; ++j[formonth2]) {
							if (day[formonth2] <= days[formonth2]) {
								printf("%2d ", day[formonth2]++);
								l[formonth2]++;
							}
						}
						for (k[formonth2] = 0; k[formonth2] < (7 - l[formonth2]); k[formonth2]++) {
							printf("   ");
						}
					}
					if (line > (weeks[formonth2] - 1)) {
						for (i = 0; i < 21; i++) {
							printf(" ");
						}
					}
				}
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
		month[0] = month[0] + 3;
		month[1] = month[1] + 3;
		month[2] = month[2] + 3;
	}
}

int main(void) {
	int day = 0, month = 0, year = 0, first = 0, second = 0, third = 0;
	printf("Veuillez entrer [l'année] ou [le mois,l'année] ou [le jour,le mois,l'année] (Par exemple: 17,8,1926) :");
	scanf("%d,%d,%d", &first, &second, &third);
	printf("\n");
	if (first != 0 && second == 0 && third == 0 && isValidDate(first, 0, 0) == 1) {
		year = first;
		printYearCalendar(year);
		return 0;
	}
	if (first != 0 && second != 0 && third == 0 && isValidDate(second, first, 0) == 1) {
		month = first;
		year = second;
		printMonthCalendar(year, month);
		return 0;
	}
	if (first != 0 && second != 0 && third != 0 && isValidDate(third, second, first) == 1) {
		day = first;
		month = second;
		year = third;
		printOneDay(year, month, day);
		return 0;
	}
	printf("Veuillez entrer la date correcte\n");
	return 0;
}
