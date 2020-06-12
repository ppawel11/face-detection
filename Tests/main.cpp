#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {

    ofstream resultFile;
    resultFile.open("results.txt",std::ios::app);

    ifstream logFile;

    logFile.open("./tests/SCHED_FIFO_99.txt");

    if (logFile.is_open())
    {
        string line;
        long long lineNumber = 0;

        bool isFirstLine = true;
        long long prevLine;
        long long nextLine;
        long long sum;

        while ( getline (logFile,line) )
        {

            if(isFirstLine){
                nextLine = stoll(line);
                isFirstLine = false;
            }
            else{
                prevLine = nextLine;
                nextLine = stoll(line);

                sum += nextLine - prevLine;
                cout << nextLine - prevLine << "\n";
            }

            lineNumber++;
        }
        cout << lineNumber << " " << sum;
        resultFile << "Schedule method: " << "SCHED_FIFO " << "priority: " << "99" << "\n";
        resultFile << "Average delay time " << sum/lineNumber << "\n\n";
        logFile.close();
    }

    else cout << "Unable to open file";

    return 0;
}
