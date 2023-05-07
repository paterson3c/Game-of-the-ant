/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author Miguel Paterson
 * @version 1.0 
 * @date 23-03-2023
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 38

/** 
 * @brief Main function for SPACE unit tests. 
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
    printf("Running all test for module Link:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

    if (all || test == 1) test1_link_create();
    if (all || test == 2) test2_link_create();
    if (all || test == 3) test3_link_create();
    if (all || test == 4) test1_link_destroy();
    if (all || test == 5) test2_link_destroy();
    if (all || test == 6) test1_link_set_name();
    if (all || test == 7) test2_link_set_name();
    if (all || test == 8) test3_link_set_name();
    if (all || test == 9) test1_link_set_id();
    if (all || test == 10) test2_link_set_id();
    if (all || test == 11) test3_link_set_id();
    if (all || test == 12) test1_link_set_orig();
    if (all || test == 13) test2_link_set_orig();
    if (all || test == 14) test3_link_set_orig();
    if (all || test == 15) test1_link_set_dest();
    if (all || test == 16) test2_link_set_dest();
    if (all || test == 17) test3_link_set_dest();
    if (all || test == 18) test1_link_set_open();
    if (all || test == 19) test2_link_set_open();
    if (all || test == 20) test3_link_set_open();
    if (all || test == 21) test1_link_get_name();
    if (all || test == 22) test2_link_get_name();
    if (all || test == 23) test1_link_get_id();
    if (all || test == 24) test2_link_get_id();
    if (all || test == 25) test1_link_get_orig();
    if (all || test == 26) test2_link_get_orig();
    if (all || test == 27) test1_link_get_dest();
    if (all || test == 28) test2_link_get_dest();
    if (all || test == 29) test1_link_get_open();
    if (all || test == 30) test2_link_get_open();
    if (all || test == 31) test1_link_print();
    if (all || test == 32) test2_link_print();
    if (all || test == 33) test1_link_get_direction();
    if (all || test == 34) test2_link_get_direction();
    if (all || test == 35) test3_link_get_direction();
    if (all || test == 36) test1_link_set_direction();
    if (all || test == 37) test2_link_set_direction();
    if (all || test == 38) test3_link_set_direction();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_link_create() {
  Link *link = NULL;

  PRINT_TEST_RESULT((link = link_create()) != NULL);
  link_destroy(link);
}

void test2_link_create() {
  Link *link = NULL;

  link = link_create(); 
  PRINT_TEST_RESULT(link != NULL);
  link_destroy(link);
}

void test3_link_create() {
  Link *link = NULL;

  link = link_create(); 
  PRINT_TEST_RESULT(link_getId(link) == NO_ID);
  link_destroy(link);
}

void test1_link_destroy() {
  Link *link = NULL;

  link = link_create(); 
  PRINT_TEST_RESULT(link_destroy(link) == OK);
}

void test2_link_destroy() {
  Link *link = NULL;

  link = link_create(); 
  link_destroy(link);
  link = NULL;
  PRINT_TEST_RESULT(!link);
}

void test1_link_set_name() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";

  link = link_create(); 
  PRINT_TEST_RESULT(link_setName(link, name) == OK);
  link_destroy(link);
}

void test2_link_set_name() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";

  link = link_create(); 
  link_setName(link, name);
  PRINT_TEST_RESULT(strcmp(link_getName(link), name) == 0);
  link_destroy(link);
}

void test3_link_set_name() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";

  link = link_create(); 
  link_setName(link, name);
  PRINT_TEST_RESULT(link_getName(link) != NULL);
  link_destroy(link);
}

void test1_link_set_id() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  PRINT_TEST_RESULT(link_setId(link, id) == OK);
  link_destroy(link);
}

void test2_link_set_id() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setId(link, id);
  PRINT_TEST_RESULT(link_getId(link) == id);
  link_destroy(link);
}

void test3_link_set_id() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setId(link, id);
  PRINT_TEST_RESULT(link_getId(link) != NO_ID);
  link_destroy(link);
}

void test1_link_set_orig() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  PRINT_TEST_RESULT(link_setOrigin(link, id) == OK);
  link_destroy(link);
}

void test2_link_set_orig() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setOrigin(link, id);
  PRINT_TEST_RESULT(link_getOrigin(link) == id);
  link_destroy(link);
}

void test3_link_set_orig() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setOrigin(link, id);
  PRINT_TEST_RESULT(link_getOrigin(link) != NO_ID);
  link_destroy(link);
}

void test1_link_set_dest() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  PRINT_TEST_RESULT(link_setDestination(link, id) == OK);
  link_destroy(link);
}

void test2_link_set_dest() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setDestination(link, id);
  PRINT_TEST_RESULT(link_getDestination(link) == id);
  link_destroy(link);
}

void test3_link_set_dest() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setDestination(link, id);
  PRINT_TEST_RESULT(link_getDestination(link) != NO_ID);
  link_destroy(link);
}

void test1_link_set_open() {
  Link *link = NULL;
  BOOL open = TRUE;

  link = link_create(); 
  PRINT_TEST_RESULT(link_setOpen(link, open) == OK);
  link_destroy(link);
}

void test2_link_set_open() {
  Link *link = NULL;
  BOOL open = TRUE;

  link = link_create(); 
  link_setOpen(link, open);
  PRINT_TEST_RESULT(link_getOpen(link) == open);
  link_destroy(link);
}

void test3_link_set_open() {
  Link *link = NULL;
  PRINT_TEST_RESULT(link_setOpen(link, FALSE) == ERROR);
}

void test1_link_get_name() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";

  link = link_create(); 
  link_setName(link, name);
  PRINT_TEST_RESULT(strcmp(link_getName(link), name) == 0);
  link_destroy(link);
}

void test2_link_get_name() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";

  link = link_create(); 
  link_setName(link, name);
  PRINT_TEST_RESULT(link_getName(link) != NULL);
  link_destroy(link);
}

void test1_link_get_id() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setId(link, id);
  PRINT_TEST_RESULT(link_getId(link) == id);
  link_destroy(link);
}

void test2_link_get_id() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setId(link, id);
  PRINT_TEST_RESULT(link_getId(link) != NO_ID);
  link_destroy(link);
}

void test1_link_get_orig() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setOrigin(link, id);
  PRINT_TEST_RESULT(link_getOrigin(link) == id);
  link_destroy(link);
}

void test2_link_get_orig() {
  Link *link = NULL;
  Id id = 1;

  link = link_create(); 
  link_setOrigin(link, id);
  PRINT_TEST_RESULT(link_getOrigin(link) != NO_ID);
  link_destroy(link);
}

void test1_link_get_dest() {
  Link *link = NULL;
  Id id = 1;

  link = link_create();
  link_setDestination(link, id);
  PRINT_TEST_RESULT(link_getDestination(link) == id);
  link_destroy(link);
}

void test2_link_get_dest() {
  Link *link = NULL;
  Id id = 1;

  link = link_create();
  link_setDestination(link, id);
  PRINT_TEST_RESULT(link_getDestination(link) != NO_ID);
  link_destroy(link);
}

void test1_link_get_open() {
  Link *link = NULL;
  BOOL open = TRUE;

  link = link_create();
  link_setOpen(link, open);
  PRINT_TEST_RESULT(link_getOpen(link) == open);
  link_destroy(link);
}

void test2_link_get_open() {
  Link *link = NULL;
  PRINT_TEST_RESULT(link_getOpen(link) == FALSE);
}

void test1_link_print() {
  Link *link = NULL;
  char name[WORD_SIZE] = "link1";
  Id id = 1;
  Id orig = 2;
  Id dest = 3;
  BOOL open = TRUE;

  link = link_create();
  link_setName(link, name);
  link_setId(link, id);
  link_setOrigin(link, orig);
  link_setDestination(link, dest);
  link_setOpen(link, open);
  PRINT_TEST_RESULT(link_print(link) == OK);
  link_destroy(link);
}

void test2_link_print() {
  Link *link = NULL;
  PRINT_TEST_RESULT(link_print(link) == ERROR);
}

void test1_link_get_direction() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_getDirection(link) == Unkown);
}

void test2_link_get_direction() {
    Link *link = NULL;
    link = link_create();
    PRINT_TEST_RESULT(link_getDirection(link) == Unkown);
    link_destroy(link);
}

void test3_link_get_direction() {
    Link *link = NULL;
    link = link_create();
    link_setDirection(link, N);
    PRINT_TEST_RESULT(link_getDirection(link) == N);
    link_destroy(link);
}

void test1_link_set_direction() {
    Link *link = NULL;
    PRINT_TEST_RESULT(link_setDirection(link, N) == ERROR);
}

void test2_link_set_direction() {
    Link *link = NULL;
    link = link_create();
    PRINT_TEST_RESULT(link_setDirection(link, N) == OK);
    link_destroy(link);
}

void test3_link_set_direction() {
    Link *link = NULL;
    link = link_create();
    link_setDirection(link, N);
    PRINT_TEST_RESULT(link_getDirection(link) == N);
    link_destroy(link);
}
