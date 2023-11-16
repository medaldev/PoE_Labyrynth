//
// Created by amedvedev on 16/11/23.
//

#include "engine.h"


vector<int> pattern_match(const int * pos, const int l, const int o) {

    // basic cases

    const int all_empty[n] = {l, l, l, l, l, l, l, l};
    if (pos_equal(pos, all_empty)) return {0, 1, 2, 3, 4, 5, 6, 7};

    const int only_one_full[n] = {o, l, l, l, l, l, l, l};
    if (pos_equal(pos, only_one_full)) return {1, 4, 7};

    const int only_one_missing[n] = {l, o, o, o, o, o, o, o};
    if (pos_equal(pos, only_one_missing)) return {0, 2, 3, 5, 6};

    // 2 gap variants

    const int two_gap_o[n] = {l, l, o, o, o, o, o, o};
    if (pos_equal(pos, two_gap_o)) return {1, 0, 2, 4, 5, 7};

    const int two_gap_2[n] = {l, o, l, o, o, o, o, o};
    if (pos_equal(pos, two_gap_2)) return {3, 4, 6, 7};

    const int two_gap_3[n] = {l, o, o, l, o, o, o, o};
    if (pos_equal(pos, two_gap_3)) return {1, 2};

    const int two_gap_4[n] = {l, o, o, o, l, o, o, o};
    if (pos_equal(pos, two_gap_4)) return {1, 0, 3, 4, 5, 7};

    // 3 gap variants

    const int three_gap_o[n] = {l, l, o, o, o, o, o, l};
    if (pos_equal(pos, three_gap_o)) return {0};

    const int three_gap_2[n] = {l, o, l,  o, o, o, l, o};
    if (pos_equal(pos, three_gap_2)) return {1, 0, 7};

    const int three_gap_3[n] = {l, l, o, l, o, o, o, o};
    if (pos_equal(pos, three_gap_3)) return {2, 3, 4, 6, 7};

    const int three_gap_4[n] = {l, l, o, o, l, o, o, o};
    if (pos_equal(pos, three_gap_4)) return {0, 5, 6};

    const int three_gap_5[n] = {l, o, o, l, o, l, o, o};
    if (pos_equal(pos, three_gap_5)) return {0, 1, 7, 3, 5};

    // 4 gap variants

    const int four_gap_o[n] = {l, o, l, o, l, o, l, o};
    if (pos_equal(pos, four_gap_o)) return {0, 2, 4, 6};

    const int four_gap_2[n] = {l, l, o, o, l, o, o, l};
    if (pos_equal(pos, four_gap_2)) return {0, 1, 2, 4, 6, 7};

    const int four_gap_3[n] = {l, l, o, o, l, l, o, o};
    if (pos_equal(pos, four_gap_3)) return {2, 3, 6, 7};

    const int four_gap_4[n] = {l, l, o, o, l, o, l, o};
    const int four_gap_4_2[n] = {o, l, o, o, l, o, l, l};
    const int four_gap_4_3[n] = {o, l, o, l, o, o, l, l};
    if (pos_equal(pos, four_gap_4)) return {1, 3, 4, 5};
    else if (pos_equal(pos, four_gap_4_2)) return {0, 7, 6, 5};
    else if (pos_equal(pos, four_gap_4_3)) return {2, 3, 6, 4};


    return {};
}

int shift_index_sol(int i, int rotations) {
    for (int k = 1; k < rotations + 1; k++) {
        i -= 1;
        if (i == -1) i = n - 1;
    }
    return i;
}

void shift_sol(vector<int> &sol, int shift) {
    for (int & i : sol) {
        i = shift_index_sol(i, shift);
    }
}


vector<int> PoE_Labyrynth(const int * pos) {

    vector<int> res = pattern_match(pos, 0, 1);

    if (res.empty()) {
        for (int move = 0; move < n; move++) {
            int * new_pos = make_move(pos, move);
            res = pattern_match(new_pos, 0, 1);
            if (!res.empty()) {
                res.insert(res.begin(), move);
                break;
            }

        }

    }

    return res;

}

vector<int> find_solution(int * current_pos) {
    int *shifted = nullptr;
    int shift_counter = 0;

    vector<int> sol = PoE_Labyrynth(current_pos);

    if (sol.empty()) {
        shifted = pos_copy(current_pos);
        circularShift(shifted, 1);
        shift_counter++;

        while (!pos_equal(current_pos, shifted)) {
            // print_pos(shifted);
            sol = PoE_Labyrynth(shifted);
            if (!sol.empty()) {
                // print_sol(sol);
                shift_sol(sol, shift_counter);
                // cout << shift_counter << endl;
                // print_sol(sol);

                break;
            }
            circularShift(shifted, 1);
            shift_counter++;
        }

    }

    delete[] shifted;

    return sol;
}

