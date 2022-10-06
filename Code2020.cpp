#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;
int letterFill (char, string, string&);

int main ()
{
    string name;
    char letter;
    int num_of_wrong_guesses=0;
    string word;
    string words[] =
    {
    "able", "acid", "act", "add", "age", "ago""aid", "aide","AIDS","aim","air","all","ally","also","and","any","Arab","area","arm","army","ask","auto","away","art","baby","back","bad","bag","bake","ball","ban","band","bank","bar","base","bean","bear","beat","bed","chocolate","cholesterol","Christian","Christmas","cigarette","circumstance","classroom","coalition","cognitive","colleague","collection","collective","combination","comfortable","commander","commercial","commission","commitment","committee","communicate","communication","community","comparison","competition","competitive","competitor","complaint","completely","complicated","component","composition","comprehensive","concentrate","concentration","concerned","conclusion","condition","conference","confidence","confident","confusion","congressional","connection","consciousness","consensus","consequence","conservative","considerable","consideration","consistent","constantly","constitute","constitutional","construct","construction","consultant","consumption","container","contemporary","continued","contribute","contribution","controversial","controversy","convention","conventional","conversation","conviction","cooperation","corporate","corporation","correspondent","counselor","criticism","criticize","currently","curriculum","dangerous","defendant","defensive","definitely","definition","democracy","democratic","demonstrate","demonstration", "department","dependent","depending","depression","description","desperate","destruction", "determine", "developing", "development", "difference", "different", "differently", "difficult", "difficulty", "dimension", "direction", "disability", "disappear", "discipline", "discourse", "discovery", "discrimination", "discussion", "distinction", "distinguish", "distribute", "distribution", "diversity", "dramatically", "economics", "economist", "education", "educational", "effective", "effectively", "efficiency", "efficient", "electricity", "electronic", "elementary", "eliminate", "elsewhere", "emergency", "emotional", "emphasize", "employment", "encounter", "encourage", "enforcement", "engineering", "enterprise", "entertainment", "environment", "environmental", "equipment", "especially"
    };

    
    srand(time(NULL));
    int n=rand()% 10;
    word=words[n];
    
    
    string unknown(word.length(),'*');

    
    cout << "\n\nWelcome to hangman...Guess a country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
    
    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;
        

        if (letterFill(letter, word, unknown)==0)
        {
            cout << endl << "Whoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << endl << "You found a letter! Isn't that exciting!" << endl;
        }
        
        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;
        
        if (word==unknown)
        {
            cout << word << endl;
            cout << "Yeah! You got it!";
            break;
        }
    }
    if(num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\nSorry, you lose...you've been hanged." << endl;
        cout << "The word was : " << word << endl;
    }
    cin.ignore();
    cin.get();
    return 0;
}



int letterFill (char guess, string secretword, string &guessword)
{
    int i;
    int matches=0;
    int len=secretword.length();
    for (i = 0; i< len; i++)
    {
        
        if (guess == guessword[i])
            return 0;
        
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
