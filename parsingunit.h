#ifndef __JINSU_PARSING_H__
#define __JINSU_PARSING_H__

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string.h>
#include "dbinterface.h"

using namespace std;

class ParsingUnit
{
	private:
		DBinterface *DB;
		string aBuffer;
	public:
		int Open(DBinterface *);
		int Input(string);
};

#endif
