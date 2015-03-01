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

    int length = 0;
    int vertical = 3;
    int horizontal = 0;

    if (input) {
        int foo = 0;
        while (!input.eof()) {
            input >> foo;
            length++;
        }
    }

    length -= 1;

    if ((length % vertical) == 0) {
        horizontal = length / vertical;
        int **inputNumbersArray = new int*[vertical];
        for (int i = 0; i < vertical; i++) {
            inputNumbersArray[i] = new int[horizontal];
        }

        input.clear();
        input.seekg(0, ios::beg);

        if (input) {
            int w = 0;
            int h = 0;
            while (!input.eof()) {
                input >> inputNumbersArray[w][h];
                w++;
                if (w == vertical) {
                    output << endl;
                    w = 0;
                    h++;
                    if (h == horizontal) break;
                }
            }
        }

        input.close();

        if (loadData) {
            int w = 0;
            int h = 0;
            int counter = 0;
            string s;

            while (!loadData.eof()) {
                loadData >> s;
                counter++;
                if (s == "genre:") {
                    counter = 0;
                    output << s << " ";
                } else if (s == "hero:") {
                    counter = 0;
                    output << s << " ";
                } else if (s == "landscape:") {
                    counter = 0;
                    output << s << " ";
                }

                if (counter == inputNumbersArray[w][h]) {
                    output << s << " ";
                    w++;
                    if (w == vertical) {
                        w = 0;
                        h++;
                        output << endl;
                        loadData.clear();
                        loadData.seekg(0, ios::beg);
                        if (h == horizontal) break;
                    }
                    counter = -1000; // hack :]
                }
            }
        }
    }

    input.close();
    loadData.close();
    output.close();
    return 0;
}
