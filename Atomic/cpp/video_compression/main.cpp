#include <iostream>
using namespace std;

int main(void) {
    auto cmd_prog = "ffmpeg";
    auto cmd_input_file = "-i";
    auto cmd_flag_c_v = "-c:v libvpx-vp9";
    auto cmd_flag_minrate = "-minrate";
    auto cmd_flag_maxrate = "-maxrate";
    auto cmd_flat_birate = "-b:v";
    auto cmd_output_file = "";
    
    cout << cmd_prog << " " << cmd_input_file;
    return 0;
}
