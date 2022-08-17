#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int getCases();
void splitToStringBySpace(string str, vector<string>* vect);
void splitToIntBySpace(string str, vector<int>* vect);
void splitToChar(string str, vector<string>* vect);
int stringToInt(string str);
int countStrokes(vector<int> vect);

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);

        int squares = stringToInt(line1);
        
        string line2;
        getline(cin, line2);

        vector<int> red;
        vector<int> blue;
        vector<int> yellow;

        vector<string> desiredColours;
        splitToChar(line2, &desiredColours);

        for (string s : desiredColours)
        {
            if (s == "R" || s == "O" || s == "P" || s == "A")
            {
                red.push_back(1);
            }
            else
            {
                red.push_back(0);
            }
            if (s == "P" || s == "G" || s == "A" || s == "B")
            {
                blue.push_back(1);
            }
            else
            {
                blue.push_back(0);
            }
            if (s == "O" || s == "G" || s == "A" || s == "Y")
            {
                yellow.push_back(1);
            }
            else
            {
                yellow.push_back(0);
            }
        }

        int redStrokes = countStrokes(red);
        int blueStrokes = countStrokes(blue);
        int yellowStrokes = countStrokes(yellow);

        cout << "Case #" << (i + 1) << ": " << (redStrokes + blueStrokes + yellowStrokes) << endl;
    }
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

int stringToInt(string str)
{
    stringstream ss;
    int num;
    ss << str;
    ss >> num;
    return num;
}

int countStrokes(vector<int> vect)
{
    int strokes = 0;
    bool bOnAStroke = false;
    for (int value : vect)
    {
        if (value == 1)
        {
            bOnAStroke = true;
        }
        else
        {
            if (bOnAStroke)
            {
                strokes++;
                bOnAStroke = false;
            }
        }
    }
    if (bOnAStroke)
    {
        strokes++;
    }
    return strokes;
}