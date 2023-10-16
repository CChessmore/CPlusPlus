#include <iostream>
#include <cmath>
#include <iostream>

using namespace std;
/*Basic number roulette game.
1) User starts with 1000 points
2) User will enter a number between 1 and 5 to start
3) If they get a win, they earn double their wager.
4) User can "cash out" and save their score, or "let it ride" to reduce 
   their odds for bigger winnings (payouts double every round).

*/
bool spin_the_wheel(int guess,int high);
int make_wager(int &wager, int &myNumber, int high, int points);
bool guess_is_right(int wager, int &multiplier, int &points);
int guess_is_wrong(int wager, int multiplier, int &points);

int main() {
    int points = 1000;
    int wager = -1;
    int myNumber;
    int multiplier = 1;
    int high = 5;
    bool win = false;
    bool cash_out = false;
    //Defaulting to C to cash out
    char choice = 'C';

    do
    {
        make_wager(wager, myNumber, high, points);
        if(spin_the_wheel(myNumber, high))
        {
            win = guess_is_right(wager, multiplier, points);
        }
        else
        {
            points = guess_is_wrong(wager, multiplier, points);
        }
        if(points > 0 && win)
        {
            cout << "Would you like to cash out (C) or risk more (R)?";
            cin >> choice;
            if(choice == 'C' || choice == 'c')
            {
                cash_out = true;
            }
            else if(choice == 'R' || choice == 'r')
            {
                //This should result in a multiplicative rise in reward
                //First is 2, then 4, then 8, 16, 32, etc.
                //Might change to multiplying itself if the payouts don't feel fun/high enough
                multiplier += multiplier;
                cout << "Multiplier is " << multiplier << endl;
                win = false;
            }
        }
        else
        {
            cout << "Try again(T) or quit(Q)?";
            cin >> choice;
            if(choice == 'Q' || choice == 'q')
            {
                cash_out = true;
                win = false;
            }
            else
            {
                cout << "Going again!" << endl;
            }
        }
    }
    while(!cash_out && points > 0);

    cout << "Your final score is: " << points << endl;
    cout << "Thanks for playing!";

    return 0;
}

bool spin_the_wheel(int guess,int high)
{
    //We need a +1 here, as rand % N will return values between 0 and N-1
    //On first run this should result in a range of 0 to 5
    int winner = rand() % (high+1);
    cout << "Wheel lands on " << winner << "!\n";
    if(guess == winner)
    {
        return true;
    }
    return false;
}

int make_wager(int &wager, int &myNumber, int high, int points)
{
    do
    {
        cout << "in loop\n";
    cout << "How many points would you like to wager (minimum of 1)? You currently have: " << points << " points." << endl;
    cin >> wager;
    cout << "Guess a number between 1 and " << high << endl;
    cin >> myNumber;}
    while(wager > 0 && myNumber <= high);
    return myNumber;
}

bool guess_is_right(int wager, int &multiplier, int &points)
{
    points += wager*multiplier;
    cout << "Winner! You got " << wager * multiplier << " points!\n";
    cout << "You now have: " << points << " points!\n";
    wager = wager * multiplier;
    
    return true;
}

int guess_is_wrong(int wager, int multiplier, int &points)
{
    cout << "Sorry, better luck next time!" << endl;
    points = points - (wager*multiplier);
    cout << "You lost " << wager*multiplier << " points, leaving you with " << points << endl;
    return points;
}