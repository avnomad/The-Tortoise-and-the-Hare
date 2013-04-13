//	Copyright (C) 2007, 2008, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of The Tortoise and the Hare.
 *
 *	The Tortoise and the Hare is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	The Tortoise and the Hare is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with The Tortoise and the Hare.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;
using std::clock;

#define LENGH 70
#define TIMEGAP 1000

void wait(clock_t milliseconds);

int main()
{
	int c;
	unsigned int result;
	int hare = 0;
	int tortoise = 0;
	
	srand(time(0));
	
	for(c = 0 ; c < LENGH + 4 ; c++ )
	    cout << (char)196;
	cout << endl;
	cout << 'H' << (char)179 << setw(LENGH + 1) << (char)179 << endl;
	cout << 'T' << (char)179 << setw(LENGH + 1) << (char)179 << endl;
	for(c = 0 ; c < LENGH + 4 ; c++ )
	    cout << (char)196;
	cout << endl;
	wait(TIMEGAP);
	cout << "Let the race begin!" << '\n' << endl;

	while(1)
	{
		//delay
        wait(TIMEGAP);
        //clear the screen
        system("CLS");
        //print upper line
        for(c = 0 ; c < LENGH + 4 ; c++ )
	    	cout << (char)196;
	    cout << endl;
	    //determine hare's move
        result = rand() % 10;
        if( result < 2 )
			hare += 9;
		else if ( result < 3 )
		{
			hare -= 12;
			if( hare < 0 ) hare = 0;
		}
		else if ( result < 6 )
		    hare += 1;
		else if ( result < 8 )
		{
			hare -= 2;
			if( hare < 0 ) hare = 0;
		}
		//determine tortoise's move
        result = rand() % 10;
        if( result < 5 )
			tortoise += 3;
		else if ( result < 7 )
		{
			tortoise -= 6;
			if( tortoise < 0 ) tortoise = 0;
		}
		else 
		    tortoise += 1;
		//print hare's move
		if ( hare == 0 )
		    cout << 'H' << (char)179 << setw(LENGH + 1) << (char)179 << endl;
		else if( hare == LENGH + 1 )
        	cout << ' ' << (char)179 << setw(LENGH + 1) << 'H' << endl;
		else if( hare > LENGH + 1 )
		    cout << ' ' << (char)179 << setw(LENGH + 1) << (char)179 << setw(hare - (LENGH + 1)) << 'H' << endl;
		else
		    cout << ' ' << (char)179 << setw(hare) << 'H' << setw(LENGH + 1 - hare) << (char)179 << endl;
		//print tortoise's move
		if ( tortoise == 0 )
		    cout << 'T' << (char)179 << setw(LENGH + 1) << (char)179 << endl;
		else if( tortoise == LENGH + 1 )
        	cout << ' ' << (char)179 << setw(LENGH + 1) << 'T' << endl;
		else if( tortoise > LENGH + 1 )
		    cout << ' ' << (char)179 << setw(LENGH + 1) << (char)179 << setw(tortoise - (LENGH + 1)) << 'T' << endl;
		else
		    cout << ' ' << (char)179 << setw(tortoise) << 'T' << setw(LENGH + 1 - tortoise) << (char)179 << endl;
        //print lower line
        for(c = 0 ; c < LENGH + 4 ; c++ )
	    	cout << (char)196;
		cout << endl;
		//check for the end of the race
		if( tortoise > LENGH && hare > LENGH)
		{
            cout << '\n' << "It's a tie ladies and gentlemen!!!\n" << endl;
		    break;
		}
		else if( tortoise > LENGH )
		{
		    cout << '\n' << "And the winner is... Tortoise!!!\n" << endl;
		    break;
		}
		else if( hare > LENGH )
		{
		    cout << '\n' << "And the winner is... the Hare!!!\n" << endl;
		    break;
		}
		
	}
	system("PAUSE");
	return 0;
}

void wait(clock_t milliseconds)
{
	clock_t stop;
	
	stop = clock() + milliseconds;
	while( clock() < stop);
}
