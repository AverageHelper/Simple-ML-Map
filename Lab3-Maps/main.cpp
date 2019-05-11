#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

int main() {
    std::string doc1Name = "1Nephi.txt";
    std::string doc2Name = "Nephi_Trump.txt";
    std::string doc3Name = "Trump.txt";
    
    std::vector<std::string> inputFiles = {doc1Name, doc2Name, doc3Name};
    
    // 1. Read the document into a set of strings and print them to a file.
    for (unsigned int i = 0; i < inputFiles.size(); i++) {
        std::string outputFileName = "SetOutput.txt";
        std::string docName = inputFiles.at(i);
        
        // Open an input file
        std::ifstream inFS;
        inFS.open(docName);
        
        if (!inFS.is_open()) {
            std::cout << "Couldn't open " << docName << " for reading." << std::endl;
            return 1;
        }
        
        // Read into string set
        std::set<std::string> stringSet;
        
        while (!inFS.eof()) {
            std::string newString = "";
            inFS >> newString;
            stringSet.insert(newString);
        }
        
        inFS.close();
        
        // Output to file
        std::ofstream outFS;
        outFS.open(outputFileName);
        
        if (!outFS.is_open()) {
            std::cout << "Couldn't open " << outputFileName << " for writing." << std::endl;
        }
        
        for (std::set<std::string>::iterator it = stringSet.begin(); it != stringSet.end(); it++) {
//            outFS << *it;
//            std::cout << *it << std::endl;
        }
        std::cout << std::endl << stringSet.size() << " elements in set for '" << docName << "'." << std::endl;
        stringSet.clear();
        
        outFS.close();
        
        std::cout << "File written to " << outputFileName << std::endl;
    }
    
    // 2. Read the document into a vector of strings and print them to a file.
    for (unsigned int i = 0; i < inputFiles.size(); i++) {
        std::string outputFileName = "VectorOutput.txt";
        std::string docName = inputFiles.at(i);
        
        // Open an input file
        std::ifstream inFS;
        inFS.open(docName);
        
        if (!inFS.is_open()) {
            std::cout << "Couldn't open " << docName << " for reading." << std::endl;
            return 1;
        }
        
        // Read into string set
        std::vector<std::string> stringVector;
        
        while (!inFS.eof()) {
            std::string newString = "";
            inFS >> newString;
            stringVector.push_back(newString);
        }
        
        inFS.close();
        
        // Output to file
        std::ofstream outFS;
        outFS.open(outputFileName);
        
        if (!outFS.is_open()) {
            std::cout << "Couldn't open " << outputFileName << " for writing." << std::endl;
        }
        
        for (std::vector<std::string>::iterator it = stringVector.begin(); it != stringVector.end(); it++) {
//            outFS << *it;
//            std::cout << *it << std::endl;
        }
        std::cout << std::endl << stringVector.size() << " elements in vector for '" << docName << "'." << std::endl;
        stringVector.clear();
        
        outFS.close();
        
        std::cout << "File written to " << outputFileName << std::endl;
    }
    
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
