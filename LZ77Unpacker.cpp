#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class LZ77Unpacker {

    struct node
    {
        int position;
        int length;
        char letter;
    };

    int TO_LEFT;
    int TO_RIGHT;
    string fileFrom;
    string fileTo;
    vector<node> nodes;

    void readFile() {
        ifstream ifs(fileFrom, ios::binary|ios::ate);
        ifstream::pos_type pos = ifs.tellg();
        int size = pos;
        char* fileBytes = new char[size];
        ifs.seekg(0, ios::beg);
        ifs.read(fileBytes, size);
        ifs.close();
        int n = 0;
        int i = 0;
        while (fileBytes[i] != '\n') {
            n = n * 10 + fileBytes[i] - 48;
            i++;
        }
        i++;
        while (i != size) {
            int position = 0, length = 0;
            char letter;
            while (fileBytes[i] != ' ') {
                position = position * 10 + fileBytes[i] - 48;
                i++;
            }
            i++;
            while (fileBytes[i] != ' ') {
                length = length * 10 + fileBytes[i] - 48;
                i++;
            }
            i++;
            letter = fileBytes[i];
            nodes.push_back({position, length, letter});
            i += 2;
        }
    }


public:

    LZ77Unpacker(string fileFrom, string fileTo) {
        this->fileFrom = fileFrom;
        this->fileTo = fileTo;
        readFile();
    }

    void unpack() {
        string output;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].position != 0)
            {
                int position = output.length() - nodes[i].position;
                for (int j = 0; j < nodes[i].length; j++)
                    output += output[position + j];
            }
            output += nodes[i].letter;
            cout << "made " << i << " out of " << nodes.size() << endl;
        }
        ofstream fout(fileTo);
        for (int i = 0; i < output.size() - 1; i++)
            fout << output[i];
        fout.close();
    }

};