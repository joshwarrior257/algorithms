/**************************************************************************************************
 * AUTHOR - GAGANDEEP SINGH.
 * DATE   - 6-07-2014.
 *
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************************************/

#include "HELPER.h"

/*************************************
 * Wrapper for the time library.
 * **********************************/
/*********************************
 * Clock() function returns the 
 * time in floating point second
 * format.
 * ******************************/
double Clock()
{
 clock_t clock_tick = clock();

 if (clock_tick == -1)
 {
    log_err("Clock Unavailable");
    exit(0);
 }
 else
 {
    return (((double)clock_tick)/CLOCKS_PER_SEC);
 }
}

/*************************************************
 * Wrapper for RANDOM number generator with seed
 * as calendar time.
 * **********************************************/
/* SEED for the random generator*/
void RANDOM_Seed()
{
 unsigned int time_in_sec;
 time_in_sec = (time(NULL)) % UINT_MAX;
 srand(time_in_sec);

}

/* Random Integers between 0 and RAND_MAX*/
int RANDOM_Integer()
{
 return rand();
}

/*Random Double between 0.0 and 1.0*/
double RANDOM_Double()
{
 return (1.0*rand())/RAND_MAX;
}


/**************************************************
 * User define functions for STD input and output.
 * ***********************************************/

/**************************************************
 * Reading Integer from STDinput.
 * ***********************************************/
int STDIn_Integer()
{
 char array[MAXLEN];
 int ret_val = EOF;
 
 if (fgets(array, MAXLEN, STDIN) == NULL)
    ret_val = EOF;
 else
    ret_val = atoi(array);

 return ret_val;

}

/**************************************************
 * Reading long Integer from STDinput.
 * ***********************************************/
long int STDIn_LongInteger()
{
 char array[MAXLEN];
 long int ret_val = EOF;
 
 if (fgets(array, MAXLEN, STDIN) == NULL)
    ret_val = EOF;
 else
    ret_val = atol(array);

 return ret_val;

}

/**************************************************
 * Reading double from STDinput.
 * ***********************************************/
double STDIn_Double()
{
 char array[MAXLEN];
 double ret_val = EOF;
 
 if (fgets(array, MAXLEN, STDIN) == NULL)
    ret_val = EOF;
 else
    ret_val = atof(array);

 return ret_val;

}

/**************************************************
 * Reading string line from STDinput.
 * ***********************************************/
int STDIn_String(char *string)
{
 int ret_val ;
 
 if (fgets(string, MAXLEN, STDIN) == NULL)
    ret_val = EOF;

 return ret_val;

}

/**************************************************
 * Writing Integer to STDOutput.
 * ***********************************************/

int STDOut_Integer(int integer)
{
 int ret_val = -1;
 ret_val = fprintf(STDOUT, "%d\n", integer);
 return ret_val;

}

/**************************************************
 * Writing Long Integer to STDOutput.
 * ***********************************************/

int STDOut_LongInteger(long int integer)
{
 int ret_val = -1;
 ret_val = fprintf(STDOUT, "%ld\n", integer);
 return ret_val;

}

/**************************************************
 * Writing Double to STDOutput.
 * ***********************************************/

int STDOut_Double(double double_num)
{
 int ret_val = -1;
 ret_val = fprintf(STDOUT, "%f\n", double_num);
 return ret_val;

}

/**************************************************
 * Writing String to STDOutput.
 * ***********************************************/

int STDOut_String(char *string)
{
 int ret_val = -1;
 ret_val = fprintf(STDOUT, "%s\n", string);
 return ret_val;
}






