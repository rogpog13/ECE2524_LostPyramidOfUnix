#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <vector>
using namespace std;

string pullQuestion(int level, vector<string> question);
vector<string> generateQuestions();

int answer, pos = 0;
string pound = "#";
string answer1, answer2, answer3, answer4;


int main()
{   cout << endl;
	cout << "______                           _     _ " <<endl;
	cout << "| ___\\                          (_)   | | " << endl;
    cout << "| |_/ /_   _ _ __ __ _ _ __ ___  _  __| |   " << endl;
	cout << "|  __/| | | |  __/ _  |  _   _ \\| |/ _  |  " << endl;
	cout << "| |   | |_| | | | (_| | | | | | | |\\(_| |    " << endl;
	cout << "\\_|   \\__,|_|_| \\_,_|_| |_| |_|_|_||__,_|  " << endl;
	cout << "        __/ |                                  " << endl;
	cout << "       |___/                              " << endl;
	cout << "              __   _   _       _    " << endl;
    cout << "             / _| | | | |     (_)     " << endl;
	cout << "        ___ | |_  | | | |_ __  ___  __" << endl;
	cout << "       / _ \\|  _| | | | | '_ \\| \\ \\/ /" << endl;
	cout << "      | (_) | |   | |_| | | | | |>  < " << endl;
	cout << "       \\___/|_|    \\___/|_| |_|_/_/\\_\\ " << endl << endl;
	cout << "                 with your host Darren Maczka!" << endl<< endl;
	cout << "Created by: Roger Baker, Wayne An and Kim Do" << endl;
	cout << endl;
 
	//player level integers
	int player1 = 1;
    int player2 = 1;
	int userAns;

	//when playerTurn ==0, it is player 1's turn
	bool playerTurn = 0;
    string ques;

    //create question array
	vector<string> question = generateQuestions(); 

	do{
     //print map
  //   pmap(player1, player2);
	 cout << endl << endl;

	 //pull question from player's respective level
	 if(!playerTurn)
	 {
	   ques = pullQuestion(player1, question);
	   cout << "PLAYER 1 - You need " << 6-player1 << " more correct answers.";
	   cout << " Here is your next question." << endl <<endl ;
	 }
	 else
	 {
	   ques = pullQuestion(player2, question);
	   cout << "PLAYER 2 - You need " << 6-player2 << " more correct answers.";
	   cout << " Here is your next question." << endl<<endl ;
	 }
    
	 //ques = "If a Unix program is running in the foreground, then it can be suspended by typing ______.#2#CONTROL-a#CONTROL-z#CONTROL-c#trash";
	 //get position of first #
	 pos = ques.find_first_of("#");
	 //print out question
	 cout << ques.substr(0,pos) << endl;
	 //get actual answer
	 answer = atoi(&ques.at(pos+1));
	 //take away up to second hash
	 ques = ques.substr(pos+3);
	 

	 //print out all options
     pos = ques.find_first_of("#");
	 cout << "1. "<< ques.substr(0,pos) << endl;
	 ques = ques.substr(pos+1);

	 pos = ques.find_first_of("#");
	 cout << "2. "<< ques.substr(0,pos) << endl;
	 ques = ques.substr(pos+1);

	 pos = ques.find_first_of("#");
	 cout << "3. "<< ques.substr(0,pos) << endl;
	 ques = ques.substr(pos+1);

	 cout << "4. "<< ques.substr(0) << endl;

	 //get input
	 cout << "Your answer:";
     string currentRead;
	 getline(cin, currentRead);
	 
     if(!isdigit(currentRead[0]))
          cout << "Wrong input, you lose your turn." << endl;
	 else
	 {
	    userAns = atoi(currentRead.c_str()); 
        if(userAns > 4 || userAns <0)
			cout << "Wrong input, you lose your turn." << endl;
       
		//correct answer
        if(userAns == answer)
		{
         if(playerTurn ==0)
		 {
			 player1++;
             cout << "Good job, player 1! You have " << player1-1 << " points" << endl;
		 }
		 else
		 {
			 player2++;
			 cout << "Good job, player 2! You have " << player2-1 << " points" << endl;
		 }
		}
		//incorrect, but valid answer
		else
		{
         if(playerTurn==0)
			 cout << "Sorry player 1";
		 else
			 cout << "Sorry player 2";
		 cout << ", the correct answer was number " << answer<< endl;
		}

	 }
	 playerTurn = !playerTurn;
	 cout << "Press enter to continue...";
	 getline(cin, currentRead);

	}while(player1 != 5 || player2 != 5);

	//congratulate winner
    if(player1 == 5)
		cout << "Congratulations player 1, you are a Unix master!" << endl;
	else
		cout << "Congratulations player 2, you are a Unix master!" << endl;

    return 0;
  }

string pullQuestion(int level, vector<string> question)
{
    int x = 0;
	//string question[36];
	srand (time(NULL));
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
		cout << "Ah ah ah! You didn't say the magic word!" << endl;
		break;
	}
	return  question[x];
}


vector<string> generateQuestions()
{
	vector<string> question(36);
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

	return question;
}