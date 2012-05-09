//This file is not used in the final version of the project. 
//It is an initial version of the question generator.


#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	int x = 0;
	int level;
	level = 1;
	string question[36];
	srand (time(NULL));

	question[0] = "You have just entered, the Twilight Zone"; //this should never be invoked unless there is some bizarre coincidence

	question[1] = "The name of the Unix shell that we are using this semester is ____.#3#sh#ksh#bash#csh";

	question[2] = "Which of the following is more similar to a 'shortcut' on a Microsoft OS, such as Windows 7?#2#hard link#symbolic link#shortcut link#linker";

	question[3] = "Unix was originally developed at ____.#3#Apple Inc.#Microsoft#AT&T/Bell Labs#Texas Instruments";

	question[4] = "To view the contents of a file, type the command ______.#2#dog#cat#mouse#penguin";

	question[5] = "To see the files that are contained in your current directory, type the command _____.#4#cout#cd#echo#ls";

	question[6] = "Which command sends (almost) anything you type back to the screen?#2#ecko#echo#copy#cout";

	question[7] = "A ______ is used to create/modify text files.#2#text maker#text editor#texter#textme";

	question[8] = "A ______ is a compact way to specify a set of character strings.#2#regular programming#regular expression#command#string finder";

	question[9] = "In standard I/O streams  in C++, standard error is ______.#2#cin#cerr#cout#cerror";

	question[10] = "In standard I/O streams  in C++, standard output is ______.#2#cin#cout#cerr#coutput";

	question[11] = "In standard I/O streams  in C++, standard input is ______.#1#cin#cout#cerr#cinput";

	question[12] = "The ____ command removes a file.#3#remove#del#rm#erase";

	question[13] = "When used correctly, the shell command 'mv' does what?#4#deletes a file#sends the contents of a text file to the shell windows#lists all files in the current directory#changes the name and/or location of a file";

	question[14] = "Which one of the following is NOT a common UNIX shell command?#4#cp#rm#date#del";

	question[15] = "When we refer to the 'exec' system call on a Unix system, we are  typically referring to a family of system calls that are closely related.#1#True#False#Not enough information#Monkey butt";

	question[16] = "When using grep, the ______ matches the end of a line.#1#dollar ($)#ampresand (&)#carrot (^)#period (.)";

	question[17] = "When using grep, the ______ matches the beginning of a line.#4#asterisk (*)#ampresand (&)#period (.)#carrot (^)";

	question[18] = "When using grep, the ______ matches zero or more occurrences of the previous item.#1#asterisk (*)#ampresand (&)#dollar ($)#carrot (^)";

	question[19] = "______ looks for text lines in a file that match a specified pattern, and then prints those lines.#1#grep#sed#awk#search";

	question[20] = "______ is a program that performs non-interactive text editing.#4#awk#bash#grep#sed";

	question[21] = "______ is a program that applies a 'script' of pattern/action pairs to text.#1#awk#bash#grep#sed";

	question[22] = "'awk' supports a built-in variable with the name NR. The value that is automatically assigned to this variable is _________.#2#The field names of the current record#The number of input records seen by 'awk' so far#The field separator that is currently in use by 'awk'#The number of awkward moments in the code";

	question[23] = "A Unix shell command that lists only those files with names containing exactly 3 characters, in the current directory, is _____.#2#ls *#ls ???#ls ***#ls -3";

	question[24] = "One way to run a program in the background is to type the character _________ at the end of the shell command.#2#@ (at)#& (ampresand)#; (semi-colon)#none of the above";

	question[25] = "On a Unix system, the system call known as ________ will suspend the execution of a calling process until any of its child processes terminates.#2#fork#wait#exec#kill";

	question[26] = "When the system call known as ________ executes normally on a Unix system, a new process is created.#1#fork#wait#exec#kill";

	question[27] = "On a Unix system, the system call known as ______ can be used to send a signal to any process.#4#fork#wait#exec#kill";

	question[28] = "On a Unix system, the system call known as ______ can be used to return a status value to the parent.#3#for#wait#exit#exec";

	question[29] = "The shell command 'chmod 710 myfile' will result in file permission codes ____________, as reported by 'ls -l'.#2#rwxrw-r--#rwx--x---#r---w---x#r--r--r--";

	question[30] = "The PATH shell variable is used to store _____.#3#the full path to the current directory#the full path to the user's home directory#the list of directories that the shell searches for commands to execute#the path of the variable";

	question[31] = "What does grep stand for?#3#globally find regular expressions and patterns#globally regulating expressions and programs#globally find regular expressions and print#globally finding regular expressions and programming";

	question[32] = "Suppose that you are using the vi text editor, and you are in 'command' mode.  Which one of the following is NOT a command  to exit the vi program?#2#:q#ESC (pressing escape key)#ZZ#none of the above";

	question[33] = "If a Unix program is running in the foreground, then it can be suspended by typing ______.#2#CONTROL-a#CONTROL-z#CONTROL-c#CONTROL-p";

	question[34] = "The purpose of the Unix shell's 'nice' command is _______.#3#To report the list of jobs initiated by the user#To measure the amount of time that the machine uses to run a program#To change the priority level of a process#none of the above";

	question[35] = "Which of the following is NOT a valid process state on a Unix system, as reported by the 'ps' command?#4#R#S#T#All of the above";


	switch(level){
	case 1:
		x = rand() % 7 + 1;
		break;
	case 2:
		x = rand() % 8 + 7;
		break; 
	case 3:
		x = rand() % 8 + 15;
		break;
	case 4:
		x = rand() % 8 + 22;
		break;
	case 5:
		x = rand() % 8 + 29;
		break;
	default:
		cout << question[0] << endl;
		break;
	}
	cout << question[x];

	cin.get();
	return 0;
}

