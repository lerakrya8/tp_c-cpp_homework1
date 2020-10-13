//
// Created by lerakry on 11.10.2020.
//

#include "diet.h"

const Products banana = {2, 1, 21, 96, No_additives, E, K, Calcium,  Phosphorus, "Банан"};
const Products coffee = {0, 0, 0, 0, No_additives, B3, B6, Potassium, Magnesium, "Кофе"};
const Products omelet = {10, 15, 2, 184, No_additives, B1, D, Ferrum, Iodine, "Омлет"};
const Products pan_cream = {7, 13, 17, 218, Colorants, B6, B9, Calcium, Magnesium, "Блины с кремом"};
const Products oatmeal = {3, 1, 12, 67, No_additives, E, B3, Calcium, Sodium, "Овсяная каша"};
const Products bf_tost = {14, 17, 24, 299, Antioxidants, A, B3, Sodium, Chlorine,
                          "Сэндвич с рыбой"};
const Products ae_tost = {10, 10, 9, 150, Stabilizers, A, B5, Sodium, Phosphorus,
                          "Тост с авокадо"};
const Products pb_tost = {16, 16, 35, 303, Preservatives, B5, E, Ferrum, Copper,
                          "Тост с арах. пастой"};
const Products a_croissant = {9, 23, 38, 380, Antioxidants, A, B6, Sodium, Ferrum,
                              "Круассан"};
const Products nm_muesli = {9, 17, 68, 460, Colorants, E,  B9, Copper, Zink,
                            "Мюсли с молоком"};
const Products bar_corny = {6, 15, 66, 424, Preservatives, A, B9, Copper,
                            Iodine, "Батончик Corny"};
const Products sauseges = {11, 24, 2, 266, Stabilizers, B3, E, Zink, Phosphorus,
                           "Сосиски"};
const Products cheesecakes = {19, 4, 19, 183, No_additives, B2, B3, Phosphorus, Ferrum, "Сырники"};


Products *initialization() {
    Products *types = (Products*)malloc(sizeof(Products) * 13);

    types[0] = banana;
    types[1] = coffee;
    types[2] = omelet;
    types[3] = pan_cream;
    types[4] = oatmeal;
    types[5] = bf_tost;
    types[6] = ae_tost;
    types[7] = pb_tost;
    types[8] = a_croissant;
    types[9] = nm_muesli;
    types[10] = bar_corny;
    types[11] = sauseges;
    types[12] = cheesecakes;

    return types;
}

enum Additives char_additive(char* additive) {
    if ( strcmp(additive, "Без") == 0 ) {
        return No_additives;
    }
    if ( strcmp(additive, "Красители") == 0 ) {
        return Colorants;
    }
    if ( strcmp(additive, "Консерванты") == 0 ) {
        return Preservatives;
    }
    if ( strcmp(additive, "Стабилизаторы") == 0 ) {
        return Stabilizers;
    }
    if ( strcmp(additive, "Антиоксиданты") == 0 ) {
        return Antioxidants;
    }
}

enum Vitamins char_vitamin(char* vitamin) {
    if ( strcmp(vitamin, "A") == 0 ) {
        return A;
    }
    if ( strcmp(vitamin, "B1") == 0 ) {
        return B1;
    }
    if ( strcmp(vitamin, "B2") == 0 ) {
        return B2;
    }
    if ( strcmp(vitamin, "B3") == 0 ) {
        return B3;
    }
    if ( strcmp(vitamin, "B5") == 0 ) {
        return B5;
    }
    if ( strcmp(vitamin, "B6") == 0 ) {
        return B6;
    }
    if ( strcmp(vitamin, "B9") == 0 ) {
        return B9;
    }
    if ( strcmp(vitamin, "D") == 0 ) {
        return D;
    }
    if ( strcmp(vitamin, "E") == 0 ) {
        return E;
    }
    if ( strcmp(vitamin, "K") == 0 ) {
        return K;
    }
}

