

 //                                            ********* Writer: Matt Hamilton    *********
 //                                             ******** Class: CS 136            ******** 
 //                                              ******* Professor: Brian Dauzat  *******
 //                                                ***** Programming Exercise 8-7 *****
 //                                                 **** ======================== ****
 //                                                   **  *** *** *** *** *** *** **
/* Write a program that allows the user to enter the last names of five candidates in a local election and the number of votes received by each candidate. 
   The program should then output each candidate's name, the number of votes received, and the percentage of the total votes received by he candidate. 
   Your program should also output the winner of the election. */

#include <iostream>
#include <array> // import the library to be able to work with arrays;
#include <string> // import the library to be able to work with strings;
#include <iomanip> // import the library to manipulate the output;

using namespace std;

int get_total(unsigned int vot_arr[]);
void show_results(string names[], unsigned int vots[], double percents[]);
int get_winer_index(unsigned int votes[]);


int main() {

// I think I could also use multidimensional arrays to solve the problem if all the data were the same type, however, since it's not, I have decided to use parallel arrays to solve the problem.
 int numOfCandidates = 5; // the variable holds the number of candidates
 string last_names [5] = {}; // the array stores the fives names 
 unsigned int votes[5] = {}; // the array stores the fives votes recieved 
 double percentage[5] = {};  // the array stores the corresponding percentages of votes for each candidate


// the loop below prompts the user to enter data for each candidate

 for(int index = {0}; index <= numOfCandidates - 1; ++index){

   cout << "-------------------------"  << endl;
   cout << "Candidate #" << index + 1 << endl;
   cout << "Last name: ";
   cin >> last_names[index]; //store the last name 
   cout << "Votes: ";
   cin >> votes[index]; //store the votes
   
 }


unsigned int total_votes = get_total(votes); // here we ask function get_total to return the total number of votes 

// after we get the total, we can calculate the percentage of votes for each candidate
//I could implement it as a separate function but the calculation is too simple

for(int i {0}; i <= numOfCandidates - 1; ++i){
  percentage[i] = (votes[i] * 100.0)/total_votes; //store the percentage to percentage array that is a parallel array 
}


// below we pass all the data to the show_results function and it displays all we need
show_results(last_names, votes, percentage); 


 system("pause");
  return 0;
}



//--------- Functions Implementation -------

int get_winer_index(unsigned int votes[]){
//the function uses a simple algorithm to find the biggest number of votes and returns the biggest value's index 
// since the number of candidates is the same, I have decided not to pass to the function the number of candidates because it knows it 

unsigned int winner = votes[0];
int winner_index = 0;

for(unsigned int i {1}; i <= 4; ++i){
  if(votes[i] > winner){
   winner = votes[i];
   winner_index = i;
  };
}

return winner_index; //return winner's index
}



int get_total(unsigned int votes_arr[5]){
  //the function calculates the total number of votes and returns it 

int total = 0;

for(int i {0}; i <= 4; i++){
   total+=votes_arr[i];
}
return total;
}



void show_results(string names[], unsigned int votes[], double percents[]){

  // the function receives all the data and displays the results

  cout << "-----------------------------------------------------------------" << endl;
  cout << setw(20) << left << "Candidates" 
  << setw(20) << left << "Votes Received" 
  <<  setw(5) << "% of Total Votes" << endl << endl; 

  for(unsigned int i {0}; i <= 4; ++i){
    cout << setw(25) << left << names[i]  
    << setw(17) << left << votes[i]  
    << setw(7) << fixed << setprecision(2) << percents[i] <<  endl;

  
  }
 cout << setw(25) << left << "Total " << setw(25) << left << get_total(votes)<< endl;
 cout << "-----------------------------------------------------------------" << endl;
 cout << "The Winner of the Election is " << names[get_winer_index(votes)]   << endl;
 cout << "-----------------------------------------------------------------" << endl;
  
}