#include <iostream>
#include <cmath>

using namespace std;
/*Basic number roulette game.
1) User starts with 1000 points
2) User will enter a number between 1 and 5 to start
3) If they get a win, they earn double their wager.
4) User can "cash out" and save their score, or "let it ride" to reduce 
   their odds for bigger winnings (payouts double every round).

*/
int main() {
    int points = 1000;
    //Minimum wager is 1
    int wager = 1;
    int myNumber;
    int multiplier = 2;
    int high = 5;
    bool cash_out = false;
    //Defaulting to C to cash out
    char choice = 'C';

    do
    {
        make_wager(wager, myNumber, high, points);
        if(spin_the_wheel(myNumber, high))
        {
            guess_is_right(wager, multiplier, points);
        }
        else
        {
            points = guess_is_wrong(wager, points);
        }
        if(points > 0)
        {
            cout << "Would you like to cash out (C) or risk more (R)?";
            cin >> choice;
            if(choice == 'C')
            {
                cash_out = true;
            }
            else if(choice == 'R')
            {
                //This should result in a multiplicative rise in reward
                multiplier += multiplier;
            }
        }
    }
    while(!cash_out);

    cout << "Your final score is: " << points << endl;
    cout << "Thanks for playing!";

    return 0;
}

bool spin_the_wheel(int guess,int high)
{
    //We need a +1 here, as rand % N will return values between 0 and N-1
    //On first run this should result in a range of 0 to 5
    return (guess == rand() % (high+1));
}

int make_wager(int &wager, int &myNumber, int high, int points)
{
    cout << "How many points would you like to wager (minimum of 1)? You currently have: " << points << "points." << endl;
    cin >> wager;
    cout << "Guess a number between 1 and " << high << endl;
    cin >> myNumber;
    return myNumber;
}

bool guess_is_right(int wager, int &multiplier, int &points)
{
    cout << "Winner! You got " << wager * multiplier << " points!\n";
    cout << "You now have: " << points << " points!";
    wager = wager * multiplier;
    points += wager;
}

int guess_is_wrong(int wager, int &points)
{
    cout << "Sorry, better luck next time!" << endl;
    points = points - wager;
    cout << "You lost " << wager << " points, leaving you with " << points;
    return points;
}