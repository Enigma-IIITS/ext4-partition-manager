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
    char str1[] = "u_int bg_block_bitmap_lo_val;\nu_int bg_block_bitmap_hi_val;\nu_int bg_inode_bitmap_lo_val;\nu_int bg_inode_bitmap_hi_val;\nu_int bg_inode_table_lo_val;\nu_int bg_inode_table_hi_val;";
    char str2 [sizeof(str1)];

    char pattern[] ="u_int";
    int counter1 = 0;
    int counter2 = 0;

    for(int i = 0 ; i < sizeof(str1) ; i++ )
    {
        if (str1[counter1] == pattern[0])
        {
            bool ret_val = checker(pattern,str1,counter1,sizeof(pattern)-1);
            if (ret_val == true)
            {
                counter1 = counter1+(sizeof(pattern)-2);
                printf("s");
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