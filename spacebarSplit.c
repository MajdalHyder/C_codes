/*
** A function to replicate the Split function for a Spacebar charachter separator in c
**
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split (char *str){                                    //char** to dynamically allocate
  int strln = 0;                                             //to iterate over the charachters of the string passed to the function
  int i = 0;                                                 //to iterate overcharachters looking for separator "here ' ' " count
  int separator_count = 0;                                   // spacebar counter
  
  while (str[i] != '\0'){                                    // while loop to count space bars
    if (str[i] == ' '){
	    separator_count++;
	  }
    i++;
  }
    
  char **word_array;                                         //arra declaration to store words
  word_array = malloc ((separator_count+1)*sizeof(char*));   // allocating memory  +1 for the NULL terminator
  int word_len = 0;                                          // to store words lengths s we iterate over the string
  int separator_index = 0;                                   // to store separator index in after every word
  int b = 0;                                                 // to start iterating charachter by charachter looking for words
  
  for (int a = 0; a < (separator_count + 1); a++){           // to start filling words at each index of allocated array
    word_len = 0;                                            // start counting word length
    while (strln < strlen(str)+1){                           //start iterating over the string 
	    strln++;                                               //count charachter
	    if (str[b] == ' ' || str[b] == '\0'){                  // if charachter is space or \0 stop
	      separator_index = b;                                 // store separator index
	      word_array[a] = malloc (word_len * sizeof (char));   //allocate at index 'a' of word array a size equal to word_len value
	      int word_depth = 0;                                  // start a counter for word_len  == word charachter depth into od array
	        for (int c = (separator_index - word_len); c < separator_index; c++){   // start at c = index of first charachter in word
		        word_array[a][word_depth] = str[c];              // at index word_depth store charachter of word
		        word_depth++;                                    // increment for next charachter
		      }
	      word_array[a][word_len] = '\0';                      // when done terminate with null charachter
	      word_len = 0;                                        // reset word length
	      b++;                                                 // go to charachter after separator
	      break;                                               // break out of while to go to next index and look for next word
	    }
	  word_len++;                                              // if separator not found yet increment word length
	  b++;                                                     // increment charachter
	  }
  }
  return word_array;
}

/* Test Main
**int main (){
**  char s[] = "A complete toolkit for building search into your product. API clients for key languages and platforms.";
**  char **ss = split (s);
**  int i=0;
**  while(ss[i] != NULL){
**    for (int j = 0; j < strlen (ss[i]); j++){
**	  printf ("%c", ss[i][j]);
**	  }
**    printf ("\n");
**    i++;
**  }
}*/
