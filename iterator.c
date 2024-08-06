/**
 * @file iterator.c
 * @author Shreyas CS
 * @brief containing definitions of all required functions.
 * @date 2024-08-06
 * 
 */
#include "iterator.h"
/**
 * @brief Pointer to char. This can be used to pass the command line arguments known to the user that the contents are not modified within the function.
 * 
 */
const char *g_argv1;
/**
 * @brief This is used to store each sub string of a argv dynamicaly.
 * 
 */
UCHAR8 *g_sub_string_argv1;
/**
 * @brief It is a counter used to calculate each character count in argv1
 * 
 */
static UINT32 g_argv1_char=0;

void main(UINT32 argc ,UCHAR8 **argv)
{
UCHAR8 *sub_string_argv1;
iter_init(argv[1]); //proper initialization of the iterator

sub_string_argv1=iter_next();// first call to iter_next()
printf("%s\n",sub_string_argv1);

sub_string_argv1=iter_next();//second call to iter_next()
printf("%s\n",sub_string_argv1);

if(iter_done()) //checking last substring has been returned (through the iter_next function) or not.
printf("last returened\n");
else
printf("not returned\n");

sub_string_argv1=iter_next();//third call to iter_next()
printf("%s\n",sub_string_argv1);

if(iter_done()) //checking last substring has been returned (through the iter_next function) or not.
printf("last returened\n");
else
printf("not returned\n");

sub_string_argv1=iter_next();//forth call to iter_next()
printf("%s\n",sub_string_argv1);

sub_string_argv1=iter_next();//fifth call to iter_next()
printf("%s\n",sub_string_argv1);

if(iter_done()) //checking last substring has been returned (through the iter_next function) or not.
printf("last returened\n");
else
printf("not returned\n");
}
/**
 * @brief Function to initialize the iterator with a string containing multiple substrings separated by white space.
 * Making command line argument as known to the user that the contents are not modified within the function.
 * 
 * @param argv passing the command line arguments. 
 */
void iter_init(UCHAR8 *argv)
{
g_argv1=argv;
}

/**
 * @brief Each call to the function returns the next substring from the string provided during the initialization till the last substring. After returning the last substring, the function should return NULL for subsequent calls.
 * In each call next substring are stored dynamicaly
 */
UCHAR8* iter_next()
{
    /** 
     * @brief count_subchar_argv1 this variable used to calculate characters in a substring
     * argv1_length is used to calculate length of command line argument
     * j is used to point first index of each substring and maintain proper index while assigning substring dynamicaly
     * l is used to maintain proper index while storing substring dynamicaly for g_sub_string_argv1
     */
UINT32 j,k,count_subchar_argv1,argv1_length,l=0;
argv1_length=strlen(g_argv1);//calculating length of argv1 of cammand line argument
for(count_subchar_argv1=0;g_argv1_char<argv1_length;g_argv1_char++)
{
    if(g_argv1[g_argv1_char]!=' ' && g_argv1[g_argv1_char]!='\0')
    {
    count_subchar_argv1++;//calculating each substring length of argv1
    continue;
    }
    break;   
}


if((g_argv1_char-1)<argv1_length)
{
g_sub_string_argv1=malloc(sizeof(char)*(count_subchar_argv1+1));//allocating memeory dynmicaly by using calculated length of each sustring
for(j=g_argv1_char-count_subchar_argv1,k=0;k<count_subchar_argv1;j++,k++)
{
    g_sub_string_argv1[l++]=g_argv1[j]; // storing substring character by character dynamicaly
}
g_sub_string_argv1[l]='\0'; //adding slash zero for last index of substring
g_argv1_char++; //skiping space after substring
return g_sub_string_argv1; //returning substring address stored dynamicaly
}

else
{
g_sub_string_argv1="NULL"; //if last substring is returned then storing NULL 
return g_sub_string_argv1; 
}
}


bool iter_done()
{
    if(g_argv1[g_argv1_char]=='\0') //checking weather last substring is returned or not 
    return true; 
    else
    return false;
}