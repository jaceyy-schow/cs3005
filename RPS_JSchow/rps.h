#ifndef _RPS_H_
#define _RPS_H_
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>

const std::string rock( "Rock" );
const std::string paper( "Paper" );
const std::string scissors( "Scissors" );
const int ROCK ( 1 );
const int PAPER ( 2 );
const int SCISSORS( 3 );
const int USER ( 11 );
const int RANDOM ( 12 );
const int TIE( 13 );


void initializeRandomNumbers();

int getRandomPlayerChoice();

int getUserPlayerChoice( std::istream& input_stream, std::ostream& output_stream );

int determineWinner(int user_choice, int random_choice);

void displayMatchResults( std::ostream& output_stream, int user_choice, int random_choice, int winner );

void displayStatistics( std::ostream& output_stream, int number_user_wins, int number_user_losses, int number_user_ties );

bool askUserIfGameShouldContinue( std::istream& input_stream, std::ostream& output_stream );

#endif
