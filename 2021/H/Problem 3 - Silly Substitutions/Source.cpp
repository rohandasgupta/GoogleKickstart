#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int getCases();
void splitToStringBySpace(string str, vector<string>* vect);
void splitToIntBySpace(string str, vector<int>* vect);
void splitToChar(string str, vector<string>* vect);
int stringToInt(string str);
void splitToInt(string str, vector<int>* vect);

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);

        int seqLen = stringToInt(line1);

        string line2;
        getline(cin, line2);

        vector<int> oldSequence;
        splitToInt(line2, &oldSequence);
        vector<int> refSequence;
        vector<int> finalSequence;
        bool bChecked = false;

        for (int current = 1; current < 10; current++)
        {
            for (int x = 0; x < oldSequence.size(); x++)
            {
                if (x == 0)
                {
                    ;
                }
                else {
                    if (x == oldSequence.size() - 1)
                    {
                        if (oldSequence[x] - oldSequence[x - 1] == 1)
                        {
                            oldSequence.erase(oldSequence.begin() + x);
                            oldSequence.erase(oldSequence.begin() + x - 1);
                            oldSequence.insert(current+1, oldSequence.begin() + x - 1);
                            x = 0;
                        }

                    }
                    else
                    {
                        if (oldSequence[x] - oldSequence[x - 1] == 1)
                        {
                            oldSequence
                        }
                    }
                }
            }
            if (current == 9 && !bChecked)
            {
                refSequence = oldSequence;
                current = 8;
                bChecked = true;
            }
            else if (bChecked)
            {
                if (refSequence == oldSequence)
                {
                    finalSequence == oldSequence;
                    break;
                }
            }
        }

        string answer = "";

        for (int val : finalSequence)
        {
            answer += val;
        }

        cout << "Case #" << (i + 1) << ": " << answer << endl;
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

void splitToInt(string str, vector<int>* vect)
{
    int wibblywobbly;
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