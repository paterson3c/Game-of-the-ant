#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "xp.h"
#include "xp_test.h"
#include "test.h"


#define MAX_TESTS 24

/** 
 * @brief Main function for XP unit tests. 
 * 
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed 
 *   2.- A number means a particular test (the one identified by that number) 
 *       is executed
 *  
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_xp_create();
    if (all || test == 2) test2_xp_create();
    if (all || test == 3) test1_xp_destroy();
    if (all || test == 4) test2_xp_destroy();
    if (all || test == 5) test1_xp_setXp();
    if (all || test == 6) test2_xp_setXp();
    if (all || test == 7) test1_xp_setLevel();
    if (all || test == 8) test2_xp_setLevel();
    if (all || test == 9) test3_xp_setLevel();
    if (all || test == 10) test4_xp_setLevel();
    if (all || test == 11) test1_xp_getXp();
    if (all || test == 12) test2_xp_getXp();
    if (all || test == 13) test1_xp_getMaxXp();
    if (all || test == 14) test2_xp_getMaxXp();
    if (all || test == 15) test1_xp_getLevel();
    if (all || test == 16) test2_xp_getLevel();
    if (all || test == 17) test1_xp_levelUp();
    if (all || test == 18) test2_xp_levelUp();
    if (all || test == 19) test1_addXp();
    if (all || test == 20) test2_addXp();
    if (all || test == 21) test3_addXp();
    if (all || test == 22) test1_setMaxXp();
    if (all || test == 23) test2_setMaxXp();
    if (all || test == 24) test3_setMaxXp();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}


void test1_xp_create() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp != NULL);
  xp_destroy(xp);
}

void test2_xp_create() {
  XP *xp;
  xp = xp_create();
  xp_destroy(xp);
  xp = NULL;
  PRINT_TEST_RESULT(xp == NULL);
}

void test1_xp_destroy() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_destroy(xp) == OK);
}

void test2_xp_destroy() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_destroy(xp) == ERROR);
}

void test1_xp_setXp() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setXp(xp, 100) == OK);
  xp_destroy(xp);
}

void test2_xp_setXp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_setXp(xp, 100) == ERROR);
}

void test1_xp_setLevel() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setLevel(xp, 3) == OK);
  xp_destroy(xp);
}

void test2_xp_setLevel() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_setLevel(xp, 3) == ERROR);
}

void test3_xp_setLevel() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setLevel(xp, 10) == ERROR);
  xp_destroy(xp);
}

void test4_xp_setLevel() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setLevel(xp, -1) == ERROR);
  xp_destroy(xp);
}

void test1_xp_getXp() {
  XP *xp;
  xp = xp_create();
  xp_setXp(xp, 100);
  PRINT_TEST_RESULT(xp_getXp(xp) == 100);
  xp_destroy(xp);
}

void test2_xp_getXp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_getXp(xp) == -1);
}

void test1_xp_getMaxXp() {
  XP *xp;
  xp = xp_create();
  xp_setMaxXp(xp, 100);
  PRINT_TEST_RESULT(xp_getMaxXp(xp) == 100);
  xp_destroy(xp);
}

void test2_xp_getMaxXp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_getMaxXp(xp) == -1);
}

void test1_xp_getLevel() {
  XP *xp;
  xp = xp_create();
  xp_setLevel(xp, 3);
  PRINT_TEST_RESULT(xp_getLevel(xp) == 3);
  xp_destroy(xp);
}

void test2_xp_getLevel() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_getLevel(xp) == -1);
}

void test1_xp_levelUp() {
  XP *xp;
  xp = xp_create();
  xp_setXp(xp, 100);
  xp_setMaxXp(xp, 100);
  PRINT_TEST_RESULT(xp_levelUp(xp) == OK);
  xp_destroy(xp);
}

void test2_xp_levelUp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_levelUp(xp) == ERROR);
}

void test1_addXp() {
  XP *xp;
  xp = xp_create();
  xp_setXp(xp, 100);
  PRINT_TEST_RESULT(addXp(xp, 100) == OK);
  xp_destroy(xp);
}

void test2_addXp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(addXp(xp, 100) == ERROR);
}

void test3_addXp() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(addXp(xp, -1) == ERROR);
  xp_destroy(xp);
}

void test1_setMaxXp() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setMaxXp(xp, 100) == OK);
  xp_destroy(xp);
}

void test2_setMaxXp() {
  XP *xp = NULL;
  PRINT_TEST_RESULT(xp_setMaxXp(xp, 100) == ERROR);
}

void test3_setMaxXp() {
  XP *xp;
  xp = xp_create();
  PRINT_TEST_RESULT(xp_setMaxXp(xp, -1) == ERROR);
  xp_destroy(xp);
}


