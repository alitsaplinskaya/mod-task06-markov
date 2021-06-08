#include <time.h>
#include "../include/textgen.h"

Markov::Markov(map<prefix, vector<string>> Generator, int genc)
{
    statelab = Generator;
    NPREF = statelab.begin()->first.size();
    MAXGEN = genc;
}

Markov::Markov(vector<string> word, int prefixc, int genc)
{
    NPREF = prefixc;
    MAXGEN = genc;

    for (int i = 0; i < word.size() - NPREF + 1; i++)
    {
        prefix prfx;
        for (int j = 0; j < NPREF; j++)
            prfx.push_back(word.at(i + j));
        if (i == word.size() - NPREF)
            statelab[prfx].push_back("<Last_Prefix>");
        else
            statelab[prfx].push_back(word.at(i + NPREF));
    }
}

string Markov::TextGenerator()
{
    srand(time(NULL));
    string output;
    deque<string> word;

    auto it = statelab.begin();
    advance(it, rand() % statelab.size());
    for (int i = 0; i < NPREF; i++)
        word.push_back(it->first.at(i));

    while (output.size() < MAXGEN)
    {
        prefix prfx;
        for (int i = 0; i < NPREF; i++)
            prfx.push_back(word.at(i));
        int random = rand() % statelab.find(prfx)->second.size();
        if (statelab.find(prfx)->second.at(random) == "<Last_Prefix>")
        {
            for (int i = 0; i < NPREF; i++)
                output += word.at(i) + ' ';
            break;
        }
        word.push_back(statelab.find(prfx)->second.at(random));

        output += word.at(0) + ' ';
        word.pop_front();
    }

    return output;
}