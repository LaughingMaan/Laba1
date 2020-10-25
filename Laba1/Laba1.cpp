// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Laba1.h"
//#include <vld.h> профайлер Visual Leak Detector

	// Точка входа в программу
	int main(void) {
		setlocale(LC_ALL, "Russian");
		short counter = 0;
		company temp_comp;
		printf_s("%s", "Введите количество записей > ");
		scanf_s("%hd", &counter);
		printf_s("%c", '\n');
		company *company_array;
		company_array = new company[counter];

		for (short i = 0; i < counter; i++) {
			printf_s("%d %s", i + 1, "Введите имя компании, количество продуктов, годовой объем продажи\n и долю рынка\n>");
			scanf_s("%s", company_array[i].name, (unsigned)_countof(company_array[i].name));
			scanf_s("%d%lu%f", &company_array[i].products, &company_array[i].year_money, &company_array[i].market_part);

		}

		outstring(company_array, counter);
			for (int i = counter - 1; i >= 0; i--) {
				for (int j = 0; j < i; j++) {
					if (strcmp(company_array[j].name, company_array[j + 1].name) > 0) {
						temp_comp = company_array[j];
						company_array[j] = company_array[j + 1];
						company_array[j + 1] = temp_comp;
					}
				}
			}
		
		outstring(company_array, counter);
		delete[] company_array;
		system("pause");
		return EXIT_SUCCESS;
	}
	// Метод описывающий вывод результата на экран
	void outstring(company * my_company, int count) {
		int max_size = 82;
		int current_size = 0;
		char buffer[17];
		printf_s("%s", "\n\n");
		printf_s("%s", "--------------------------------------------------------------------------------\n");
		printf_s("%s", "|Фирмы-производители СКБД                                                      |\n");
		printf_s("%s", "--------------------------------------------------------------------------------\n");
		printf_s("%s", "|Компания | Количество продуктов | Годовой объем продажи ($) | Часть рынка (%) |\n"); //9 23(22) 27 17(18)
		printf_s("%s", "--------------------------------------------------------------------------------\n");
		for (int i = 0; i < count; i++) {

			printf_s("%s", "|");
			current_size = (int)strlen(my_company[i].name);
			printf_s("%s", my_company[i].name);
			while (current_size < 9) {
				printf_s("%s", " ");
				current_size++;
			}
			printf_s("%s", "|");
			_itoa_s(my_company[i].products, buffer, 10);
			current_size = (int)strlen(buffer);
			printf_s("%d", my_company[i].products);
			while (current_size < 22) {
				printf_s("%s", " ");
				current_size++;
			}
			printf_s("%s", "|");
			_ultoa_s(my_company[i].year_money, buffer, 10);
			current_size = (int)strlen(buffer);
			printf_s("%lu", my_company[i].year_money);
			while (current_size < 27) {
				printf_s("%s", " ");
				current_size++;
			}
			printf_s("%s", "|");
			_gcvt_s(buffer, my_company[i].market_part, 10);
			//_gcvt(my_company[i].market_part, 10, buffer); deprecated
			current_size = (int)strlen(buffer);
			printf_s("%5.1f%%", my_company[i].market_part);
			while (current_size < 22) {
				printf_s("%s", " ");
				current_size++;
			}
			printf_s("%s", "|\n");
		}
		printf_s("%s", "--------------------------------------------------------------------------------\n");
	}
