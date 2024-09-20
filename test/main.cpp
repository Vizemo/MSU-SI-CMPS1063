#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int SIZE = 100;

typedef float f;

// Struct to store athlete information, including scores for each event and the
// total score.
struct Athlete {
  int jNum;     // Contestant's number
  f diving;     // Score for Diving
  f gymnastics; // Score for Gymnastics
  f boxing;     // Score for Boxing
  f skating;    // Score for Skating
  f posing;     // Score for Power Posing
  f totalScore; // Total score (sum of all event scores)
};

// Purpose:  Required code to open and close files
void openFiles(ifstream &infile, ofstream &outfile);

void heading(ofstream &fout);

void calculateTotalScore(Athlete &athlete);

void getContestants(ifstream &fin, Athlete athletes[], int &count);

void findContestantOfTheYear(ofstream &fout, const Athlete athletes[],
                             int count);

void displayAllContestants(ofstream &fout, const Athlete athletes[], int count);

int main() {
  ifstream fin;
  ofstream fout;
  Athlete athletes[SIZE]; // Array to store data for up to 100 athletes
  int count;              // Variable to store the total number of athletes

  openFiles(fin, fout);

  heading(fout);

  // Get data for all athletes from the input file and store it in the array
  getContestants(fin, athletes, count);

  // Display the scores and total points for each athlete
  displayAllContestants(fout, athletes, count);

  // Close the input and output files
  fin.close();
  fout.close();

  return 0; // Return successful execution status
}

void openFiles(ifstream &infile, ofstream &outfile) {
  // char inFileName[40];
  // char outFileName[40];

  cout << "Enter the input file name: ";
  // cin >> inFileName;
  infile.open("in.txt"); // Open input file

  cout << "Enter the output file name: ";
  // cin >> outFileName;
  outfile.open("out.txt"); // Open output file
} // End of openFiles function

void heading(ofstream &fout) {
  fout << "Victor Marchesi" << endl;
  fout << "CMPS 1063 SI" << endl << endl;
}

void calculateTotalScore(Athlete &athlete) {
  athlete.totalScore = athlete.diving + athlete.gymnastics + athlete.boxing +
                       athlete.skating + athlete.posing;
}

void getContestants(ifstream &fin, Athlete athletes[], int &count) {
  int jNumFunction; // To store contestant number
  char eventType;   // To store event type (D, G, B, S, P)
  float score;      // To store the score for each event

  count = 0; // Initialize the count of athletes to 0

  // Loop through the input file until we reach the sentinel value (-1).
  while (fin >> jNumFunction && jNumFunction != -1) {
    // Set the contestant number for the current athlete
    athletes[count].jNum = jNumFunction;

    // Initialize all event scores to 0 for the current athlete
    athletes[count].diving = athletes[count].gymnastics =
        athletes[count].boxing = athletes[count].skating =
            athletes[count].posing = 0;

    // Loop to read the next 5 lines for event and score pairs.
    for (int i = 0; i < 5; ++i) {
      // Read event type (D, G, B, S, P) and the corresponding score
      fin >> eventType >> score;

      // Use a switch statement to assign the score to the correct event based
      // on the event type.
      switch (eventType) {
      case 'D':
        athletes[count].diving = score; // Assign the score to diving
        break;
      case 'G':
        athletes[count].gymnastics = score; // Assign the score to gymnastics
        break;
      case 'B':
        athletes[count].boxing = score; // Assign the score to boxing
        break;
      case 'S':
        athletes[count].skating = score; // Assign the score to skating
        break;
      case 'P':
        athletes[count].posing = score; // Assign the score to power posing
        break;
      }
    }
    // After reading all 5 event scores, calculate the total score for the
    // current athlete
    calculateTotalScore(athletes[count]);

    count++; // Move to the next athlete in the array
  }
}

void findContestantOfTheYear(ofstream &fout, const Athlete athletes[],
                             int count) {
  Athlete winner = athletes[0]; // Initialize the winner as the first athlete

  // Loop through the remaining athletes and find the one with the highest total
  // score.
  for (int i = 1; i < count; ++i) {
    if (athletes[i].totalScore > winner.totalScore) {
      winner = athletes[i];
      // Update the winner if a higher total score is found
    }
  }

  // Display the winner (athlete with the highest total score)
  fout << "ATHLETE OF THE YEAR: Contestant " << winner.jNum << " with TOTAL of "
       << winner.totalScore << endl;
}

void displayAllContestants(ofstream &fout, const Athlete athletes[],
                           int count) {
  // Loop through each athlete and print their scores for all events along with
  // their total score.
  for (int i = 0; i < count; ++i) {
    fout << "Contestant: " << athletes[i].jNum << endl;
    fout << "  Diving:" << setw(8) << fixed << setprecision(1)
         << athletes[i].diving << endl;
    fout << "  Gymnastics:" << setw(4) << fixed << setprecision(1)
         << athletes[i].gymnastics << endl;
    fout << "  Boxing:" << setw(8) << fixed << setprecision(1)
         << athletes[i].boxing << endl;
    fout << "  Skating:" << setw(7) << fixed << setprecision(1)
         << athletes[i].skating << endl;
    fout << "  Posing:" << setw(8) << fixed << setprecision(1)
         << athletes[i].posing << endl;
    fout << setw(50) << "TOTAL: " << fixed << setprecision(1)
         << athletes[i].totalScore << endl
         << endl;
  }

  // Find the athlete with the highest total score
  findContestantOfTheYear(fout, athletes, count);
}