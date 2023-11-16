//
// Created by amedvedev on 16/11/23.
//

#ifndef FAST_EGYPT_POSITION_H
#define FAST_EGYPT_POSITION_H

#endif //FAST_EGYPT_POSITION_H

#pragma once

#include "consts.h"

int * new_pos(int fill_with = 0);
int * pos_from(const int pos[]);
int * pos_copy(const int * pos);
int * pos_copy_invert(const int * pos);
bool pos_equal(const int * a, const int * b);
void circularShift(int * a, int rotations);

vector<int> get_neigbours(int element);
int * make_move(const int * pos, int cell);