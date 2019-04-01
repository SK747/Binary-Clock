
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "binaryclock.h"

enum {
  MAX_VARIABLE_LENGTH = 8   
};

static uint16_t currentType;
static uint16_t currentNumber;
static uint16_t currentTime[3];
static uint16_t variable_index = 0;

char variable[MAX_VARIABLE_LENGTH + 1];



static const int microscript_start = 22;
static const int microscript_first_final = 22;
static const int microscript_error = 0;

static const int microscript_en_main = 22;


static uint8_t cs; 

void init_microscript( void ) {
    
	cs = microscript_start;
}

void parse_microscript(const char* p, uint16_t len, uint8_t is_eof) {
    const char* pe = p + len; /
    const char* eof = is_eof ? pe : ((char*) 0); 
    
	const char *_acts;
	unsigned int _nacts;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	switch ( cs ) {
case 22:
	if ( (*p) == 32 )
		goto tr1;
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr1;
	goto tr0;
case 0:
	goto _out;
case 1:
	if ( (*p) == 32 )
		goto tr1;
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr1;
	goto tr0;
case 2:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr7;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 3:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr3;
	goto tr0;
case 23:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr8;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr8;
	goto tr0;
case 4:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr8;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr8;
	goto tr0;
case 5:
	if ( (*p) == 32 )
		goto tr6;
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr9;
	} else if ( (*p) >= 9 )
		goto tr6;
	goto tr0;
case 6:
	switch( (*p) ) {
		case 10: goto tr11;
		case 32: goto tr10;
		case 58: goto tr13;
		case 59: goto tr14;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr12;
	} else if ( (*p) >= 9 )
		goto tr10;
	goto tr0;
case 7:
	switch( (*p) ) {
		case 10: goto tr16;
		case 32: goto tr15;
		case 59: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr15;
	goto tr0;
case 24:
	switch( (*p) ) {
		case 10: goto tr16;
		case 32: goto tr18;
		case 59: goto tr17;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr18;
	goto tr0;
case 8:
	switch( (*p) ) {
		case 10: goto tr16;
		case 32: goto tr18;
		case 59: goto tr17;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr18;
	goto tr0;
case 9:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr19;
	goto tr0;
case 10:
	switch( (*p) ) {
		case 10: goto tr21;
		case 32: goto tr20;
		case 58: goto tr23;
		case 59: goto tr24;
		case 97: goto tr25;
		case 112: goto tr26;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr22;
	} else if ( (*p) >= 9 )
		goto tr20;
	goto tr0;
case 11:
	switch( (*p) ) {
		case 10: goto tr28;
		case 32: goto tr27;
		case 59: goto tr29;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr27;
	goto tr0;
case 25:
	switch( (*p) ) {
		case 10: goto tr28;
		case 32: goto tr30;
		case 59: goto tr29;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr30;
	goto tr0;
case 12:
	switch( (*p) ) {
		case 10: goto tr28;
		case 32: goto tr30;
		case 59: goto tr29;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto tr30;
	goto tr0;
case 13:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr31;
	goto tr0;
case 14:
	switch( (*p) ) {
		case 10: goto tr21;
		case 32: goto tr20;
		case 59: goto tr24;
		case 97: goto tr25;
		case 112: goto tr26;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr32;
	} else if ( (*p) >= 9 )
		goto tr20;
	goto tr0;
case 15:
	switch( (*p) ) {
		case 10: goto tr34;
		case 32: goto tr33;
		case 59: goto tr35;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr33;
	goto tr0;
case 16:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr36;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 17:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr37;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 18:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr38;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 19:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr39;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 20:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr40;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
case 21:
	switch( (*p) ) {
		case 10: goto tr4;
		case 32: goto tr3;
		case 59: goto tr5;
		case 61: goto tr6;
	}
	if ( (*p) > 13 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr41;
	} else if ( (*p) >= 9 )
		goto tr3;
	goto tr0;
	}

	tr0: cs = 0; goto f0;
	tr1: cs = 1; goto _again;
	tr2: cs = 2; goto f1;
	tr3: cs = 3; goto _again;
	tr41: cs = 3; goto f3;
	tr8: cs = 4; goto _again;
	tr6: cs = 5; goto _again;
	tr9: cs = 6; goto f4;
	tr12: cs = 6; goto f7;
	tr15: cs = 7; goto _again;
	tr10: cs = 7; goto f5;
	tr18: cs = 8; goto _again;
	tr13: cs = 9; goto f5;
	tr19: cs = 10; goto f9;
	tr22: cs = 10; goto f12;
	tr27: cs = 11; goto _again;
	tr20: cs = 11; goto f10;
	tr33: cs = 11; goto f17;
	tr30: cs = 12; goto _again;
	tr23: cs = 13; goto f5;
	tr31: cs = 14; goto f15;
	tr32: cs = 14; goto f16;
	tr25: cs = 15; goto f5;
	tr26: cs = 15; goto f13;
	tr7: cs = 16; goto f3;
	tr36: cs = 17; goto f3;
	tr37: cs = 18; goto f3;
	tr38: cs = 19; goto f3;
	tr39: cs = 20; goto f3;
	tr40: cs = 21; goto f3;
	tr5: cs = 22; goto f2;
	tr14: cs = 22; goto f6;
	tr17: cs = 22; goto f8;
	tr24: cs = 22; goto f11;
	tr29: cs = 22; goto f14;
	tr35: cs = 22; goto f18;
	tr4: cs = 23; goto f2;
	tr11: cs = 24; goto f6;
	tr16: cs = 24; goto f8;
	tr21: cs = 25; goto f11;
	tr28: cs = 25; goto f14;
	tr34: cs = 25; goto f18;

	f3: _acts = _microscript_actions + 1; goto execFuncs;
	f17: _acts = _microscript_actions + 3; goto execFuncs;
	f5: _acts = _microscript_actions + 5; goto execFuncs;
	f2: _acts = _microscript_actions + 7; goto execFuncs;
	f8: _acts = _microscript_actions + 9; goto execFuncs;
	f14: _acts = _microscript_actions + 11; goto execFuncs;
	f0: _acts = _microscript_actions + 13; goto execFuncs;
	f1: _acts = _microscript_actions + 15; goto execFuncs;
	f18: _acts = _microscript_actions + 18; goto execFuncs;
	f13: _acts = _microscript_actions + 21; goto execFuncs;
	f10: _acts = _microscript_actions + 24; goto execFuncs;
	f6: _acts = _microscript_actions + 27; goto execFuncs;
	f7: _acts = _microscript_actions + 30; goto execFuncs;
	f12: _acts = _microscript_actions + 33; goto execFuncs;
	f16: _acts = _microscript_actions + 36; goto execFuncs;
	f9: _acts = _microscript_actions + 39; goto execFuncs;
	f15: _acts = _microscript_actions + 43; goto execFuncs;
	f11: _acts = _microscript_actions + 47; goto execFuncs;
	f4: _acts = _microscript_actions + 51; goto execFuncs;

execFuncs:
	_nacts = *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
	currentNumber = 0;
	break;
	case 1:
	variable[variable_index++] = (*p);
	break;
	case 2:
	variable_index = 0; memset(variable, 0, MAX_VARIABLE_LENGTH);
	break;
	case 3:
	memset(currentTime, 0, sizeof(currentTime)); 
	break;
	case 4:
	currentTime[0] = currentNumber;
	break;
	case 5:
	currentTime[1] = currentNumber;
	break;
	case 6:
	currentTime[2] = currentNumber;
	break;
	case 7:
	break;
	case 8:
	currentType = TYPE_TIME;
	break;
	case 9:
	currentType = TYPE_NUMBER;
	break;
	case 10:
	var_display(variable);
	break;

	case 11:
	var_set(variable, currentNumber);
	break;

	case 12:
		time_set(variable, currentTime);
		break;

	case 13:
		break;
	case 14:
	    uint8_t digit = (*p) - '0';
	    currentNumber = currentNumber * 10 + digit;
	break;
		}
	}
	goto _again;

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _microscript_actions + _microscript_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 13:
	break;
		}
	}
	}

	_out: {}

}
