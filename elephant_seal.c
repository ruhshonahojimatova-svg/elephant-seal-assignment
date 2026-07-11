#include <stdio.h>
#include <stdlib.h>

#define MAX_SEALS 10000 // Максимальный размер массива с запасом для всех данных

/**
 * @file elephant_seal.c
 * @brief Программа для расчета среднего веса популяции морских слонов.
 * * Данная программа открывает файл "elephant_seal_data", считывает
 * содержащиеся в нем значения веса в массив динамического подсчета,
 * после чего вычисляет точное среднее арифметическое значение.
 */
int main() {
    int weights[MAX_SEALS];
    int count = 0;
    long long sum = 0;
    double average = 0.0;

    // Открываем файл "elephant_seal_data" для чтения
    FILE *file = fopen("elephant_seal_data", "r");
    
    // Проверка на корректность открытия файла
    if (file == NULL) {
        printf("Error: Could not open file 'elephant_seal_data'.\n");
        return 1;
    }

    // Пошагово считываем данные из файла и записываем их в массив weights
    while (count < MAX_SEALS && fscanf(file, "%d", &weights[count]) == 1) {
        sum += weights[count]; // Аккумулируем сумму для последующего расчета
        count++;
    }

    // Обязательно закрываем файл после завершения работы с ним
    fclose(file);

    // Защита от деления на ноль: проверяем, что массив не пустой
    if (count > 0) {
        // Приведение типов к double для сохранения точности при делении
        average = (double)sum / count;

        // Красивый и структурированный вывод результатов работы программы
        printf("=========================================\n");
        printf("  Elephant Seal Population Weight Report \n");
        printf("=========================================\n");
        printf(" Total number of seals read: %d\n", count);
        printf(" Total combined weight:      %lld\n", sum);
        printf(" Average weight:             %.2f\n", average);
        printf("=========================================\n");
    } else {
        printf("Warning: No valid data found in the file.\n");
    }

    return 0;
}
