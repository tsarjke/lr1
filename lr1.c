#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc,char *argv[]) {
	FILE *source; //data.csv
	double t;
	int a = 0, b = 0, c = 0, k = 1, y, x, n;
	char path[50], string[100], temp[10], *check, *istr, sep[2]=",";
	char number[9] = "915642913";
	//Проверка любого номера
	//printf("Введите номер: ");
	//scanf("%s",number);
	printf("Укажите путь до файла CSV: ");
	scanf("%s", path);
	source = fopen(path, "r");
	while(1) {
		check = fgets(string, 255, source); //читаем строку
		if (!check) {
			break;
		}
		istr = strtok(string, sep); //делим строку на части (разделитель - запятая)
		while(istr) {
			a++;
			//printf("|%s|   ",istr); вывод csv
			if (a == 2) { //ищем строку в исходящих вызовах
				for (int i = 0; i < 9; i++) {
					if (istr[i] == number[i]) {
						b++;
					}
					else {
						b = 0;
					}
				}
			}
			if (a == 3) { //ищем строку во входящих вызовах
				for (int i = 0; i < 9; i++) {
					if (istr[i] == number[i]) {
						c++;
					}
					else {
						c = 0;
					}
				}
			}
			if ((b == 9 || c == 9) && a == 4) {//суммируем время входящих и исходящих вызовов
				for (int i = 0; i < strlen(istr); i++) {
					temp[i] = istr[i];
				}
				t += atof(temp);		
			}
			if (b == 9 && a == 5) {//суммируем время входящих и исходящих вызовов
				for (int i = 0; i < strlen(istr); i++) {
					temp[i] = istr[i];
				}
				n += atoi(temp);	
			}
			istr = strtok(NULL, sep);
		}
		a = 0;
	}
	fclose(source);
	t = ceil(t);
	x = t * k;
	for (int i = 0; i < n - 5; i++) {
		if (i < 5) {
			y++;
		}
		else {
			y+=2;
		}
	}
	printf("Сумма за звонки - %d рублей\n",x);
	printf("Сумма за СМС - %d рублей\n",y);
	printf("Итог: %d рублей\n",x+y);
	return 0;
}
