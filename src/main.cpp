#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    // Print help
    if (argc == 1 || strcmp(argv[0], "--help") == 0) {
        cout << "GLSLPreprocessor is a simple preprocessor for GLSL files." << endl
             << "Usage:" << endl
             << "GLSLPreprocessor input output" << endl;
        return 0;
    }
    
    return 0;
}
