#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "buff_debuff.h"
#include "buff_debuff_test.h"
#include "test.h"


#define MAX_TESTS 16

/** 
 * @brief Main function for BUFF_DEBUFF unit tests. 
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

  if (all || test == 1) test1_bd_create();
  if (all || test == 2) test2_bd_create();
  if (all || test == 3) test1_bd_destroy();
  if (all || test == 4) test2_bd_destroy();
  if (all || test == 5) test1_bd_setType();
  if (all || test == 6) test2_bd_setType();
  if (all || test == 7) test3_bd_setType();
  if (all || test == 8) test4_bd_setType();
  if (all || test == 9) test1_bd_getType();
  if (all || test == 10) test2_bd_getType();
  if (all || test == 11) test1_bd_getValue();
  if (all || test == 12) test2_bd_getValue();
  if (all || test == 13) test1_bd_setValue();
  if (all || test == 14) test2_bd_setValue();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_bd_create() {
  BD *bd;
  bd = bd_create();
  PRINT_TEST_RESULT(bd != NULL);
  bd_destroy(bd);
}

void test2_bd_create() {
  BD *bd;
  bd = bd_create();
  bd_destroy(bd);
  bd = NULL;
  PRINT_TEST_RESULT(bd == NULL);
}

void test1_bd_destroy() {
  BD *bd;
  bd = bd_create();
  PRINT_TEST_RESULT(bd_destroy(bd) == OK);
}

void test2_bd_destroy() {
  BD *bd = NULL;
  PRINT_TEST_RESULT(bd_destroy(bd) == ERROR);
}

void test1_bd_setType() {
  BD *bd;
  bd = bd_create();
  PRINT_TEST_RESULT(bd_setType(bd, 1) == OK);
  bd_destroy(bd);
}

void test2_bd_setType() {
  BD *bd = NULL;
  PRINT_TEST_RESULT(bd_setType(bd, 1) == ERROR);
}

void test3_bd_setType() {
  BD *bd;
  bd = bd_create();
  PRINT_TEST_RESULT(bd_setType(bd, -1) == ERROR);
  bd_destroy(bd);
}

void test4_bd_setType() {
  BD *bd;
  bd = bd_create();
  PRINT_TEST_RESULT(bd_setType(bd, 4) == ERROR);
  bd_destroy(bd);
}

void test1_bd_getType() {
  BD *bd;
  bd = bd_create();
  bd_setType(bd, 1);
  PRINT_TEST_RESULT(bd_getType(bd) == 1);
  bd_destroy(bd);
}

void test2_bd_getType() {
  BD *bd = NULL;
  PRINT_TEST_RESULT(bd_getType(bd) == -1);
}

void test1_bd_getValue() {
  BD *bd;
  bd = bd_create();
  bd_setType(bd, 1);
  bd_setValue(bd, 1.0);
  PRINT_TEST_RESULT(bd_getValue(bd, 1) == 1.0);
  bd_destroy(bd);
}

void test2_bd_getValue() {
  BD *bd = NULL;
  PRINT_TEST_RESULT(bd_getValue(bd, 1) == 0);
}

void test1_bd_setValue() {
  BD *bd;
  bd = bd_create();
  bd_setType(bd, 1);
  PRINT_TEST_RESULT(bd_setValue(bd, 1.0) == OK);
  bd_destroy(bd);
}

void test2_bd_setValue() {
  BD *bd = NULL;
  PRINT_TEST_RESULT(bd_setValue(bd, 1.0) == ERROR);
}




