#ifndef _CONSOLE_COLOR_AZA_H_
#define _CONSOLE_COLOR_AZA_H_

typedef enum {
	Normal = 0,
	Red,
	Blue,
	Green,
	Magenta,
	Cyan,
	White,
	Yellow	
}Color;

//Set foreground color
void set_fcolor(Color color){
	switch(color){
		case Normal:{printf("\x1B[0m");}break;
		case Red:{printf("\x1B[31m");}break;
		case Blue:{printf("\x1B[34m");}break;
		case Green:{printf("\x1B[32m");}break;
		case Magenta:{printf("\x1B[35m");}break;
		case Cyan:{printf("\x1B[36m");}break;
		case White:{printf("\x1B[37m");}break;
		case Yellow:{printf("\x1B[33m");}break;
	}
}
//Set background color
void set_bcolor(Color color){
	switch(color){
		case Normal:{printf("\x1B[0m");}break;
		case Red:{printf("\x1B[41m");}break;
		case Blue:{printf("\x1B[44m");}break;
		case Green:{printf("\x1B[42m");}break;
		case Magenta:{printf("\x1B[45m");}break;
		case Cyan:{printf("\x1B[46m");}break;
		case White:{printf("\x1B[47m");}break;
		case Yellow:{printf("\x1B[43m");}break;
	}
}

#endif
