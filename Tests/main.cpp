#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {

    ofstream resultFile;
    resultFile.open("results.txt",std::ios::app);

    ifstream logFile;

    logFile.open("./tests/SCHED_FIFO_1.txt");

    if (logFile.is_open())
    {
        string line;
        long long lineNumber = 0;
        long long number;
        long long sum;
        long long arithmeticMean;
        while ( getline (logFile,line) )
        {
            if(lineNumber == 0){
                lineNumber++;
                arithmeticMean = stoll(line);
            }
            else{
                lineNumber++;
                number = stoll(line);
                arithmeticMean = arithmeticMean / lineNumber;
                arithmeticMean = (arithmeticMean * (lineNumber - 1) + number / lineNumber);
            }
        }
        cout << lineNumber << " " << arithmeticMean;
        resultFile << "Schedule method: " << "SCHED_RR " << "priority: " << "99" << "\n";
        resultFile << "Average delay time " << arithmeticMean << "\n\n";
        logFile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
