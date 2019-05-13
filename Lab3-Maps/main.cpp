#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

/*
 *  A Very Basic Natural Language Processing Model
 *
 *  Pairing words together, and remembering that they've been seen before.
 *
 */

void stripPunctuation(std::string &str) {
    
    std::string finalStr = "";
    
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str.at(i))) {
            finalStr.push_back(str.at(i));
        }
    }
    
    str = finalStr;
    
}

int main() {
    std::string docName = "";
    
    std::cout << "Enter the name of a text file: ";
    std::cin  >> docName;
    std::cout << std::endl;
    
    // 1. Read the document into a set of strings and print them to a file.
    std::string setOutputFilename = docName + "_set.txt";
    
    // Open an input file
    std::ifstream inFS;
    inFS.open(docName + ".txt");
    
    if (!inFS.is_open()) {
        std::cout << "Couldn't open " << docName << ".txt for reading." << std::endl;
        return 1;
    }
    
    
    // Read into a string set
    std::set<std::string> stringSet;
    
    while (!inFS.eof()) {
        std::string newString = "";
        inFS >> newString;
        stripPunctuation(newString);
        stringSet.insert(newString);
    }
    
    inFS.close();
    
    // Output to file
    std::ofstream outFS;
    outFS.open(setOutputFilename);
    
    if (!outFS.is_open()) {
        std::cout << "Couldn't open " << setOutputFilename << " for writing." << std::endl;
    }
    
    for (std::set<std::string>::iterator it = stringSet.begin(); it != stringSet.end(); it++) {
        outFS << *it << std::endl;
//        std::cout << *it << std::endl;
    }
    std::cout << std::endl << stringSet.size() << " elements in set for " << docName << ".txt" << std::endl;
    stringSet.clear();
    
    outFS.close();
    
    std::cout << "File written to " << setOutputFilename << std::endl;
    
    
    // 2. Read the document into a vector of strings and print them to a file.
    std::string vectorOutputFilename = docName + "_vector.txt";
    
    // Open an input file
    inFS.open(docName + ".txt");
    
    if (!inFS.is_open()) {
        std::cout << "Couldn't open " << docName << ".txt for reading." << std::endl;
        return 1;
    }
    
    // Read into string set
    std::vector<std::string> stringVector;
    
    while (!inFS.eof()) {
        std::string newString = "";
        inFS >> newString;
        stripPunctuation(newString);
        stringVector.push_back(newString);
    }
    
    inFS.close();
    
    // Output to file
    outFS.open(vectorOutputFilename);
    
    if (!outFS.is_open()) {
        std::cout << "Couldn't open " << vectorOutputFilename << " for writing." << std::endl;
    }
    
    for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); it++) {
        outFS << *it << std::endl;
//        std::cout << *it << std::endl;
    }
    std::cout << std::endl << stringVector.size() << " elements in vector for " << docName << ".txt" << std::endl;
    stringVector.clear();
    
    outFS.close();
    
    std::cout << "File written to " << vectorOutputFilename << std::endl;
    
    
    // 3. Create a map from a string (the key) to a string (the value).
    std::map<std::string, std::string> stringMap;
    
    // 4. Generate text from this map.
    // ???
    
    // 5. Generate text from a map that pairs strings (keys) to a vector of strings (values).
    
    
    // 6. Generate text from a map composed of a list of strings as keys and vectors of strings as values.
    
    
    // 7. Explore different texts and methods, and observe when the algorithm produces interesting
    //      things. Have a little fun. Discuss what you did in your Canvas Submission.
    
    return 0;
}
