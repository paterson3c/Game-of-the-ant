#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enemy.h"
#include "test.h"
#include "enemy_test.h"

#define MAX_TESTS 20

int main (int argc, char *argv[])
{
    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Enemy:\n");
    } 
    else 
    {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) 
        {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }

    if (all || test == 1) test1_enemy_create();
    if (all || test == 2) test1_enemy_destroy();
    if (all || test == 3) test2_enemy_destroy();
    if (all || test == 4) test1_enemy_getName();
    if (all || test == 5) test2_enemy_getName();
    if (all || test == 6) test1_enemy_setHealth();
    if (all || test == 7) test2_enemy_setHealth();
    if (all || test == 8) test1_enemy_getId();
    if (all || test == 9) test2_enemy_getId();
    if (all || test == 10) test1_enemy_getName();
    if (all || test == 11) test2_enemy_getName();
    if (all || test == 12) test1_enemy_getHealth();
    if (all || test == 13) test2_enemy_getHealth();
    if (all || test == 14) test1_enemy_setId();
    if (all || test == 15) test2_enemy_setId();
    if (all || test == 16) test1_enemy_setLocation();
    if (all || test == 17) test2_enemy_setLocation();
    if (all || test == 18) test1_enemy_getLocation();
    if (all || test == 19) test2_enemy_getLocation();

    
    PRINT_PASSED_PERCENTAGE; 

    return 1; 
}

void test1_enemy_create() {
    Enemy *enemy; 
    enemy = enemy_create(); 
    PRINT_TEST_RESULT (enemy != NULL); 
    enemy_destroy(enemy);
}

void test1_enemy_destroy(){
    Enemy *enemy;
    enemy = enemy_create();
    PRINT_TEST_RESULT (enemy_destroy(enemy) == OK);
}

void test2_enemy_destroy(){
    Enemy *enemy = NULL;
    PRINT_TEST_RESULT (enemy_destroy(enemy) == ERROR);
}

void test1_enemy_getName() {
    Enemy *enemy; 
    enemy = enemy_create();
    enemy_setName(enemy, "UAM");
    PRINT_TEST_RESULT (strcmp(enemy_getName(enemy), "UAM") == 0); 
    enemy_destroy(enemy);  
}

void test2_enemy_getName() {
    Enemy *enemy=NULL; 
    PRINT_TEST_RESULT (enemy_getName (enemy) == ERROR); 
}

void test1_enemy_setHealth () {
    Enemy *enemy=NULL; 
    PRINT_TEST_RESULT (enemy_setHealth (enemy, -1) == ERROR); 
}

void test2_enemy_setHealth () {
    Enemy *enemy; 
    enemy = enemy_create(); 
    PRINT_TEST_RESULT (enemy_setHealth (enemy, 5) == OK);
    enemy_destroy(enemy);
}

void test1_enemy_getId () {
    Enemy *enemy; 
    enemy = enemy_create(); 
    enemy_setId(enemy, 5);
    PRINT_TEST_RESULT (enemy_getId (enemy) == 5); 
    enemy_destroy (enemy); 
}

void test2_enemy_getId () {
    Enemy *enemy=NULL; 
    PRINT_TEST_RESULT (enemy_getId (enemy) == NO_ID); 
}

void test1_enemy_setName () {
    Enemy *enemy; 
    enemy = enemy_create(); 
    PRINT_TEST_RESULT (enemy_setName(enemy, "Paco") == OK); 
    enemy_destroy (enemy); 
}

void test2_enemy_setName () {
    Enemy *enemy=NULL; 
    PRINT_TEST_RESULT (enemy_setName (enemy, NULL) == ERROR); 
}

void test1_enemy_getHealth () {
    Enemy *enemy; 
    enemy = enemy_create(); 
    enemy_setHealth (enemy, 7); 
    PRINT_TEST_RESULT (enemy_getHealth (enemy) == 7);
    enemy_destroy(enemy);
}

void test2_enemy_getHealth () {
    Enemy *enemy = NULL; 
    PRINT_TEST_RESULT (enemy_getHealth (enemy) == -1); 
}

void test1_enemy_setId (){
    Enemy *enemy; 
    enemy = enemy_create();
    enemy_setId(enemy, 5);
    PRINT_TEST_RESULT (enemy_setId(enemy, 5) == OK); 
    enemy_destroy(enemy);
}

void test2_enemy_setId (){
    Enemy *enemy; 
    enemy = enemy_create();
    PRINT_TEST_RESULT (enemy_setId(enemy, NO_ID) == ERROR);
    enemy_destroy(enemy);
}

void test1_enemy_setLocation() {
    Enemy *enemy;
    enemy = enemy_create();
    PRINT_TEST_RESULT (enemy_setLocation(enemy, 11) == OK);
    enemy_destroy(enemy);
}

void test2_enemy_setLocation() {
    Enemy *enemy;
    enemy = NULL;
    PRINT_TEST_RESULT (enemy_setLocation(enemy, 11) == ERROR);
}

void test1_enemy_getLocation() {
    Enemy *enemy;
    enemy = enemy_create();
    enemy_setLocation(enemy, 11);
    PRINT_TEST_RESULT (enemy_getLocation(enemy) == 11);
    enemy_destroy(enemy);
}

void test2_enemy_getLocation() {
    Enemy *enemy;
    enemy = NULL;
    PRINT_TEST_RESULT (enemy_getLocation(enemy) == NO_ID);
}