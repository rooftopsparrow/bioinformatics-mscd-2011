#ifndef _SCORING_H
#define _SCORING_H

#include <string>
using namespace std;

class Scoring
{
    private:
        int scoreMatrix [4][4];
        int GetMatrixValue(char ACGT);
    public:
        Scoring();
        int Score (string a, string b);
};

#endif /* _SCORING_H */
