//
// Created by jmgduarte on 24/09/20.
//

#ifndef LINKED_LIST_LINKED_LIST_TESTS_H
#define LINKED_LIST_LINKED_LIST_TESTS_H

#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

#define LOG() fprintf(stdout, "Running test \"%s\"\n", __func__);

void insert_empty_list();
void insert_single_element_list();
void insert_multiple_element_list();

#endif //LINKED_LIST_LINKED_LIST_TESTS_H
