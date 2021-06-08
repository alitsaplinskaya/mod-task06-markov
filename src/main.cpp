#include "../include/textgen.h"
#include <fstream>
#include <iostream>

int main()
{
    ifstream fin;
    fin.open("input.txt");
    vector<string> words;
    string word;
    while (!fin.eof())
    {
        fin >> word;
        words.push_back(word);
    }
    fin.close();

    Markov Generator(words, 2, 1000);
    string line = Generator.TextGenerator();

    ofstream fout;
    fout.open("output.txt");
    fout.clear();
    fout << line;
    fout.close();

    return 1;
}
