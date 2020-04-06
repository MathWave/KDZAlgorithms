#include "Huffman.cpp"
#include "LZ77Packer.cpp"
#include "LZ77Unpacker.cpp"
#include <filesystem>
#include <chrono>
#include <string>
using namespace std;

string* defaultFiles = new string[10]{ "1.txt", "2.docx", "3.pptx", "4.pdf", "5.dll", "6.jpg", "7.jpg", "8.bmp", "9.bmp", "10.mov" };

int main() {
    string dir = "DATA/";
    map<int, map<string, vector<chrono::milliseconds>>> times;
    for (int file = 1; file <= 10; file++) {
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            huffmanCompress(dir + defaultFiles[file], dir + to_string(file) + ".haff");
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["haff"].push_back(elapsed_ms);
        }
        cout << "haffman ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["haff"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Packer(dir + defaultFiles[file], dir + to_string(file) + ".lz775", 4 * 1024, 5 * 1024).pack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["lz775"].push_back(elapsed_ms);
        }
        cout << "lz775 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["lz775"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Packer(dir + defaultFiles[file], dir + to_string(file) + ".lz7710", 8 * 1024, 10 * 1024).pack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["lz7710"].push_back(elapsed_ms);
        }
        cout << "lz7710 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["lz7710"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Packer(dir + defaultFiles[file], dir + to_string(file) + ".lz7720", 16 * 1024, 20 * 1024).pack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["lz7720"].push_back(elapsed_ms);
        }
        cout << "lz7720 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["lz7720"]) {
            cout << k.count() << endl;
        }

        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            huffmanDecompress(dir + to_string(file) + ".haff", dir + to_string(file) + ".unhaff");
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["unhaff"].push_back(elapsed_ms);
        }
        cout << "unhaffman ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["unhaff"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Unpacker(dir + to_string(file) + ".lz775", dir + to_string(file) + ".unlz775").unpack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["unlz775"].push_back(elapsed_ms);
        }
        cout << "unlz775 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["unlz775"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Unpacker(dir + to_string(file) + ".lz7710", dir + to_string(file) + ".unlz7710").unpack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["unlz7710"].push_back(elapsed_ms);
        }
        cout << "unlz7710 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["unlz7710"]) {
            cout << k.count() << endl;
        }
        for (int i = 0; i < 10; i++) {
            auto begin = std::chrono::steady_clock::now();
            LZ77Unpacker(dir + to_string(file) + ".lz7720", dir + to_string(file) + ".unlz7720").unpack();
            auto end = std::chrono::steady_clock::now();
            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
            times[file]["unlz7720"].push_back(elapsed_ms);
        }
        cout << "unlz7720 ready for file " << file << endl;
        for (chrono::milliseconds k : times[file]["unlz7720"]) {
            cout << k.count() << endl;
        }
        cout << file << ": " << endl;
        for (auto t : times[file]) {
            cout << t.first << ": " << endl;
            for (chrono::milliseconds k : t.second) {
                cout << k.count() << endl;
            }
        }
    }
    for (auto p : times) {
        cout << p.first << ": " << endl;
        for (auto t : p.second) {
            cout << t.first << ": " << endl;
            for (chrono::milliseconds k : t.second) {
                cout << k.count() << endl;
            }
        }
    }
}