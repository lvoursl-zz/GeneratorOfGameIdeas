#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char const *argv[]) {
    ifstream loadData;
    ifstream input;
    ofstream output;
    loadData.open("data.txt", ios::in);
    input.open("input.txt", ios::in);
    output.open("output.txt", ios::out);

    int inputNumbersArray[2];
    int counter = 0;
    string s;

    if (input) {
        int i = 0;
        while (!input.eof()) {
            input >> inputNumbersArray[i];
            i++;
        }
    }

    if (loadData) {
        int num = 0;
        while (!loadData.eof()) {
            loadData >> s;
            counter++;
            if (s == "genre:") {
                counter = 0;
            } else if (s == "hero:") {
                counter = 0;
            }

            if (counter == inputNumbersArray[num]) {
                output << s;
                num++;
                if (num > 1) {
                    break;
                }
            }
        }
    }

    loadData.close();
    input.close();
    output.close();
    return 0;
}