enum Minerals char_mineral(char* mineral) {
    if ( strcmp(mineral, "Магний") == 0 ) {
        return Magnesium;
    }
    if ( strcmp(mineral, "Фосфор") == 0 ) {
        return Phosphorus;
    }
    if ( strcmp(mineral, "Медь") == 0 ) {
        return Copper;
    }
    if ( strcmp(mineral, "Хлор") == 0 ) {
        return Chlorine;
    }
    if ( strcmp(mineral, "Кальций") == 0 ) {
        return Calcium;
    }
    if ( strcmp(mineral, "Натрий") == 0 ) {
        return Sodium;
    }
    if ( strcmp(mineral, "Цинк") == 0 ) {
        return Zink;
    }
    if ( strcmp(mineral, "Железо") == 0 ) {
        return Ferrum;
    }
    if ( strcmp(mineral, "Калий") == 0 ) {
        return Potassium;
    }
    if ( strcmp(mineral, "Йод") == 0 ) {
        return Iodine;
    }
}

bool correct_calories(int min_calories, int max_calories) {
    if ( min_calories == 0 && max_calories == 0 ) {
        return true;
    }
    if ( min_calories == 0 && max_calories != 0 ) {
        return true;
    }
    if ( min_calories !=0 && max_calories == 0 ) {
        return true;
    }
    if ( min_calories <= max_calories ) {
        return true;
    }
    return false;
}

bool find_additives(Products product, char* additive) {
    if ( product.additive == char_additive(additive) || strcmp(additive, "-") == 0 ) {
        return true;
    }
    return false;
}

bool find_vitamin(Products product, char* vitamin) {
    if ( product.vitamin1 == char_vitamin(vitamin) ||
         product.vitamin2 == char_vitamin(vitamin) ||
         strcmp(vitamin, "-") == 0 ) {
        return true;
    }
    return false;
}

bool find_mineral(Products product, char* mineral) {
    if ( product.mineral1 == char_mineral(mineral) ||
         product.mineral2 == char_mineral(mineral) ||
         strcmp(mineral, "-") == 0 ) {
        return true;
    }
    return false;
}

bool right_proteins(Products product, int proteins) {
    if ( proteins == 0 ) {
        return true;
    }
    if ( product.proteins <= proteins ) {
        return true;
    }
    return false;
}

bool right_fats(Products product, int fats) {
    if ( fats == 0 ) {
        return true;
    }
    if ( product.fats <= fats ) {
        return true;
    }
    return false;
}

bool right_carbohydrates(Products product, int carbohydrates) {
    if ( carbohydrates == 0 ) {
        return true;
    }
    if ( product.carbohydrates <= carbohydrates ) {
        return true;
    }
    return false;
}

bool right_calories(Products product, int min_calories, int max_calories) {
    if ( max_calories == 0 && min_calories == 0 ) {
        return true;
    }

    if ( max_calories ==0 && min_calories != 0 ) {
        return product.calories >= min_calories;
    }
    if ( product.calories >= min_calories && product.calories <= max_calories ) {
        return true;
    }
    return false;
}

char* search_products(int proteins, int fats,
                      int carbohydrates, int min_calories, int max_calories,
                      char* additive, char* vitamin, char* mineral, char* result_string) {
    Products* types = initialization();

    for ( int i = 0; i < 13; ++i ) {
        if ( !find_additives(types[i], additive) ) {
            continue;
        }
        if ( !find_mineral(types[i], mineral) ) {
            continue;
        }
        if ( !find_vitamin(types[i], vitamin) ) {
            continue;
        }
        if ( right_calories(types[i], min_calories, max_calories) &&
              right_carbohydrates(types[i], carbohydrates) &&
              right_fats(types[i], fats) && right_proteins(types[i], proteins)  ) {
            proteins -= types[i].proteins;
            fats -= types[i].fats;
            carbohydrates -= types[i].carbohydrates;
            max_calories -= types[i].calories;
            strcat(result_string, types[i].name);
            strcat(result_string, ", ");
        }
    }

    free(types);

    int len = strlen(result_string);
    result_string[len - 2] = '\0';

    return result_string;
}

