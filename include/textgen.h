#include <string>
#include <vector>
#include <deque>
#include <map>


using namespace std;

class Markov
{
private:
    typedef deque<string> prefix;
    map<prefix, vector<string>> statelab;
    int NPREF = 2;
    int MAXGEN = 1000;

public:
    Markov(vector<string> allwords, int prefixc, int genc);
    Markov(map<prefix, vector<string>> Generator, int genc);
    string TextGenerator();
};
