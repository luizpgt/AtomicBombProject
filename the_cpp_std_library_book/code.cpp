/*
 * header files
 */

// header files no longer have extensions as used to (.h .hpp .hxx)
// C header files are now used with c prefix instead of .h extension: cstdlib = stdlib.h || cstring = string.h
#include <iostream>

int main() {
    /*
     * about namespaces
     */
    // qualify namespaces directly
    std::cout<< std::hex << 15 << std::endl;
    // qualify namespace using declaration 
    using std::cout;
    cout << "\"using\" declaration\n";
    // using a "using directive"
    using namespace std;
    cout << hex << 15 << endl;
    

}
