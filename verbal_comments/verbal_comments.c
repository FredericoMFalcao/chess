#include "../main.h"
#include "verbal_comments.h"

void no_action_phrase(){
	unsigned long i = random() % 3;
	char phrase[1024];
	
	if (i == 0) sprintf(phrase, "say \""PHRASE_1"\"", "you");
	if (i == 1) sprintf(phrase, "say \""PHRASE_2"\"", "you");
	if (i == 2) sprintf(phrase, "say \""PHRASE_3"\"", "you");
	if (i == 3) sprintf(phrase, "say \""PHRASE_4"\"", "you");
	
		
	system(phrase);
}