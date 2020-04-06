#include <fstream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

class LZ77Packer {

    struct node
    {
        int position;
        int length;
        char letter;
    };

    int TO_RIGHT;
    int TO_LEFT;
    string fileFrom;
    string fileTo;
    char* fileBytes;
    int size;

    void readFile() {
        ifstream ifs(fileFrom, ios::binary|ios::ate);
        ifstream::pos_type pos = ifs.tellg();
        size = pos;
        size++;
        fileBytes = new char[size];
        ifs.seekg(0, ios::beg);
        ifs.read(fileBytes, size - 1);
        ifs.close();
        if (fileBytes[size - 2] == '\0')
            fileBytes[size - 1] = '\n';
        else
            fileBytes[size - 1] = '\0';
    }

    node findMatch(int pointer)
    {
        queue<node> q;
        for (int i = 1; i <= min(pointer, TO_LEFT); i++)
            if (fileBytes[pointer - i] == fileBytes[pointer])
                q.push({i, 1, fileBytes[pointer + 1]});
        if (q.empty())
            return {0, 0, fileBytes[pointer]};
        node f = q.front();
        while (q.size() != 1)
        {
            q.pop();
            if (fileBytes[pointer - f.position + f.length] == fileBytes[pointer + f.length])
                q.push({f.position, f.length + 1, fileBytes[pointer + f.length + 1]});
            f = q.front();
        }
        while (pointer + f.length < size && fileBytes[pointer - f.position + f.length] == fileBytes[pointer + f.length])
        {
            if (f.length == TO_RIGHT)
                break;
            f.length++;
            f.letter = fileBytes[pointer + f.length];
        }
        return f;
    }

public:

    LZ77Packer(string fileFrom, string fileTo, int preHistorySize, int slideSize) {
        this->TO_LEFT = preHistorySize;
        this->TO_RIGHT = slideSize;
        this->fileFrom = fileFrom;
        this->fileTo = fileTo;
        readFile();
    }

    void pack() {
        ofstream fout(fileTo);
        vector<node> v;
        int pointer = 0;
        node n;
        while (pointer != size)
        {
            n = findMatch(pointer);
            pointer += n.length + 1;
            v.push_back(n);
        }

        fout << v.size() << endl;
        for (auto & i : v)
            fout << i.position << " " << i.length << " " << i.letter << " ";
        fout.close();
    }

};

