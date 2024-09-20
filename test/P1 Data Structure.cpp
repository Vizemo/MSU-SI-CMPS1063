#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
typedef struct Athlete {
    int contestantNumber;
    double diving;
    double gymnastics;
    double skating;
    double boxing;
    double posing;
    double totalScore;
};void GetContestants(Athlete contestants[], int &numContestants);
void DisplayAllContestants(Athlete contestants[], int numContestants);
Athlete FindWinner(Athlete contestants[], int numContestants);
void PrintWinner(Athlete winner);int main() {
    const int Contestant = 25;
    Athlete contestants[Contestant];
    int numContestants = 0;    GetContestants(contestants, numContestants);
    DisplayAllContestants(contestants, numContestants);
    Athlete winner = FindWinner(contestants, numContestants);
    PrintWinner(winner);    return 0;
}void GetContestants(Athlete contestants[], int &numContestants) {
    ifstream inputFile("CS1prog1.txt");
    if (!inputFile) {
        cout << "Error opening input file." << endl;
        return;
    }    int contestantNumber;
    while (inputFile >> contestantNumber) {
        if (contestantNumber == -1) {
            break;
        }
        contestants[numContestants].contestantNumber = contestantNumber;        string sports;
        double score;
        for (int i = 0; i < 5; i++) {
            inputFile >> sports >> score;
            switch (sports[0]) {
                case 'D':
                    contestants[numContestants].diving = score;
                    break;
                case 'G':
                    contestants[numContestants].gymnastics = score;
                    break;
                case 'S':
                    contestants[numContestants].skating = score;
                    break;
                case 'B':
                    contestants[numContestants].boxing = score;
                    break;
                case 'P':
                    contestants[numContestants].posing = score;
                    break;
                default:
                    cerr << "Invalid sports type: " << sports << endl;
                    break;
            }
        }
        contestants[numContestants].totalScore = contestants[numContestants].diving + contestants[numContestants].gymnastics +
            contestants[numContestants].skating + contestants[numContestants].boxing + contestants[numContestants].posing;
        numContestants++;
    }}void DisplayContestant(Athlete contestant) {
    cout << "Contestant: " << contestant.contestantNumber << endl;
    cout << "Diving: " << fixed << setprecision(1) << contestant.diving << endl;
    cout << "Gymnastics: " << fixed << setprecision(1) << contestant.gymnastics << endl;
    cout << "Skating: " << fixed << setprecision(1) << contestant.skating << endl;
    cout << "Boxing: " << fixed << setprecision(1) << contestant.boxing << endl;
    cout << "Posing: " << fixed << setprecision(1) << contestant.posing << endl;
    cout << "TOTAL: " << fixed << setprecision(2) << contestant.totalScore << endl;
    cout << endl;
}void DisplayAllContestants(Athlete contestants[], int numContestants) {
    cout << "Contestant Information:" << endl;
    for (int i = 0; i < numContestants; i++) {
        DisplayContestant(contestants[i]);
    }
}Athlete FindWinner(Athlete contestants[], int numContestants) {
    Athlete winner = contestants[0];
    for (int i = 1; i < numContestants; i++) {
        if (contestants[i].totalScore > winner.totalScore) {
            winner = contestants[i];
        }
    }
    return winner;
}void PrintWinner(Athlete winner) {
    cout << "ATHLETE OF THE YEAR: Contestant " << winner.contestantNumber << " with TOTAL of " << fixed << setprecision(2) << winner.totalScore << endl;
}