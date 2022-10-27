#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "argc:" << argc << endl;
        return -1;
    }

    std::string s(argv[1]);
    switch(s) {
        case "first":
            cout << argv[1] << endl;
            break;
        case "second":
            cout << argv[1] << endl;
            break;
        default:
            cout << "default" << endl;
    }

    return 0;
}
