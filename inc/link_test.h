/** 
 * @brief It declares the tests for the link module
 * 
 * @file link_test.h
 * @author Miguel Paterson
 * @version 1.0 
 * @date 23-03-2023
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test the link creation function
 * @pre A link structure
 * @post Non NULL pointer to the link
 */
void test1_link_create();

/**
 * @test Test the link creation function
 * @pre A link structure
 * @post The link id is the same as the input
 */
void test2_link_create();

/**
 * @test Test the link creation function
 * @pre A link structure
 * @post The link id is the same as the input
 */
void test3_link_create();


void test1_link_destroy();
void test2_link_destroy();
void test3_link_destroy();

void test1_link_set_name();
void test2_link_set_name();
void test3_link_set_name();

void test1_link_set_id();
void test2_link_set_id();
void test3_link_set_id();

void test1_link_set_orig();
void test2_link_set_orig();
void test3_link_set_orig();

void test1_link_set_dest();
void test2_link_set_dest();
void test3_link_set_dest();

void test1_link_set_open();
void test2_link_set_open();
void test3_link_set_open();

void test1_link_get_name();
void test2_link_get_name();

void test1_link_get_id();
void test2_link_get_id();

void test1_link_get_orig();
void test2_link_get_orig();

void test1_link_get_dest();
void test2_link_get_dest();

void test1_link_get_open();
void test2_link_get_open();

void test1_link_print();
void test2_link_print();

void test1_link_get_direction();
void test2_link_get_direction();
void test3_link_get_direction();

void test1_link_set_direction();
void test2_link_set_direction();
void test3_link_set_direction();

#endif
