//
// Created by amedvedev on 16/11/23.
//

#include "position.h"
#include "consts.h"



int * new_pos(int fill_with) {
    int * new_pos = new int[n];
    for (int i = 0; i <n; i++) {
        new_pos[i] = fill_with;
    }
    return new_pos;
}

int * pos_from(const int pos[]) {
    int * new_pos = new int[n];
    for (int i = 0; i <n; i++) {
        new_pos[i] = pos[i];
    }
    return new_pos;
}


int * pos_copy(const int * pos) {
    int * new_pos = new int[n];
    for (int i = 0; i <n; i++) {
        new_pos[i] = pos[i];
    }
    return new_pos;
}

int * pos_copy_invert(const int * pos) {
    int * new_pos = new int[n];
    for (int i = 0; i <n; i++) {
        new_pos[i] = (int) !pos[i];
    }
    return new_pos;
}

bool pos_equal(const int * a, const int * b) {
    for (int i = 0; i <n; i++) if (a[i] != b[i]) return false;
    return true;
}

void circularShift(int * a, int rotations) {
    int temp = a[0];
    for (int i = 0; i <n; i++) {
        int temp1 = a[((i + 1) * rotations) % n];
        a[((i + 1) * rotations) % n] = temp;
        temp = temp1;
    }
}

vector<int> get_neigbours(int element) {
    switch (element) {
        case 0:
            return {7, 1};
        case 7:
            return {6, 1};
        default:
            if (element >= 0 && element < n)
                return {element - 1, element + 1};
            else
                throw invalid_argument("Invalid index for neighbors search");
    }
}

int * make_move(const int * pos, const int cell) {
    vector<int> neighbours = get_neigbours(cell);
    int * new_pos = pos_copy(pos);
    for (int neighbour : neighbours) {
        new_pos[neighbour] = !new_pos[neighbour];
    }
    new_pos[cell] = !new_pos[cell];
    return new_pos;
}
