//doesnt work for unicode

#include <stdio.h>
#include <stdbool.h>



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

int main()
{
    //give the string in which you want some text inside to be reoved 
    char str1[] = "";
    char str2 [sizeof(str1)];

    //give the text that needs to be removed in str1
    char pattern[] = "";
    int counter1 = 0;
    int counter2 = 0;

    if(pattern[0] == '\0')
    {
        printf("Pattern cannot be a null string!");
        return 0;
    }

    for(int i = 0 ; i < sizeof(str1) ; i++ )
    {
        if (str1[counter1] == pattern[0])
        {
            bool ret_val = checker(pattern,str1,counter1,sizeof(pattern)-1);
            if (ret_val == true)
            {
                counter1 = counter1+(sizeof(pattern)-1);
                continue;
            }
            else
            {
                str2[counter2] = str1[counter1];
                counter1++;
                counter2++;
                continue;
            }
        }
        else
        {
            str2[counter2] = str1[counter1];
            counter1++;
            counter2++;
            continue;
        }
    }

    printf(str2);
}
