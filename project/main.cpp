//
// Created by lerakry on 09.10.2020.
//

#include <gtest/gtest.h>
#include <string>

extern "C" {
    #include "diet.h"
}

TEST(Char_strings, test_additive) {
    char additive1[] = "Без";
    char additive2[] = "Красители";
    EXPECT_EQ(Additives(No_additives), char_additive(additive1));
    EXPECT_EQ(Additives(Colorants), char_additive(additive2));
}

TEST(Char_strings, test_vitamin) {
    char vitamin1[] = "E";
    char vitamin2[] = "K";
    EXPECT_EQ(Vitamins(E), char_vitamin(vitamin1));
    EXPECT_EQ(Vitamins(K), char_vitamin(vitamin2));
}

TEST(Char_strings, test_mineral) {
    char mineral1[] = "Кальций";
    char mineral2[] = "Фосфор";
    EXPECT_EQ(Minerals(Calcium), char_mineral(mineral1));
    EXPECT_EQ(Minerals(Phosphorus), char_mineral(mineral2));
}

TEST(Find_nessesary_param, different_additives) {
    Products* products = initialization();
    char additive1[] = "Антиоксиданты";
    char additive2[] = "Загуститель";
    char additive3[] = "-";
    EXPECT_EQ(true, find_additives(products[8], additive1));
    EXPECT_EQ(false, find_additives(products[6], additive2));
    EXPECT_EQ(true, find_additives(products[5], additive3));
    free(products);
}

TEST(Find_nessesary_param, different_vitamins) {
    Products* products = initialization();
    char vitamin1[] = "B9";
    char vitamin2[] = "B7";
    char vitamin3[] = "-";
    EXPECT_EQ(false, find_vitamin(products[8], vitamin1));
    EXPECT_EQ(true, find_vitamin(products[9], vitamin1));
    EXPECT_EQ(false, find_vitamin(products[4], vitamin2));
    EXPECT_EQ(true, find_vitamin(products[5], vitamin3));
    free(products);
}

TEST(Find_nessesary_param, different_minerals) {
    Products* products = initialization();
    char mineral1[] = "Калий";
    char mineral2[] = "Хром";
    char mineral3[] = "-";
    EXPECT_EQ(false, find_mineral(products[8], mineral1));
    EXPECT_EQ(true, find_mineral(products[1], mineral1));
    EXPECT_EQ(false, find_mineral(products[3], mineral2));
    EXPECT_EQ(true, find_mineral(products[5], mineral3));
    free(products);
}

TEST(Calculations, proteins) {
    Products* products = initialization();
    int proteins1 = 0;
    int proteins2 = 10;
    EXPECT_EQ(true, right_proteins(products[10], proteins1));
    EXPECT_EQ(true, right_proteins(products[0], proteins2));
    EXPECT_EQ(true, right_proteins(products[3], proteins2));
    EXPECT_EQ(false, right_proteins(products[5], proteins2));
    free(products);
}

TEST(Calculations, fats) {
    Products* products = initialization();
    int fats1 = 0;
    int fats2 = 16;
    EXPECT_EQ(true, right_fats(products[11], fats1));
    EXPECT_EQ(true, right_fats(products[0], fats2));
    EXPECT_EQ(true, right_fats(products[2], fats2));
    EXPECT_EQ(false, right_fats(products[5], fats2));
    free(products);
}

TEST(Calculations, carbohydrates) {
    Products* products = initialization();
    int carboh1 = 0;
    int carboh2 = 12;
    EXPECT_EQ(true, right_carbohydrates(products[5], carboh1));
    EXPECT_EQ(false, right_carbohydrates(products[0], carboh2));
    EXPECT_EQ(true, right_carbohydrates(products[2], carboh2));
    EXPECT_EQ(false, right_carbohydrates(products[3], carboh2));
    EXPECT_EQ(true, right_carbohydrates(products[6], carboh2));
    free(products);
}

TEST(Calculations, calories) {
    Products* products = initialization();
    int min_calories1 = 0;
    int min_calories2 = 226;
    int max_calories1 = 0;
    int max_calories2 = 543;
    EXPECT_EQ(true, right_calories(products[10], min_calories1, max_calories1));
    EXPECT_EQ(true, right_calories(products[0], min_calories1, max_calories2));
    EXPECT_EQ(false, right_calories(products[2], min_calories2, max_calories2));
    EXPECT_EQ(true, right_calories(products[5], min_calories2, max_calories2));
    free(products);
}

