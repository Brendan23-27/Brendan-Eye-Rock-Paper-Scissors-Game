// the point of this program is for 2 NPCs (not player characters) to play rock paper scissors
// the program works through the use of for and while loops as well as the rand funtion and some if statments
// Results: The results are 2 NPCs play an accurate game of rock paper scissors
// Class: CS 2010
// Section: 1001
// Term: Spring 2025
// Author: Brendan Eye 
// Program: Eyeb_pgm4
// Due: 03/23/2025
// This was a very fun program trough it I was able to learn how to make and use vaalidation loops

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //consts for rock paper an scissors
    const int ROCK = 1;
    const int PAPER = 2;
    const int SCISSORS = 3;

    //win amounts for both players 
    int playerOneWinCount  = 0;
    int playerTwoWinCount = 0;

    //vars to hold player choices (random nums)
    int playerOneChoice;
    int playerTwoChoice;

    //vars for names
    string PlayerOneName;
    string PlayerTwoName;

    //var for game num
    int numOfGames = 0;

    //counter var
    int counter = 0;

    //var for while loop to ask if they want to play again 
    bool keepGoing = true;

    //input for keepGoing loop
    string playAgain;

    //get new random nums 
    srand(time(NULL));

    while (keepGoing)
    {
        //prompting the player for names of the players
        cout << "Hello what is your name?" << endl;
        cin >> PlayerOneName;
        cout << "Nice to meet you " << PlayerOneName << " what is your oppoent's name?" << endl;
        cin >> PlayerTwoName;

        //if oppoents names are the same go again
        if (PlayerOneName == PlayerTwoName)
        {
            cout << "You both can't have the same name let's try again" << endl;
            continue;
        }


        //prompting how many games the players want 
        cout << "How many rounds would you two like to play" << endl;
        cin >> numOfGames;


        cout << PlayerOneName << " vs " << PlayerTwoName << " for " << numOfGames <<  " rounds" << endl;

        //makeing it look cool
        cout.width(20);
        cout.fill('-');
        cout << '-' << endl;

        //while the round num is greater <= 0 print an error and keep going until its <= 0
        while (numOfGames <= 0)
        {
            cout << " You need to pick an amount of rounds that's more than 0 or we can't play" << endl;
            cin >> numOfGames;

            counter++;


            if (counter == 2)
            {
                cout << " I understand it can be difficult please give me a number bigger than 0" << endl;
                cin >> numOfGames;
            }

            if (counter > 2)
            {
                cout << " I'm starting to think you're messing with me I need a number bigger than 0" << endl;
                cin >> numOfGames;
            }
        }

        //num of rounds printed
        cout << " Great you selected " << numOfGames << endl;

        if (counter >= 2)
        {
            cout << " Great job I honestly did not think you could do it " << endl;
            cout << " you have " << numOfGames << " rounds " << endl;
        }

        do
        {
            cout << "Tie" << endl;
            playerOneChoice = 1 + rand() % 3;
            playerTwoChoice = 1 + rand() % 3;

        } while (playerOneChoice == playerTwoChoice);

        for (int i = -2; i < numOfGames; i++)
        {
            playerOneChoice = 1 + rand() % 3;
            playerTwoChoice = 1 + rand() % 3;

            //win condintions 
            if (playerOneChoice == ROCK && playerTwoChoice == SCISSORS)
            {
                cout << PlayerOneName << " Wins with rock" << endl;
                playerOneWinCount += 1;
            }

            if (playerTwoChoice == ROCK && playerOneChoice == SCISSORS)
            {
                cout << PlayerTwoName << " Wins with rock" << endl;
                playerTwoWinCount += 1;
            }

            if (playerOneChoice == PAPER && playerTwoChoice == ROCK)
            {
                cout << PlayerOneName << " Wins with Paper" << endl;
                playerOneWinCount += 1;
            }

            if (playerTwoChoice == PAPER && playerOneChoice == ROCK)
            {
                cout << PlayerTwoName << " Wins with rock" << endl;
                playerTwoWinCount += 1;
            }

            if (playerOneChoice == SCISSORS && playerTwoChoice == PAPER)
            {
                cout << PlayerOneName << " Wins with scissors" << endl;
                playerOneWinCount += 1;
            }


            if (playerTwoChoice == SCISSORS && playerOneChoice == PAPER)
            {
                cout << PlayerTwoName << " Wins with scissors " << endl;
                playerTwoWinCount += 1;
            }
        }

        //makeing it look cool
        cout.width(20);
        cout.fill('-');
        cout << '-' << endl;

        cout << PlayerOneName << " won " << playerOneWinCount << " rounds " << PlayerTwoName << " won " << playerTwoWinCount << " rounds " << endl;

    
    
        cout << "would you like to play again " << "yes or no" << endl;
        cin >> playAgain;

        if (playAgain == "yes" || playAgain == "Yes")
        {
            continue;
        }

        else if (playAgain == "no" || "No")
        {
            cout << "have a nice day" << endl;
            keepGoing = false;
            break;
        }


    }
}