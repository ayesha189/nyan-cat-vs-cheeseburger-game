#ifndef SCORE_H
#define SCORE_H

#include <string>
using namespace std;

class Score {
public:
    string playerName;
    int score = 0;
    string mode;
    void bubbleSort(Score scores[], int n);
};
#endif