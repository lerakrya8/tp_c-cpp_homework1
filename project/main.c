//
// Created by lerakrya on 09.10.2020.
//
#include "diet.h"
#include <assert.h>

int get_number() {
    int number;
    char str[20];

    scanf("%s", str);
    if ( strcmp(str, "-") == 0 || strcmp(str, "0") == 0 ) {
        number = 0;
    } else {
        if ( atoi(str) == 0 ) {
            printf("%s", "Неверный формат ввода!\n");
            exit(1);
        }
        number = atoi(str);
    }
    return number;
}

int main(void) {
    int proteins;
    int fats;
    int carbohydrates;
    int min_calories, max_calories;
    char vitamin[15];
    char additive[30];
    char mineral[30];

    printf("%s", "Белки: ");
    proteins = get_number();

    printf("%s", "Жиры: ");
    fats = get_number();

    printf("%s", "Углеводы: ");
    carbohydrates = get_number();

    printf("%s", "Минимальная калорийность: ");
    min_calories = get_number();

    printf("%s", "Максимальная калорийность: ");
    max_calories = get_number();
    if ( !correct_calories(min_calories, max_calories) ) {
        printf("%s", "Количество минимальных калорий должно быть больше максимального!");
        return 0;
    }

    printf("%s", "Пищевая добавка: ");
    scanf("%s", additive);

    printf("%s", "Витамин: ");
    scanf("%s", vitamin);

    printf("%s", "Минерал: ");
    scanf("%s", mineral);

    char* print_product = (char*)malloc(sizeof(char) * 500);


    print_product = search_products(proteins, fats, carbohydrates, min_calories,
                  max_calories, additive, vitamin, mineral, print_product);

    printf("%s", "Возможные варианты продуктов: ");
    print(print_product);

    free(print_product);

    return 0;
}
