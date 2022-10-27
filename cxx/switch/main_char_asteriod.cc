#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "argc:" << argc << endl;
        return -1;
    }

    switch(argv[1]) {
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
