/* A program to extract the first int number "multi-digit-or single digit" from a String
** this is a prototype and works or the example string in main()
** function works by a copy paste if enough attention is paid to the parameters"
*/
#include <stdio.h>

int main() {
    char s[] = "-----+-429++--334";  //test string
    int my_number = my_getnbr(s);    //assign function return to variable
    printf("%d\n", my_number);       // print result
    return 0;
}
/*--------------------------------------------------------*/

int my_getnbr(char *str){                                        //function declared                      
    int start_index = 0;                                        //start index of first integer encountered iterating over string charachters
    int len=0;                                                  //length of the string passed to function
    int result=0;                                               //final return value with full int
    int multiplier=1;                                           //to construct the result with multifigures starting from right 
    int end_index=0;                                            //end index 
    int i = 0;
    while(str[i] != '\0'){                                      //calculate passed string length
        i++;
        len++;
    }
    
    i = 0;                                                      //reset i
    
    for(int i = 0; i<len; ++i){                                 //start iterating over string 
        if (str[i] >= 48 && str[i] <= 57){                      //first occurence of a digit charachter
          start_index = i;                                      // mark index
          end_index = start_index;                              //set end index counter
          while(str[end_index] >= 48 && str[end_index] <= 57){  //as long as the following charachter is an int
             ++end_index;                                       //increment end index
          }
          end_index = end_index-1;                              //shift end_index
          break;                                                //once while iterates over non digit charachter => break
        }
    }
    for(int k = end_index; k >= start_index; k--){              // from end indx to start index
        result = result + (str[k]-'0')*multiplier;              // result is the digit multiplied by a multiplier
        multiplier=multiplier*10;                               // with every iteration multiplier is multiplied by 10 to keep up with figures
    }
    if(str[start_index-1] == 45){                               // finally if charachter before first digit is a minus sign 
        result = result * (-1);                                 // multiply result by -1;
    }
    return result;
}



