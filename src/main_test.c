/** 
 * @brief It tests space module
 * 
 * @file space_test.c
 * @author Profesores Pprog
 * @version 3.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "space.h"
#include "space_test.h"
#include "link.h"
#include "link_test.h"
#include "set.h"
#include "set_test.h"
#include "inventory.h"
#include "inventory_test.h"
#include "enemy.h"
#include "enemy_test.h"
#include "buff_debuff.h"
#include "buff_debuff_test.h"
#include "xp.h"
#include "xp_test.h"
#include "test.h"

#define MAX_TESTS 36

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
    printf("Running all test for modules Space, Link, Set, Inventory, Enemy, BuffDebuff, Xp:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


    if (all || test == 1) test1_space_create();
    if (all || test == 2) test2_space_create();
    if (all || test == 3) test1_space_set_name();
    if (all || test == 4) test2_space_set_name();
    if (all || test == 5) test3_space_set_name();
    if (all || test == 6) test1_space_set_north();
    if (all || test == 7) test2_space_set_north();
    if (all || test == 8) test1_space_set_south();
    if (all || test == 9) test2_space_set_south();
    if (all || test == 10) test1_space_set_east();
    if (all || test == 11) test2_space_set_east();
    if (all || test == 12) test1_space_set_west();
    if (all || test == 13) test2_space_set_west();
    if (all || test == 14) test1_space_get_name();
    if (all || test == 15) test2_space_get_name();
    if (all || test == 16) test1_space_has_object();
    if (all || test == 17) test2_space_has_object();
    if (all || test == 18) test3_space_has_object();
    if (all || test == 19) test1_space_get_north();
    if (all || test == 20) test2_space_get_north();
    if (all || test == 21) test1_space_get_south();
    if (all || test == 22) test2_space_get_south();
    if (all || test == 23) test1_space_get_east();
    if (all || test == 24) test2_space_get_east();
    if (all || test == 25) test1_space_get_west();
    if (all || test == 26) test2_space_get_west();
    if (all || test == 27) test1_space_get_id();
    if (all || test == 28) test2_space_get_id();
    if (all || test == 29) test1_space_add_object();
    if (all || test == 30) test2_space_add_object();
    if (all || test == 31) test1_space_get_objects();
    if (all || test == 32) test2_space_get_objects();
    if (all || test == 33) test3_space_get_objects();
    if (all || test == 34) test1_space_delete_object();
    if (all || test == 35) test2_space_delete_object();
    if (all || test == 36) test3_space_delete_object();

    printf("End of tests for module Space\n");

    if (all || test == 37) test1_link_create();
    if (all || test == 38) test2_link_create();
    if (all || test == 39) test3_link_create();
    if (all || test == 40) test1_link_destroy();
    if (all || test == 41) test2_link_destroy();
    if (all || test == 42) test1_link_set_name();
    if (all || test == 43) test2_link_set_name();
    if (all || test == 44) test3_link_set_name();
    if (all || test == 45) test1_link_set_id();
    if (all || test == 46) test2_link_set_id();
    if (all || test == 47) test3_link_set_id();
    if (all || test == 48) test1_link_set_orig();
    if (all || test == 49) test2_link_set_orig();
    if (all || test == 50) test3_link_set_orig();
    if (all || test == 51) test1_link_set_dest();
    if (all || test == 52) test2_link_set_dest();
    if (all || test == 53) test3_link_set_dest();
    if (all || test == 54) test1_link_set_open();
    if (all || test == 55) test2_link_set_open();
    if (all || test == 56) test3_link_set_open();
    if (all || test == 57) test1_link_get_name();
    if (all || test == 58) test2_link_get_name();
    if (all || test == 59) test1_link_get_id();
    if (all || test == 60) test2_link_get_id();
    if (all || test == 61) test1_link_get_orig();
    if (all || test == 62) test2_link_get_orig();
    if (all || test == 63) test1_link_get_dest();
    if (all || test == 64) test2_link_get_dest();
    if (all || test == 65) test1_link_get_open();
    if (all || test == 66) test2_link_get_open();
    if (all || test == 67) test1_link_print();
    if (all || test == 68) test2_link_print();
    if (all || test == 69) test1_link_get_direction();
    if (all || test == 70) test2_link_get_direction();
    if (all || test == 71) test3_link_get_direction();
    if (all || test == 72) test1_link_set_direction();
    if (all || test == 73) test2_link_set_direction();
    if (all || test == 74) test3_link_set_direction();
  
    printf("End of tests for module Link\n");

    if (all || test == 75) test1_set_create();
    if (all || test == 76) test2_set_create();
    if (all || test == 77) test1_set_add();
    if (all || test == 78) test2_set_add();
    if (all || test == 79) test3_set_add();
    if (all || test == 80) test1_set_del();
    if (all || test == 81) test2_set_del();
    if (all || test == 82) test3_set_del();
    if (all || test == 83) test1_set_get_numberofIds();
    if (all || test == 84) test2_set_get_numberofIds();
    if (all || test == 85) test1_set_get_ids();
    if (all || test == 86) test2_set_get_ids();
    if (all || test == 87) test1_set_contains();
    if (all || test == 88) test2_set_contains();
    if (all || test == 89) test1_set_destroy();
    if (all || test == 90) test2_set_destroy();

    printf("End of tests for module Set\n");

    if (all || test == 91) test1_inv_create();
    if (all || test == 92) test2_inv_create();
    if (all || test == 93) test1_inv_destroy();
    if (all || test == 94) test2_inv_destroy();
    if (all || test == 95) test1_inv_isFull();
    if (all || test == 96) test2_inv_isFull();
    if (all || test == 97) test3_inv_isFull();
    if (all || test == 98) test1_inv_isEmpty();
    if (all || test == 99) test2_inv_isEmpty();
    if (all || test == 100) test1_inv_add();
    if (all || test == 101) test2_inv_add();
    if (all || test == 102) test3_inv_add();
    if (all || test == 103) test4_inv_add();
    if (all || test == 104) test1_inv_del();
    if (all || test == 105) test2_inv_del();
    if (all || test == 106) test3_inv_del();
    if (all || test == 107) test4_inv_del();
    if (all || test == 108) test1_inv_getMaxObjects();
    if (all || test == 109) test2_inv_getMaxObjects();
    if (all || test == 110) test1_inv_getObjs();
    if (all || test == 111) test2_inv_getObjs();
    if (all || test == 112) test1_inv_getIds();
    if (all || test == 113) test2_inv_getIds();
    if (all || test == 114) test1_inv_setMaxObjs();
    if (all || test == 115) test2_inv_setMaxObjs();
    if (all || test == 116) test3_inv_setMaxObjs();

    printf("End of tests for module Inventory\n");

    if (all || test == 117) test1_enemy_create();
    if (all || test == 118) test1_enemy_destroy();
    if (all || test == 119) test2_enemy_destroy();
    if (all || test == 120) test1_enemy_getName();
    if (all || test == 121) test2_enemy_getName();
    if (all || test == 122) test1_enemy_setHealth();
    if (all || test == 123) test2_enemy_setHealth();
    if (all || test == 124) test1_enemy_getId();
    if (all || test == 125) test2_enemy_getId();
    if (all || test == 126) test1_enemy_getName();
    if (all || test == 127) test2_enemy_getName();
    if (all || test == 128) test1_enemy_getHealth();
    if (all || test == 129) test2_enemy_getHealth();
    if (all || test == 130) test1_enemy_setId();
    if (all || test == 131) test2_enemy_setId();
    if (all || test == 132) test1_enemy_setLocation();
    if (all || test == 133) test2_enemy_setLocation();
    if (all || test == 134) test1_enemy_getLocation();
    if (all || test == 135) test2_enemy_getLocation();

    printf("End of tests for module Enemy\n");

    if (all || test == 136) test1_bd_create();
    if (all || test == 137) test2_bd_create();
    if (all || test == 138) test1_bd_destroy();
    if (all || test == 139) test2_bd_destroy();
    if (all || test == 140) test1_bd_setType();
    if (all || test == 141) test2_bd_setType();
    if (all || test == 142) test3_bd_setType();
    if (all || test == 143) test4_bd_setType();
    if (all || test == 144) test1_bd_getType();
    if (all || test == 145) test2_bd_getType();
    if (all || test == 146) test1_bd_getValue();
    if (all || test == 147) test2_bd_getValue();
    if (all || test == 148) test1_bd_setValue();
    if (all || test == 149) test2_bd_setValue();

    printf("End of tests for module BuffDebuff\n");

    if (all || test == 150) test1_xp_create();
    if (all || test == 151) test2_xp_create();
    if (all || test == 152) test1_xp_destroy();
    if (all || test == 153) test2_xp_destroy();
    if (all || test == 154) test1_xp_setXp();
    if (all || test == 155) test2_xp_setXp();
    if (all || test == 156) test1_xp_setLevel();
    if (all || test == 157) test2_xp_setLevel();
    if (all || test == 158) test3_xp_setLevel();
    if (all || test == 159) test4_xp_setLevel();
    if (all || test == 160) test1_xp_getXp();
    if (all || test == 161) test2_xp_getXp();
    if (all || test == 162) test1_xp_getMaxXp();
    if (all || test == 163) test2_xp_getMaxXp();
    if (all || test == 164) test1_xp_getLevel();
    if (all || test == 165) test2_xp_getLevel();
    if (all || test == 166) test1_xp_levelUp();
    if (all || test == 167) test2_xp_levelUp();
    if (all || test == 168) test1_addXp();
    if (all || test == 169) test2_addXp();
    if (all || test == 170) test3_addXp();
    if (all || test == 171) test1_setMaxXp();
    if (all || test == 172) test2_setMaxXp();
    if (all || test == 173) test3_setMaxXp();

    printf("End of tests for module Xp\n");

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

void test1_space_set_south() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

void test1_space_set_east() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

void test1_space_set_west() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
  space_destroy(s);
}

void test2_space_set_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

void test1_space_add_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_add_object(s, 21) == OK);
  space_destroy(s);
}

void test2_space_add_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_add_object(s, 21) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_has_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_has_object(s, 21) == FALSE);
  space_destroy(s);
}

void test2_space_has_object() {
  Space *s;
  s = space_create(1);
  space_add_object(s, 21);
  PRINT_TEST_RESULT(space_has_object(s, 21) == TRUE);
  space_destroy(s);  
}

void test3_space_has_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_has_object(s, 21) == FALSE);
}

void test1_space_get_north() {
  Space *s;
  s = space_create(5);
  space_set_north(s, 4);
  PRINT_TEST_RESULT(space_get_north(s) == 4);
  space_destroy(s);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
  Space *s;
  s = space_create(5);
  space_set_south(s, 2);
  PRINT_TEST_RESULT(space_get_south(s) == 2);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
  Space *s;
  s = space_create(5);
  space_set_east(s, 1);
  PRINT_TEST_RESULT(space_get_east(s) == 1);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
  Space *s;
  s = space_create(5);
  space_set_west(s, 6);
  PRINT_TEST_RESULT(space_get_west(s) == 6);
  space_destroy(s);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_get_objects() {
  Space *s = NULL;
  s = space_create(1);
  space_add_object(s, 21);
  PRINT_TEST_RESULT(space_get_objects(s) != NULL);
  space_destroy(s);
}

void test2_space_get_objects() {
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
  space_destroy(s);
}

void test3_space_get_objects() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_objects(s) == NULL);
}

void test1_space_delete_object() {
  Space *s = NULL;
  s = space_create(1);
  PRINT_TEST_RESULT(space_delete_object(s, 21) == ERROR);
  space_destroy(s);
}

void test2_space_delete_object() {
  Space *s = NULL;
  s = space_create(1);
  space_add_object(s, 21);
  PRINT_TEST_RESULT(space_delete_object(s, 21) == OK);
  space_destroy(s);
}

void test3_space_delete_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_delete_object(s, 21) == ERROR);
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

void test1_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(s != NULL);
  set_destroy(s);
}
void test2_set_create() {
  Set *s;
  s = set_create();
  set_destroy(s);
  s = NULL;
  PRINT_TEST_RESULT(s == NULL);
}

void test1_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, 5) == OK);
  set_destroy(s);
}

void test2_set_add() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add(s, 5) == ERROR);
}

void test3_set_add() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_add(s, NO_ID) == ERROR);
  set_destroy(s);
}

void test1_set_del() {
  Set *s;
  s = set_create();
  set_add(s,5);
  PRINT_TEST_RESULT(set_del(s, 5) == OK);
  set_destroy(s);
}

void test2_set_del() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_del(s, 5) == ERROR);
}

void test3_set_del() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_del(s, 4) == ERROR);
  set_destroy(s);
}

void test1_set_get_numberofIds() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_numberofIds(s) == 0);
  set_destroy(s);
}

void test2_set_get_numberofIds(){
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_numberofIds(s) == -1);
}

void test1_set_get_ids(){
  Set *s;
  s = set_create();
  set_add(s,4);
  PRINT_TEST_RESULT(set_get_ids(s) != NULL);
  set_destroy(s);
}

void test2_set_get_ids() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_ids(s) == NULL);
}

void test1_set_contains(){
  Set *s;
  s = set_create();
  set_add(s,4);
  PRINT_TEST_RESULT(set_contains(s,4) == TRUE);
  set_destroy(s);
}

void test2_set_contains(){
  Set *s;
  s = set_create();
  set_add(s,4);
  PRINT_TEST_RESULT(set_contains(s,5) == FALSE);
  set_destroy(s);
}

void test1_set_destroy(){
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_destroy(s) == OK);
}

void test2_set_destroy(){
  Set *s = NULL;
  PRINT_TEST_RESULT(set_destroy(s) == ERROR);
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