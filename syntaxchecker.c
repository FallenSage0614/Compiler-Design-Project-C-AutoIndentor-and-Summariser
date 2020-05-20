#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prntf = 0, scnf = 0, fpts = 0, fgts = 0, fprntf = 0, fscnf = 0, pts = 0, gts = 0;
int curly = 0, curve = 0, straight = 0;
int int_c = 0, float_c = 0, double_c = 0, long_c = 0, char_c = 0, string_c = 0, bool_c = 0;
int intf_c = 0, floatf_c = 0, doublef_c = 0, longf_c = 0, charf_c = 0, stringf_c = 0, boolf_c = 0, void_c = 0;

typedef struct
{
    char line[1000];
    int len;
} s2;

void stripStartingSpaces(char line[])
{
    int spaceFlag = 0;
    int i_p = 0;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] != ' ')
        {
            spaceFlag = 1;
        }
        if (spaceFlag)
        {
            line[i_p] = line[i];
            i_p++;
        }
    }
    line[i_p] = '\0';
}

void fileReading(s2 file[], int *linecount, char *filename)
{
    FILE *p;
    p = fopen(filename, "r"); // make sure that the file exists, if not create it

    int i = 0, k = 0;
    while (!feof(p))
    {
        // printf("\nCheckpoint %d\n", i);
        fgets(file[i].line, 1000, p);
        stripStartingSpaces(file[i].line);
        if (file[i].line[1] == '\0' || file[i].line[0] == '\n' || (file[i].line[0] == '/' && file[i].line[1] == '/') || (file[i].line[0] == '/' && file[i].line[1] == '*'))
        {
            continue;
        }
        *linecount += 1;
        file[i].len = strlen(file[i].line);
        for (k = 0; k < file[i].len; k++)
        {
            if (file[i].line[k] == '/' && file[i].line[k + 1] == '/')
            {
                file[i].line[k] = '\n';
                file[i].line[k + 1] = '\0';
            }
            file[i].len = strlen(file[i].line) - 1; //cehck this
        }
        printf("%d", i + 1);
        printf("-%s", file[i].line);
        i++;
    }
    //printf("%d- }",i+1);
}

void printData(s2 file[], int *linecount)
{
    printf("\n\n\nBASIC INFORMATION ABOUT THE ABOVE CODE\n=========================================");
    printf("\n\tTotal num of lines-->\t\t        %d", *linecount);
    printf("\n\tTotal built in functions used-->\t%d", prntf + scnf + fscnf + fprntf + fgts + fpts + pts + gts);
    printf("\n\tTotal num of variables used-->\t\t%d", int_c - intf_c + long_c - longf_c + float_c - floatf_c + double_c - doublef_c + char_c - charf_c + string_c - stringf_c + bool_c - boolf_c);
    printf("\n\nINFORMATION ABOUT FUNCTIONS USED IN THE ABOVE CODE\n=====================================================");
    if (void_c > 0)
        printf("\n\tTotal number of \"void\" fuctions-->         %d", void_c);

    if (intf_c > 0)
        printf("\n\tTotal number of \"integer\" fuctions-->      %d", intf_c);
    if (longf_c > 0)
        printf("\n\tTotal number of \"long\" fuctions-->      %d", longf_c);

    if (floatf_c > 0)
        printf("\n\tTotal number of \"float\" fuctions-->     %d", floatf_c);
    if (doublef_c > 0)
        printf("\n\tTotal number of \"double\" fuctions-->      %d", doublef_c);

    if (charf_c > 0)
        printf("\n\tTotal number of \"char\" fuctions-->     %d", charf_c);
    if (stringf_c > 0)
        printf("\n\tTotal number of \"string\" fuctions-->      %d", stringf_c);

    if (boolf_c > 0)
        printf("\n\tTotal number of \"bool\" fuctions-->      %d", boolf_c);

    if (prntf > 0)
        printf("\n\tTotal number of \"printf\" function-->       %d", prntf);
    if (scnf > 0)
        printf("\n\tTotal number of \"scanf\" function-->        %d", scnf);

    if (fscnf > 0)
        printf("\n\tTotal number of \"fscanf\" function-->       %d", fscnf);
    if (fprntf > 0)
        printf("\n\tTotal number of \"fprintf\" function-->       %d", fprntf);

    if (fgts > 0)
        printf("\n\tTotal number of \"fgets\" function-->        %d", fgts);
    if (fpts > 0)
        printf("\n\tTotal number of \"fputs\" function--->       %d", fpts);

    if (pts > 0)
        printf("\n\tTotal number of \"puts\" function-->         %d", pts);
    if (gts > 0)
        printf("\n\tTotal number of \"gets\" function-->         %d", gts);

    printf("\n\nINFORMATION ABOUT THE BRACKETS USED IN ABOVE CODE\n====================================================");
    if (curly > 0)
        printf("\n\t%d closing curly bracket is missing ", curly); //if count = -n that means there are } extra brackets.
    else if (curly < 0)
        printf("\n\t%d opening curly bracket is missing", -curly);
    else
        printf("\n\tcurly brackets are perfectly closed");

    if (curve > 0)
        printf("\n\t%d closing curve bracket is missing ", curve); //if count = -n that means there are } extra brackets.
    else if (curve < 0)
        printf("\n\t%d opening curve bracket is missing", -curve);
    else
        printf("\n\tcurve brackets are perfectly closed");

    if (straight > 0)
        printf("\n\t%d closing long bracket is missing ", straight); //if count = -n that means there are } extra brackets.
    else if (straight < 0)
        printf("\n\t%d opening long bracket is missing", -straight);
    else
        printf("\n\tlong brackets are perfectly closed");

    printf("\n\nINFORMATION ABOUT THE VARIABLES USED\n========================================");

    if (float_c - floatf_c > 0)
        printf("\n\tthe num of floats variables used are ---> %d", float_c - floatf_c);
    else
        printf("\n\tno float variables used");

    if (double_c - doublef_c > 0)
        printf("\n\tthe num of double variables used are --> %d", double_c - doublef_c);
    else
        printf("\n\tno double variables used");

    if (int_c - intf_c > 0)
        printf("\n\tthe num of int variables used are --> %d", int_c - intf_c);
    else
        printf("\n\tno int variables used");

    if (long_c - longf_c > 0)
        printf("\n\tthe num of long variables used are --> %d", long_c - longf_c);
    else
        printf("\n\tno long variables used");

    if (string_c - stringf_c > 0)
        printf("\n\tthe num of string variables used are --> %d", string_c - stringf_c);
    else
        printf("\n\tno string variables used");

    if (char_c - charf_c > 0)
        printf("\n\tthe num of char variables used are --> %d", char_c - charf_c);
    else
        printf("\n\tno char variables used");

    if (bool_c - boolf_c > 0)
        printf("\n\tthe num of bool variables used are --> %d", bool_c - boolf_c);
    else
        printf("\n\tno bool variables used");
}

