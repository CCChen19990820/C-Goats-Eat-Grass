#include <cstdlib>
#include <cstring>
#include <iostream>
#include "AnsiPrint.h"

using namespace std;

// a few constant ansi formatting string
const char *init="\x1b[";
const char *endc="m";
const char *hilit="1;";
const char *blink="5;";
const char *recover="\x1b[0m";
const char *fgBase="30;";
const char *bgBase="40;";
const int kFormatStrSize=20;

void AnsiPrint(const char *str, color fg, color bg, bool hi, bool blinking) {

	// kick out exceptional case
	if ((str==NULL)||(strlen(str)==0))
		return;
	// creating foreground and background options
	char *foreground=strdup(fgBase);
	foreground[1]+=fg;
	char *background=strdup(bgBase);
	background[1]+=bg;
	// initialize the formatting string
	char formatStr[kFormatStrSize]="";
	strcat(formatStr, init);
	// according to the options, append appropriate string
	if (hi) {
		strcat(formatStr, hilit);
	}
	if (blinking) {
		strcat(formatStr, blink);
	}
	if (fg!=nochange) {
		strcat(formatStr, foreground);
	}
	if (bg!=nochange) {
		strcat(formatStr, background);
	}
	// terminate the options
	if (formatStr[strlen(formatStr)-1]==';')
		formatStr[strlen(formatStr)-1]= '\0';
	strcat(formatStr,endc);
	// print to the standard output
#ifdef _WIN
	cout << str;
#else
	cout << formatStr << str << recover;
#endif
	// delete allocated buffer
	free(background);
	free(foreground);
	return;

}

void AnsiPrint(const char *str, bool hi, bool blinking) {

	// kick out exceptional case
	if ((str==NULL)||(strlen(str)==0))
		return;

	char formatStr[kFormatStrSize]="";
	if (hi||blinking) {
		// initialize the formatting string
		strcat(formatStr, init);
		// according to the options, append appropriate string
		if (hi) {
			strcat(formatStr, hilit);
		}
		if (blinking) {
			strcat(formatStr, blink);
		}
		if (formatStr[strlen(formatStr)-1]==';')
			formatStr[strlen(formatStr)-1]= '\0';
		strcat(formatStr,endc);
	}
	// print to the standard output
#ifdef _WIN
	cout << str;
#else
	cout << formatStr << str << recover;
#endif
	return;

}

