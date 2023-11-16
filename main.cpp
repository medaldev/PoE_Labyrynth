#include <vector>

#include "stream.h"
#include "engine.h"


using namespace std;


int main() {

    // const int init_data[n] = {1, 1, 0, 1, 1, 1, 0, 1};

    // print_pos(init_data);

    int * current_pos = read_vector(); // Load row from input_position.txt

    print_pos(current_pos);

    vector<int> sol = find_solution(current_pos);

    writeSol(sol); // Save solution to fastest_answer.txt

    delete[] current_pos;

    return 0;
}