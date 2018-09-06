#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;


int main(int argc, char **arg) {

    if ((arg[1] != NULL) && (arg[1] == '\0')) {
        printf("c is empty\n");
    }
    int size = 4;
    char str[80];
    char plus[250];
    char list[] = {'E' , 'T' , 'A' , 'O'};
    int registered [size];

    for(int n = 0 ; n< size; n++) {

        registered [n]= 0;
    }

    string text;
    int freq[128];
    char createFile[205];
    char userInput[250];

    strcpy(str, arg[1]);
    strcat(str, ".txt");

    cout << endl;
    cout << "opening " << arg[1] <<  " File " << endl;

    ifstream inFile ;
    char mychar;
    inFile.open(arg[1],ios::in);

    if (!inFile)
    {
        cout << "The input file could not be opened." <<endl;
        return 1;
    }


    for (int k = 0; k < 128; k++)
    {
        freq[k] = 0;
    }
    pid_t pid,wpid ;
    pid = fork();

    for (int i = 0; i < size; i++)
    {


        if ( pid  == 0)
        {
            mychar = inFile.get();

            while (mychar != EOF)
            {
                mychar = toupper(mychar);
                freq[mychar]++;
                mychar = inFile.get();
            }

            cout << endl << "A to Z " << endl;
            for (char ch = 'A'; ch <= 'Z'; ch++)
            {
                cout << ch << " : " << freq[ch] << endl;
            }

            _exit(0);

        }
        else
        {

            int status;
            waitpid(pid, &status , 0);

        }
    }

    return 0;
}
