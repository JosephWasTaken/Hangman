#include <iostream>
using std::cout, std::cin;

std::string generateWord(int size, std::string words[]);

int main(){
  std::string words[] = {"HAMBURG", "CASTLE", "TABLE", "SCARED", "COUPLE", "DINOSAUR", "KITCHEN", "PHONE"};
  std::string guess;
  int size = sizeof(words)/sizeof(words[0]);

  cout << "******  HANGMAN  ******\n";
  std::string word = generateWord(size, words);

  char indexes[word.length()];
  int lettersGuessed = 0;

while (lettersGuessed != word.length()){
  cout << "Enter a CAPITAL letter to guess the word: ";
  cin >> guess;

  if (guess.length() == 1 && !guess.empty()){
   int position = word.find(guess);

  for (int i=0; i< word.length(); i++){
    if (indexes[i] == word[i]){
      cout << word[i];
    } else if (i == position){
      cout << word[i];
      indexes[i] = word[i];
      lettersGuessed++;
    } else{
      cout << "_";
    }
  }

  cout << "\n";
  }
}
  
  cout << "You won! \n";
  cout << "***********************\n";

  return 0;
}

std::string generateWord(int size, std::string words[]){
  srand(time(NULL));
  int number = (rand() % size) + 1;
  std::string word = words[number];

  for (int i=0; i< word.length(); i++){
    cout << "_ ";
  }
  cout << "\n";

  return word;
}