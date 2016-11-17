#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string GetParentDirectory(const string& path) {
    for (size_t i = path.length() - 1; i > 0; --i) {
        if (path[i] == '\\' || path[i] == '/')
            return path.substr(0, i);
    }
    
    return path;
}

string ProcessFile(const string& filename);

string ProcessLine(const string& line, const string& directory) {
    if (line.substr(0, 8) == "#include") {
        size_t startPosition = line.find('"') + 1;
        size_t endPosition = line.find('"', startPosition);
        string filename = directory + "/" + line.substr(startPosition, endPosition - startPosition);
        return ProcessFile(filename);
    }
    
    return line;
}

string ProcessFile(const string& filename) {
    string contents = "";
    string directory = GetParentDirectory(filename);
    
    string line;
    ifstream inFile(filename.c_str());
    while (getline(inFile, line))
        contents += ProcessLine(line, directory) + "\n";
    
    inFile.close();
    
    return contents;
}

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
    
    // Process file.
    string output = ProcessFile(inputName);
    
    // Write output file.
    ofstream outFile(outputName.c_str());
    outFile << output;
    outFile.close();
    
    return 0;
}
