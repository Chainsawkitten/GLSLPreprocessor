#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char* argv[]) {
    // Print help
    if (argc == 1 || strcmp(argv[0], "--help") == 0) {
        cout << "GLSLPreprocessor is a simple preprocessor for GLSL files." << endl
             << "Usage:" << endl
             << "GLSLPreprocessor input output" << endl;
        return 0;
    }
    
    // Get input and output names.
    string inputName = argv[1];
    string outputName;
    if (argc > 2)
        outputName = argv[2];
    else
        outputName = inputName;
    
    // TODO: Process file.
    string output = "";
    
    // Write output file.
    ofstream outFile(outputName.c_str());
    outFile << output;
    outFile.close();
    
    return 0;
}