void checker(s2 file[], int *linecount)
{
    int m, k;
    for (int i = 0; i < *linecount; i++)
    {
        for (k = 0; k < file[i].len; k++)
        {
            // printf("\nCheckpoint %d %d %c\n", i, k, file[i].line[k]);

            //inbuilt functions
            /*scanf*/
            if (file[i].line[k] == 's' && file[i].line[k + 1] == 'c' && file[i].line[k + 2] == 'a' && file[i].line[k + 3] == 'n' && file[i].line[k + 4] == 'f' && file[i].line[k + 5] == '(')
            {
                scnf += 1;
            }
            /*printf*/
            if (file[i].line[k] == 'p' && file[i].line[k + 1] == 'r' && file[i].line[k + 2] == 'i' && file[i].line[k + 3] == 'n' && file[i].line[k + 4] == 't' && file[i].line[k + 5] == 'f' && file[i].line[k + 6] == '(')
            {
                prntf += 1;
            }
            /*fscanf*/
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 's' && file[i].line[k + 2] == 'c' && file[i].line[k + 3] == 'a' && file[i].line[k + 4] == 'n' && file[i].line[k + 5] == 'f' && file[i].line[k + 6] == '(')
            {
                fscnf += 1;
            }
            /*fprintf*/
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 'p' && file[i].line[k + 2] == 'r' && file[i].line[k + 3] == 'i' && file[i].line[k + 4] == 'n' && file[i].line[k + 5] == 't' && file[i].line[k + 6] == 'f' && file[i].line[k + 7] == '(')
            {
                fprntf += 1;
            }
            /*fgets*/
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 'g' && file[i].line[k + 2] == 'e' && file[i].line[k + 3] == 't' && file[i].line[k + 4] == 's' && file[i].line[k + 5] == '(')
            {
                fgts += 1;
            }
            /*fputs*/
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 'p' && file[i].line[k + 2] == 'u' && file[i].line[k + 3] == 't' && file[i].line[k + 4] == 's' && file[i].line[k + 5] == '(')
            {
                fpts += 1;
            }
            /*gets*/
            if (file[i].line[k] == 'g' && file[i].line[k + 1] == 'e' && file[i].line[k + 2] == 't' && file[i].line[k + 3] == 's' && file[i].line[k + 4] == '(')
            {
                gts += 1;
            }
            /*puts*/
            if (file[i].line[k] == 'p' && file[i].line[k + 1] == 'u' && file[i].line[k + 2] == 't' && file[i].line[k + 3] == 's' && file[i].line[k + 4] == '(')
            {
                pts += 1;
            }

            // brackets check
            if (file[i].line[k] == '{')
            {
                curly++;
            }
            if (file[i].line[k] == '}')
            {
                curly--;
            }
            if (file[i].line[k] == '(')
            {
                curve++;
            }
            if (file[i].line[k] == ')')
            {
                curve--;
            }
            if (file[i].line[k] == '[')
            {
                straight++;
            }
            if (file[i].line[k] == ']')
            {
                straight--;
            }

            //function check
            /*void function*/
            if (file[i].line[k] == 'v' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'i' && file[i].line[k + 3] == 'd' && file[i].line[k + 4] == ' ')
            {
                for (m = k + 5; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        void_c += 1;
                        break;
                    }
                }
            }
            /*float function*/
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 'l' && file[i].line[k + 2] == 'o' && file[i].line[k + 3] == 'a' && file[i].line[k + 4] == 't' && file[i].line[k + 5] == ' ')
            {
                for (m = k + 6; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        floatf_c += 1;
                        break;
                    }
                }
            }
            //int function
            if (file[i].line[k] == 'i' && file[i].line[k + 1] == 'n' && file[i].line[k + 2] == 't' && file[i].line[k + 3] == ' ')
            {
                for (m = k + 4; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        intf_c += 1;
                        break;
                    }
                }
            }
            // long function
            if (file[i].line[k] == 'l' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'n' && file[i].line[k + 3] == 'g' && file[i].line[k + 4] == ' ')
            {
                for (m = k + 5; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        longf_c += 1;
                        break;
                    }
                }
            }
            //double function
            if (file[i].line[k] == 'd' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'u' && file[i].line[k + 3] == 'b' && file[i].line[k + 4] == 'l' && file[i].line[k + 5] == 'e' && file[i].line[k + 6] == ' ')
            {
                for (m = k + 7; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        doublef_c += 1;
                        break;
                    }
                }
            }
            //char function
            if (file[i].line[k] == 'c' && file[i].line[k + 1] == 'h' && file[i].line[k + 2] == 'a' && file[i].line[k + 3] == 'r' && file[i].line[k + 4] == ' ')
            {
                for (m = k + 5; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        charf_c += 1;
                        break;
                    }
                }
            }
            //string function
            if (file[i].line[k] == 's' && file[i].line[k + 1] == 't' && file[i].line[k + 2] == 'r' && file[i].line[k + 3] == 'i' && file[i].line[k + 4] == 'n' && file[i].line[k + 5] == 'g' && file[i].line[k + 6] == ' ')
            {
                for (m = k + 7; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        stringf_c += 1;
                        break;
                    }
                }
            }
            //bool function
            if (file[i].line[k] == 'b' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'o' && file[i].line[k + 3] == 'l' && file[i].line[k + 4] == ' ')
            {
                for (m = k + 5; m < file[i].len; m++)
                {
                    if (file[i].line[m] == '(')
                    {
                        boolf_c += 1;
                        break;
                    }
                }
            }

            //variables check
            if (file[i].line[k] == 'i' && file[i].line[k + 1] == 'n' && file[i].line[k + 2] == 't' && file[i].line[k + 3] == ' ')
            {
                int_c += 1;
                for (k = k + 4; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        int_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 'l' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'n' && file[i].line[k + 3] == 'g' && file[i].line[k + 4] == ' ')
            {
                long_c += 1;
                for (k = k + 5; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        long_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 'c' && file[i].line[k + 1] == 'h' && file[i].line[k + 2] == 'a' && file[i].line[k + 3] == 'r' && file[i].line[k + 4] == ' ')
            {
                char_c += 1;
                for (k = k + 5; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        char_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 's' && file[i].line[k + 1] == 't' && file[i].line[k + 2] == 'r' && file[i].line[k + 3] == 'i' && file[i].line[k + 4] == 'n' && file[i].line[k + 5] == 'g' && file[i].line[k + 6] == ' ')
            {
                string_c += 1;
                for (k = k + 7; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        string_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 'd' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'u' && file[i].line[k + 3] == 'b' && file[i].line[k + 4] == 'l' && file[i].line[k + 5] == 'e' && file[i].line[k + 6] == ' ')
            {
                double_c += 1;
                for (k = k + 7; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        double_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 'f' && file[i].line[k + 1] == 'l' && file[i].line[k + 2] == 'o' && file[i].line[k + 3] == 'a' && file[i].line[k + 4] == 't' && file[i].line[k + 5] == ' ')
            {
                float_c += 1;
                for (k = k + 6; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        float_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
            if (file[i].line[k] == 'b' && file[i].line[k + 1] == 'o' && file[i].line[k + 2] == 'o' && file[i].line[k + 3] == 'l' && file[i].line[k + 4] == ' ')
            {
                bool_c += 1;
                for (k = k + 5; k <= file[i].len; k++)
                {
                    if (file[i].line[k] == ',')
                        bool_c += 1;
                    if (file[i].line[k] == ';')
                        break;
                    else
                        continue;
                }
            }
        }
    }
}

void summarize(char *filename)
{
    s2 file[1000];
    int lc = 0;
    fileReading(file, &lc, filename); //in total lines..code is counting extra used lines too...
    // printf("Checkpoint level2");
    checker(file, &lc);
    printData(file, &lc);
}