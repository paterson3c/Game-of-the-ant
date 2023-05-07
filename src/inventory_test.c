#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"


#define MAX_TESTS 16

/** 
 * @brief Main function for INVENTORY unit tests. 
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

  if (all || test == 1) test1_inv_create();
  if (all || test == 2) test2_inv_create();
  if (all || test == 3) test1_inv_destroy();
  if (all || test == 4) test2_inv_destroy();
  if (all || test == 5) test1_inv_isFull();
  if (all || test == 6) test2_inv_isFull();
  if (all || test == 7) test3_inv_isFull();
  if (all || test == 8) test1_inv_isEmpty();
  if (all || test == 9) test2_inv_isEmpty();
  if (all || test == 10) test1_inv_add();
  if (all || test == 11) test2_inv_add();
  if (all || test == 12) test3_inv_add();
  if (all || test == 13) test4_inv_add();
  if (all || test == 14) test1_inv_del();
  if (all || test == 15) test2_inv_del();
  if (all || test == 16) test3_inv_del();
  if (all || test == 17) test4_inv_del();
  if (all || test == 18) test1_inv_getMaxObjects();
  if (all || test == 19) test2_inv_getMaxObjects();
  if (all || test == 20) test1_inv_getObjs();
  if (all || test == 21) test2_inv_getObjs();
  if (all || test == 22) test1_inv_getIds();
  if (all || test == 23) test2_inv_getIds();
  if (all || test == 24) test1_inv_setMaxObjs();
  if (all || test == 25) test2_inv_setMaxObjs();
  if (all || test == 26) test3_inv_setMaxObjs();

  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_inv_create() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inv != NULL);
  inventory_destroy(inv);
}

void test2_inv_create() {
  Inventory *inv;
  inv = inventory_create();
  inventory_destroy(inv);
  inv = NULL;
  PRINT_TEST_RESULT(inv == NULL);
}

void test1_inv_destroy() {
  Inventory* inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_destroy(inv) == OK);
}

void test2_inv_destroy() {
  Inventory* inv = NULL;
  PRINT_TEST_RESULT(inventory_destroy(inv) == ERROR);
}

void test1_inv_isFull() {
  Inventory *inv;
  inv = inventory_create();
  inventory_add(inv, 3);
  inventory_setMaxObjs(inv, 1);
  PRINT_TEST_RESULT(inventory_isFull(inv) == TRUE);
  inventory_destroy(inv);
}

void test2_inv_isFull() {
  Inventory* inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_isFull(inv) == FALSE);
  inventory_destroy(inv);
}

void test3_inv_isFull() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_isFull(inv) == FALSE);
}

void test1_inv_isEmpty() {
  Inventory* inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_isEmpty(inv) == TRUE);
  inventory_destroy(inv);
}

void test2_inv_isEmpty() {
  Inventory* inv;
  inv = inventory_create();
  inventory_add(inv, 3);
  PRINT_TEST_RESULT(inventory_isEmpty(inv) == FALSE);
  inventory_destroy(inv);
}

void test1_inv_add() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_add(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inv_add() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_add(inv, NO_ID) == ERROR);
  inventory_destroy(inv);
}

void test3_inv_add() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_add(inv, 5) == ERROR);
}

void test4_inv_add() {
  Inventory *inv;
  inv = inventory_create();
  inventory_setMaxObjs(inv, 0);
  PRINT_TEST_RESULT(inventory_add(inv, 5) == ERROR);
  inventory_destroy(inv);
}

void test1_inv_del() {
  Inventory *inv;
  inv = inventory_create();
  inventory_add(inv, 5);
  PRINT_TEST_RESULT(inventory_del(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inv_del() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_del(inv, 5) == ERROR);
  inventory_destroy(inv);
}

void test3_inv_del() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_del(inv, 5) == ERROR);
}

void test4_inv_del() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_del(inv, NO_ID) == ERROR);
  inventory_destroy(inv);
}

void test1_inv_getMaxObjects() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_getMaxObjects(inv) != NO_ID);
  inventory_destroy(inv);
}

void test2_inv_getMaxObjects() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_getMaxObjects(inv) == NO_ID);
}

void test1_inv_getObjs() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_getObjs(inv) != NULL);
  inventory_destroy(inv);
}

void test2_inv_getObjs() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_getObjs(inv) == NULL);
}

void test1_inv_getIds() {
  Inventory *inv;
  inv = inventory_create();
  inventory_add(inv, 5);
  PRINT_TEST_RESULT(inventory_getIds(inv) != NULL);
  inventory_destroy(inv);
}

void test2_inv_getIds() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_getIds(inv) == NULL);
}

void test1_inv_setMaxObjs() {
  Inventory *inv = NULL;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_setMaxObjs(inv, 4) == OK);
  inventory_destroy(inv);
}

void test2_inv_setMaxObjs() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_setMaxObjs(inv, 4) == ERROR);
}

void test3_inv_setMaxObjs() {
  Inventory *inv;
  inv = inventory_create();
  PRINT_TEST_RESULT(inventory_setMaxObjs(inv, NO_ID) == ERROR);
  inventory_destroy(inv);
}