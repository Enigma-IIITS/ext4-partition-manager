#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


//fucntions which are helping comparision functions
bool checker(char * pattern , char * str , int str_offset , int pattern_size)
{

    int counter = 0;
    for(int i = 0; i < pattern_size; i++)
    {
        if(pattern[i] == str[str_offset+i])
        {
            counter++;
        }

        else 
        {
            break;
        }
    }

    if(counter == pattern_size)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

bool non_alphabet_checker(char * str)
{
    int i = 0;
    while(str[i])
    {
        if(!((str[i]>=65)&&(str[i]<=90))||((str[i]>=97)&&(str[i]<=122)))
        {
            //there is a non alphabet charecter in the string 
            return true;
        }
        i++;
    }
    
}








//comparison functions
void hard_compare(char * str1 , char * str2)
{
    if(strcmp(str1,str2) == 0)
    {
        printf("The strings are equal");
    }
    else
    {
        printf("The strings are not equal");
    }
}

void soft_compare(char * str1 , char * str2)
{
    int i = 0;
    while(str1[i])
    {
        str1[i] = tolower(str1[i]);
        i++;
    }

    i = 0;

    while(str2[i])
    {
        str2[i] = tolower(str2[i]);
        i++;
    }
    i=0;

    hard_compare(str1,str2);
}

void sub_string_check(char * str1, char * str2)
{
    //set this true if you need the pattern to be a seperate word
    bool pattern_as_seperate_word = true;

    //for readability and usage of flags in code
    bool flag1 = pattern_as_seperate_word;

    char *pattern = str2;
    int counter1 = 0;

    if(pattern[0] == '\0')
    {
        printf("Pattern cannot be a null string!");
        return ;
    }

    int i = 0;
    for( ; counter1 < strlen(str1) ;)
    {

        //checks if the patterns firt charecter and current pointed letter is same 
        if (str1[counter1] == pattern[0])
        {
            //checks if the pattern is observed here or not
            bool ret_val = checker(pattern,str1,counter1,strlen(pattern));
            if (ret_val == true)
            {
               
               //checks if the pattern is needed as a seperate word
                if((flag1 == true))
                {

                    //pattern observed as the first word
                    if(counter1 == 0)
                    {
                        if(str1[counter1+(strlen(pattern))] == ' ')
                        {
                            for(int j = counter1; j < counter1+(strlen(pattern)) ; j++)
                            {
                                printf("\033[0;31m"); //Set the text to the color red
                                printf("%c",str1[j]); //Display Hello in red
                                printf("\033[0m"); //Resets the text to default color
                            }
                            counter1 = counter1+(strlen(pattern));
                            i++;
                            continue;
                        }
                    }

                    //pattern is observed as a word somewhere in middle
                    else if((str1[counter1-1] == ' ')&&(str1[counter1+(strlen(pattern))] == ' '))
                    {
                        
                        for(int j = counter1; j < counter1+(strlen(pattern)) ; j++)
                        {
                            printf("\033[0;31m"); //Set the text to the color red
                            printf("%c",str1[j]); //Display Hello in red
                            printf("\033[0m"); //Resets the text to default color
                        }
                        counter1 = counter1+(strlen(pattern));
                        i++;
                        continue;
                        
                    }

                    //word oberved as the ending word
                    else if((str1[counter1-1] == ' ')&&(str1[counter1+(strlen(pattern))] == '\0'))
                    {
                        
                        for(int j = counter1; j < counter1+(strlen(pattern)) ; j++)
                        {
                            printf("\033[0;31m"); //Set the text to the color red
                            printf("%c",str1[j]); //Display Hello in red
                            printf("\033[0m"); //Resets the text to default color
                        }
                        counter1 = counter1+(strlen(pattern));
                        i++;
                        continue;
                        
                    }

                    //if pattern is observed inside another word
                    else
                    {
                        printf("%c",str1[counter1]);              
                        counter1++;
                        i++;
                        continue;
                    }
                   
                }

                //if the pattern is not required as a seperate word 

                for(int j = counter1; j < counter1+(strlen(pattern)) ; j++)
                {
                    printf("\033[0;31m"); //Set the text to the color red
                    printf("%c",str1[j]); //Display Hello in red
                    printf("\033[0m"); //Resets the text to default color
                }
                counter1 = counter1+(strlen(pattern));
                i++;
                continue;
            }

            //pattern is not seen 
            else
            {
                printf("%c",str1[counter1]);              
                counter1++;
                i++;
                continue;
            }
        }

        //first letter is not same
        else
        {
            printf("%c",str1[counter1]);              
            counter1++;
            i++;
            continue;
        }
        i++;
    }
    i=0;

}


void anangram_checker(char * str1, char * str2)
{

    if(non_alphabet_checker(str1))
    {
        printf("There is a non aplhabet charecter in the string 1!");
        return ;
    }
    if(non_alphabet_checker(str2))
    {
        printf("There is a non aplhabet charecter in the string 2!");
        return ;
    }

    int arr1[26]={0};
    int arr2[26]={0};
    bool flag = true;

    int i = 0;
    while(str1[i])
    {
        str1[i] = tolower(str1[i]);
        arr1[(int)(str1[i]-'a')]++;
        i++;
    }

    i = 0;

    while(str2[i])
    {
        str2[i] = tolower(str2[i]);
        arr2[(int)(str2[i]-'a')]++;
        i++;
    }
    i = 0 ;

    for(;i<26;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            flag = false;
            break;
        }
    }

    if(flag == false)
    {
        printf("it is not an anagram");
    }
    else
    {
        printf("it is an anagram");
    }
}

int main()
{
    //give your strings in here
    char str1[] = "man man a human who is a man";
    char str2[] = "man";

    //set the if block according to which ever comparision you need
    // to set turn the 0 to 1 and to reset turn 1 to 0
    
    //compare strings with no change
    if(0)
    {    
        hard_compare(str1,str2);
    }


    //compare with condition (NON CASE SENSITIVE)
    if(0)
    {
        soft_compare(str1,str2);    
    }

    //checkes if the both given strings are anagrams or not
    if(0)
    {
        anangram_checker(str1,str2);
    }


    //checks if a pattern is in the string
    //if you need the pattern being a seperate word then turn on the flag in the function
    if(1)
    {
        sub_string_check(str1,str2);
    }
    
}

/*
09 04 00 00 19 04 00 00 29 04 00 00 f9 00 ea 1f 07 00 04 00 00 00 00 00 dc 30 2b 37 e9 1f cd 36 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  8a 1b 43 01 00 00 00 00 
*/
