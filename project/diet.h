#ifndef  _HOME_LERAKRY_TP_PROGRAM_C___DZ1_PROJECT_DIET_H_
#define  _HOME_LERAKRY_TP_PROGRAM_C___DZ1_PROJECT_DIET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum Vitamins {
    A,
    B1,
    B2,
    B3,
    B5,
    B6,
    B9,
    D,
    E,
    K
};

enum Minerals {
    Magnesium,                              // магний
    Phosphorus,                             // фосфор
    Copper,                                 // медь
    Chlorine,                               // хлор
    Calcium,                                // кальций
    Sodium,                                 // натрий
    Zink,                                   // цинк
    Ferrum,                                 // железо
    Potassium,                              // калий
    Iodine                                  // йод
};

enum Additives {
    No_additives,
    Colorants,                              // красители
    Preservatives,                          // консерванты
    Antioxidants,                           // антиоксиданты
    Stabilizers                             // стабилизаторы
};

typedef struct {                            // банан
    int proteins;                         // белки
    int fats;                             // жиры
    int carbohydrates;                    // углеводы
    int calories;
    enum Additives additive;
    enum Vitamins vitamin1;
    enum Vitamins vitamin2;
    enum Minerals mineral1;
    enum Minerals mineral2;
    char name[35];
} Products;

Products *initialization();
enum Additives char_additive(char* additive);
enum Vitamins char_vitamin(char* vitamin);
enum Minerals char_mineral(char* mineral);
bool correct_calories(int min_calories, int max_calories);
bool find_additives(Products product, char* additive);
bool find_vitamin(Products product, char* vitamin);
bool find_mineral(Products product, char* mineral);
bool right_proteins(Products product, int proteins);
bool right_fats(Products product, int fats);
bool right_carbohydrates(Products product, int carbohydrates);
bool right_calories(Products product, int min_calories, int max_calories);
char* search_products(int proteins, int fats,
                   int carbohydrates, int min_calories, int max_calories,
                   char* additive, char* vitamin, char* mineral, char* result_string);


#endif  //  _HOME_LERAKRY_TP_PROGRAM_C___DZ1_PROJECT_DIET_H_
