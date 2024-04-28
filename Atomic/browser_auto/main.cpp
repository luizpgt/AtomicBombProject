#include <iostream>
#include <string>

using namespace std;

int main (void) {
    int i;
    const string url("https://qualquer.algo/image/title/*.gif");
    string::size_type idx = url.find("*");
    string start, end, furl;
    start = url.substr(0, idx);
    end = url.substr(idx+1);

    for (i = 0; i < 254; i++) {
        furl = start;
        furl += to_string(i);
        furl += end;
        cout << furl <<"\n";
    }
    return 0;
}
