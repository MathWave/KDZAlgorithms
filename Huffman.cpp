#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef map<char, string> dictionary;

struct node {
    char key;
    node* left = nullptr;
    node* right = nullptr;
    int count = 0;
    node(char k, int c) {
        key = k;
        count = c;
    }
    ~node() {
        if (left) {
            delete left;
        }
        if (right) {
            delete right;
        }
    }
};

bool nodeComparer(node* node1, node* node2) {
    return node1->count > node2->count;
}

int getAllBytesFromFile(const string& filename, char*& out) {
    ifstream ifs(filename, ios::binary|ios::ate);
    ifstream::pos_type pos = ifs.tellg();
    int length = pos;
    out = new char[length];
    ifs.seekg(0, ios::beg);
    ifs.read(out, length);
    ifs.close();
    return length;
}

node* buildTree(vector<node*> nodeSet) {
    while (nodeSet.size() != 1) {
        node* a = nodeSet.back();
        nodeSet.pop_back();
        node* b = nodeSet.back();
        nodeSet.pop_back();
        node* newNode = new node('\0', a->count + b->count);
        newNode->left = a;
        newNode->right = b;
        nodeSet.push_back(newNode);
        for (unsigned long i = nodeSet.size() - 1; i != 0 && nodeSet[i]->count > nodeSet[i - 1]->count; i--) {
            swap(nodeSet[i], nodeSet[i - 1]);
        }
    }
    return nodeSet[0];
}

void makeCode(dictionary& codes, node* tree, const string& code) {
    if (tree->left) {
        makeCode(codes, tree->left, code + '0');
    }
    if (tree->right) {
        makeCode(codes, tree->right, code + '1');
    }
    if (!tree->right && !tree->left) {
        codes[tree->key] = code;
    }
}

string makeBinaryString(char* input, int length, dictionary dict) {
    string binary;
    for (int i = 0; i < length; i++) {
        binary += dict[input[i]];
    }
    return binary;
}

char createChar(const string& bins) {
    char res = 0;
    int c = 1;
    for (int i = 7; i >= 0; i--) {
        res += (bins[i] == '1' ? c : 0);
        c *= 2;
    }
    return res;
}

vector<char> makeCharArray(string binaryString) {
    vector<char> res;
    for (unsigned long i = 0; i < binaryString.size(); i += 8) {
        string code;
        for (int j = 0; j < 8; j++) {
            code += binaryString[i + j];
        }
        res.push_back(createChar(code));
    }
    return res;
}

string fromCharToBinaryString(char c) {
    string code;
    for (int i = 7; i >= 0; --i) {
        code.push_back(((c & (1 << i))? '1' : '0'));
    }
    return code;
}

string translate(map<string, char> dict, string code) {
    string s;
    string buffer;
    for (int i = 0; i < code.size(); i++) {
        buffer += code[i];
        if (dict.find(buffer) != dict.end()) {
            s += dict[buffer];
            buffer = "";
        }
    }
    return s;
}

void decode(char* code, int length, map<string, char>& dict, string& text) {
    int i = 0;
    int count = 0;
    for (i = 0; code[i] != '\n'; i++)
        count = count * 10 + code[i] - 48;
    i++;
    for (int j = 0; j < count; j++) {
        char c = code[i];
        i += 2;
        string s;
        while (code[i] != '\n')
            s += code[i++];
        dict[s] = c;
        i++;
    }
    int n = code[i] - 48;
    i += 2;
    while (i != length) {
        text += fromCharToBinaryString(code[i++]);
    }
    for (int j = 0; j < n; j++) {
        text.pop_back();
    }
}

void huffmanCompress(const string& pathFrom, const string& pathTo) {
    char* out = nullptr;
    int length = getAllBytesFromFile(pathFrom, out);
    map<char, int> dict;
    for (int i = 0; i < length; i++) {
        if (dict.find(out[i]) == dict.end())
            dict[out[i]] = 1;
        else
            dict[out[i]]++;
    }
    vector<node*> v;
    v.reserve(dict.size());
    for (auto nodePair : dict) {
        v.push_back(new node(nodePair.first, nodePair.second));
    }
    sort(v.begin(), v.end(), nodeComparer);
    node* tree = buildTree(v);
    dictionary codes;
    makeCode(codes, tree, "");
    delete tree;
    ofstream fout(pathTo);
    fout << codes.size() << endl;
    for (const auto& code : codes) {
        fout << code.first << endl << code.second << endl;
    }
    string binaryString = makeBinaryString(out, length, codes);
    int last = (8 - (binaryString.size() % 8)) % 8;
    fout << last << endl;
    for (int i = 0; i < last;  i++) {
        binaryString.push_back('0');
    }
    vector<char> chars = makeCharArray(binaryString);
    for (char c : chars) {
        fout << c;
    }
    fout.close();
}

void huffmanDecompress(const string& fileFrom, const string& fileTo) {
    char* fileText;
    int length = getAllBytesFromFile(fileFrom, fileText);
    string s;
    map<string, char> dict;
    decode(fileText, length, dict, s);
    string text = translate(dict, s);
    ofstream fout(fileTo);
    fout << text;
    fout.close();
}
