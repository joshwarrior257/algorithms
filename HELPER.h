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

#ifndef HELPER_H_
#define HELPER_H_

#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define clean_errno()   (errno == 0 ? "NONE" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d errno: %s)" M "\n",\
		__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define MAXLEN  1024
#define STDIN   stdin
#define STDOUT  stdout
#define STDERR  stderr

double Clock(void);

/*Prototypes for standard input*/
int STDIn_Integer(void);
long int STDIn_LongInteger();
double STDIn_Double();
int STDIn_String(char *string);

/*Prototype for standard output*/
int STDOut_Integer(int integer);
int STDOut_LongInteger(long int integer);
int STDOut_Double(double double_num);
int STDOut_String(char *string);

/*Prototypes for Random number */
void RANDOM_Seed();
int RANDOM_Integer();
double RANDOM_Double();


#endif