TEST(Chosen_products, test_half_components) {
    char additive[] = "-";
    char vitamin[] = "-";
    char mineral[] = "-";

    int proteins1 = 13;
    int fats1 = 24;
    int carbohydrates1 = 30;
    int min_calories1 = 200;
    int max_calories1 = 400;

    char* print_product = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Блины с кремом", search_products(proteins1, fats1, carbohydrates1,
                                                                              min_calories1, max_calories1, additive, vitamin, mineral, print_product));
    free(print_product);

    int proteins2 = 15;
    int fats2 = 17;
    int carbohydrates2 = 20;
    int min_calories2 = 0;
    int max_calories2 = 317;

    char* print_product1 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Кофе, Омлет, Овсяная каша", search_products(proteins2, fats2, carbohydrates2,
                                                   min_calories2, max_calories2, additive, vitamin, mineral, print_product1));
    free(print_product1);
}

TEST(Chosen_products, test_secondHalf_comp) {
    int proteins = 0;
    int fats = 0;
    int carbohydrates = 0;
    int min_calories = 80;
    int max_calories = 0;

    char additive1[] = "Без";
    char vitamin1[] = "E";
    char mineral1[] = "Кальций";

    char* print_product = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Банан",search_products(proteins, fats, carbohydrates, min_calories, max_calories, additive1, vitamin1, mineral1, print_product));
    free(print_product);

    char additive2[] = "Стабилизаторы";
    char vitamin2[] = "B9";
    char mineral2[] = "Железо";

    char* print_product1 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("",search_products(proteins, fats, carbohydrates, min_calories,
                                                                                      max_calories, additive2, vitamin2, mineral2, print_product1));
    free(print_product1);
}

TEST(Chosen_products, test_all_components) {
    int proteins1 = 0;
    int fats1 = 20;
    int carbohydrates1 = 35;
    int min_calories1 = 236;
    int max_calories1 = 499;
    char additive1[] = "-";
    char vitamin1[] = "B3";
    char mineral1[] = "-";

    char* print_product1 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Сэндвич с рыбой",search_products(proteins1, fats1, carbohydrates1, min_calories1, max_calories1, additive1, vitamin1, mineral1, print_product1));
    free(print_product1);

    int proteins2 = 20;
    int fats2 = 25;
    int carbohydrates2 = 40;
    int min_calories2 = 200;
    int max_calories2 = 400;
    char additive2[] = "Антиоксиданты";
    char vitamin2[] = "B6";
    char mineral2[] = "Натрий";

    char* print_product2 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Круассан",search_products(proteins2, fats2, carbohydrates2, min_calories2, max_calories2, additive2, vitamin2, mineral2, print_product2));
    free(print_product2);

    int proteins3 = 24;
    int fats3 = 0;
    int carbohydrates3 = 0;
    int min_calories3 = 0;
    int max_calories3 = 400;
    char additive3[] = "Без";
    char vitamin3[] = "B6";
    char mineral3[] = "-";

    char* print_product3 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Кофе",search_products(proteins3, fats3, carbohydrates3, min_calories3, max_calories3, additive3, vitamin3, mineral3, print_product3));
    free(print_product3);

    int proteins4 = 30;
    int fats4 = 30;
    int carbohydrates4 = 50;
    int min_calories4 = 220;
    int max_calories4 = 551;
    char additive4[] = "-";
    char vitamin4[] = "B3";
    char mineral4[] = "Цинк";

    char* print_product4 = (char*)malloc(sizeof(char) * 500);
    EXPECT_STREQ("Сосиски",search_products(proteins4, fats4, carbohydrates4, min_calories4, max_calories4, additive4, vitamin4, mineral4, print_product4));
    free(print_product4);
}

TEST(Correct_input, test_calories) {
    int min_calories1 = 0;
    int min_calories2 = 547;
    int min_calories3 = 80;
    int max_calories1 = 0;
    int max_calories2 = 642;
    int max_calories3 = 100;

    EXPECT_EQ(true, correct_calories(min_calories1, max_calories1));
    EXPECT_EQ(false, correct_calories(min_calories2, max_calories3));
    EXPECT_EQ(true, correct_calories(min_calories3, max_calories2));
    EXPECT_EQ(true, correct_calories(min_calories3, max_calories1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

