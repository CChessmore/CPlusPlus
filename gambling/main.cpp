#include <iostream>
#include <cmath>
#include <iostream>
#include <game.cpp>

using namespace std;
/*Basic number roulette game.
1) User starts with 1000 points
2) User will enter a number between 1 and 5 to start
3) If they get a win, they earn double their wager.
4) User can "cash out" and save their score, or "let it ride" to reduce 
   their odds for bigger winnings (payouts double every round).
Using this as a quick review of functional programming.

Done differently, I would improve how variables are tracked and passed. May remake at
a later date to create a better implementation.
*/

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
                cout << "Multiplier is " << multiplier << endl;
                high = high + 5;
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
                if(points <= 0)
                {
                    cout << "Not enough points!" << endl;
                    break;
                }
                cout << "Going again!" << endl;
            }
        }
    }
    while(!cash_out && points > 0);

    cout << "Your final score is: " << points << endl;
    cout << "Thanks for playing!" << endl;

    return 0;
}

