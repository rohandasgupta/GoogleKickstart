#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int getCases();
void splitToStringBySpace(string str, vector<string>* vect);
void splitToIntBySpace(string str, vector<int>* vect);
void splitToChar(string str, vector<string>* vect);
int letterToValue(string str);

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);

        //vector<string> line1arrstr;
        //vector<int> line1arrint;

        vector<string> l1arrstr;
        splitToChar(line1, &l1arrstr);
        vector<int> line1val;
        for (string x : l1arrstr)
        {
            line1val.push_back(letterToValue(x));
        }

        string line2;
        getline(cin, line2);

        vector<string> l2arrstr;
        splitToChar(line2, &l2arrstr);
        vector<int> line2val;
        for (string x : l2arrstr)
        {
            line2val.push_back(letterToValue(x));
        }

        int x = 0;
        int totalOperations = 0;
        
        while (x < line1val.size())
        {
            int min = 15;
            vector<int> alldifs;
            for (int value : line2val)
            {
                alldifs.push_back(line1val[x] - value);
                alldifs.push_back(value - line1val[x]);
            }
            for (int diff : alldifs)
            {
                if (diff > 13) {
                    diff = 26 - diff;
                }
                if (diff >= 0 && diff<min) {
                    min = diff;
                }
            }
            totalOperations += min;

            x++;
        }
        cout << "Case #" << (i + 1) << ": " << totalOperations << endl;
    }
    return 0;
}

int getCases()
{
    string txtCases;
    getline(cin, txtCases);
    stringstream ss;
    ss << txtCases;
    int cases;
    ss >> cases;
    return cases;
}


void splitToStringBySpace(string str, vector<string>* vect)
{
    string word = "";

    for (auto c : str) {
        if (c == ' ')
        {
            vect->push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    vect->push_back(word);
}

void splitToIntBySpace(string str, vector<int>* vect)
{
    string numstr = "";
    stringstream ss;
    int number = 0;

    for (char c : str) {
        if (c == ' ')
        {
            ss << numstr;
            ss >> number;
            vect->push_back(number);
            numstr = "";
            ss.clear();
        }
        else
        {
            numstr += c;
        }
    }
    ss << numstr;
    ss >> number;
    vect->push_back(number);
}

void splitToChar(string str, vector<string>* vect)
{
    string wibblywobbly;
    stringstream ss;
    for (char c : str)
    {
        ss << c;
        ss >> wibblywobbly;
        vect->push_back(wibblywobbly);
        ss.clear();
    }
}

int letterToValue(string str)
{
    if (str == "a") { return 1; }
    if (str == "b") { return 2; }
    if (str == "c") { return 3; }
    if (str == "d") { return 4; }
    if (str == "e") { return 5; }
    if (str == "f") { return 6; }
    if (str == "g") { return 7; }
    if (str == "h") { return 8; }
    if (str == "i") { return 9; }
    if (str == "j") { return 10; }
    if (str == "k") { return 11; }
    if (str == "l") { return 12; }
    if (str == "m") { return 13; }
    if (str == "n") { return 14; }
    if (str == "o") { return 15; }
    if (str == "p") { return 16; }
    if (str == "q") { return 17; }
    if (str == "r") { return 18; }
    if (str == "s") { return 19; }
    if (str == "t") { return 20; }
    if (str == "u") { return 21; }
    if (str == "v") { return 22; }
    if (str == "w") { return 23; }
    if (str == "x") { return 24; }
    if (str == "y") { return 25; }
    if (str == "z") { return 26; }
}