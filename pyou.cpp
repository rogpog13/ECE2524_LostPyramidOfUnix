/*****************************************
* Pyramid of Unix
* BY: Roger Baker, Kim Do, Wayne An
* 5.1.12 - ECE 2524 - Intro to Unix
* Semester Project
* - A trivia game created to help students
*   study for unix. It features many questions
*   used in quizzes, notes, etc. throughout
    the semester.
******************************************/

#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <vector>
#include <wchar.h>
#include <locale.h>

using namespace std;

struct Block{
	char line0[500];
	char line1[500];
	char line2[500];
	char line3[500];
	char line4[500];
};

string pullQuestion(int level, vector<string> question);
vector<string> generateQuestions();
void pmap(int player1, int player2);
static void setBlock(Block* A, Block B);
static void printBlock(Block A);


int answer, pos = 0;
string pound = "#";
string answer1, answer2, answer3, answer4;
string currentRead;


int main()
{   
    setlocale(LC_ALL,"");

	do{
	cout << endl;
	cout << "       ______                           _     _ " <<endl;
	cout << "       | ___\\                          (_)   | | " << endl;
    cout << "       | |_/ /_   _ _ __ __ _ _ __ ___  _  __| |   " << endl;
	cout << "       |  __/| | | |  __/ _  |  _   _ \\| |/ _  |  " << endl;
	cout << "       | |   | |_| | | | (_| | | | | | | |\\(_| |    " << endl;
	cout << "       \\_|   \\__,|_|_| \\_,_|_| |_| |_|_|_||__,_|  " << endl;
	cout << "               __/ |                                  " << endl;
	cout << "              |___/                              " << endl;
	cout << "                     __   _   _       _    " << endl;
    cout << "                    / _| | | | |     (_)     " << endl;
	cout << "               ___ | |_  | | | |_ __  ___  __" << endl;
	cout << "              / _ \\|  _| | | | | '_ \\| \\ \\/ /" << endl;
	cout << "             | (_) | |   | |_| | | | | |>  < " << endl;
	cout << "              \\___/|_|    \\___/|_| |_|_/_/\\_\\ " << endl << endl;
	cout << "                        with your host Darren Maczka!" << endl<< endl;
	cout << "   Created by: Roger Baker, Wayne An and Kim Do" << endl;
	cout << endl;
  

	//player level integers
	int player1 = 1;
    int player2 = 1;

    //player names
	string userName1;
	string userName2;
	int userAns;

	//when playerTurn ==0, it is player 1's turn
	bool playerTurn = 0;
    string ques;

    //create question array
	vector<string> question = generateQuestions(); 

     cout << "Player 1 please enter your name:";
	 getline(cin, userName1);

     cout << "Player 2 please enter your name:";
	 getline(cin, userName2);

	do{
     //print map
     cout << endl << endl;
     pmap(player1, player2);
	 cout << endl << endl;

	 //pull question
	 if(!playerTurn)
	 {
	   ques = pullQuestion(player1, question);
	   cout << userName1 << "- You need " << 6-player1 << " more correct answers.";
	   cout << " Here is your next question." << endl <<endl ;
	 }
	 else
	 {
	   ques = pullQuestion(player2, question);
	   cout << userName2 << "- You need " << 6-player2 << " more correct answers.";
	   cout << " Here is your next question." << endl<<endl ;
	 }
   
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
             cout << "Good job, " << userName1 << "! You have " << player1-1 << " points" << endl;
		 }
		 else
		 {
			 player2++;
			 cout << "Good job," << userName2 << " You have " << player2-1 << " points" << endl;
		 }
		}

		//incorrect, but valid answer
		else
		{
         if(playerTurn==0)
			 cout << "Sorry " << userName1;
		 else
			 cout << "Sorry " << userName2;
		 cout << ", the correct answer was number " << answer<< endl;
		}

	 }
	 playerTurn = !playerTurn;
	 cout << "Press enter to continue...";
	 getline(cin, currentRead);

	}while(player1 != 6 && player2 != 6);

	//congratulate winner
    if(player1 == 6)
		cout << "Congratulations " << userName1 << ", you are a Unix master!" << endl;
	else
		cout << "Congratulations " << userName2 << ", you are a Unix master!" << endl;

	cout << "Press Y then Enter to play again...";
	getline(cin, currentRead);
    }
	while(currentRead[0] == 'Y' || currentRead[0] == 'y');

    return 0;
  }

string pullQuestion(int level, vector<string> question)
{
    int x = 0;
	srand(time(NULL));
	x = rand()% 35+1 ;
	return  question[x];
}


void pmap (int playerA, int playerB)
{
	int n = 0;
    Block PYRAMID_BLOCK;
	Block PLAYER_A;
	Block PLAYER_B;
	Block BLANK;
	Block U;
	Block N;
	Block I;
	Block X;

	//---------------------------------------------------------
	//INITIALIZE THE BASIC SHAPES
	//---------------------------------------------------------

	//INIT BLANK
	n = sprintf(BLANK.line0,"       ");
	n = sprintf(BLANK.line1,"       ");
	n = sprintf(BLANK.line2,"       ");
	n = sprintf(BLANK.line3,"       ");
	n = sprintf(BLANK.line4,"       ");

	//INIT PYRAMID
	n = sprintf(PYRAMID_BLOCK.line0,"       ");
	n = sprintf(PYRAMID_BLOCK.line1," \u2588\u2588\u2588\u2588\u2588");
	n = sprintf(PYRAMID_BLOCK.line2," \u2588\u2588\u2588\u2588\u2588");
	n = sprintf(PYRAMID_BLOCK.line3," \u2588\u2588\u2588\u2588\u2588");
	n = sprintf(PYRAMID_BLOCK.line4," \u2588\u2588\u2588\u2588\u2588");

	//INIT PLAYER_A
	n = sprintf(PLAYER_A.line0,"       ");
	n = sprintf(PLAYER_A.line1,"  \u2593   \u2593");
	n = sprintf(PLAYER_A.line2,"  \u2593\u2593\u2593\u2593\u2593");
	n = sprintf(PLAYER_A.line3,"  \u2593 \u2593 \u2593");
	n = sprintf(PLAYER_A.line4,"   \u2593\u2593\u2593 ");


	//INIT PLAYER_B
	n = sprintf(PLAYER_B.line0,"       ");
	n = sprintf(PLAYER_B.line1," \u2593\u2593\u2593\u2593\u2593 ");
	n = sprintf(PLAYER_B.line2," \u2593 \u2593 \u2593 ");
	n = sprintf(PLAYER_B.line3,"  \u2593\u2593\u2593  ");
	n = sprintf(PLAYER_B.line4,"  \u2593 \u2593 ");

	//INIT U
	n = sprintf(U.line0,"       ");
	n = sprintf(U.line1," \u2588   \u2588");
	n = sprintf(U.line2," \u2588   \u2588");
	n = sprintf(U.line3," \u2588   \u2588");
	n = sprintf(U.line4,"  \u2588\u2588\u2588 ");

	//INIT N
	n = sprintf(N.line0,"       ");
	n = sprintf(N.line1," \u2588\u2588  \u2588");
	n = sprintf(N.line2," \u2588 \u2588 \u2588");
	n = sprintf(N.line3," \u2588  \u2588\u2588");
	n = sprintf(N.line4," \u2588   \u2588");

	//INIT I
	n = sprintf(I.line0,"       ");
	n = sprintf(I.line1," \u2588\u2588\u2588\u2588\u2588");
	n = sprintf(I.line2,"   \u2588  ");
	n = sprintf(I.line3,"   \u2588  ");
	n = sprintf(I.line4," \u2588\u2588\u2588\u2588\u2588");

	//INIT X
	n = sprintf(X.line0,"       ");
	n = sprintf(X.line1," \u2588   \u2588");
	n = sprintf(X.line2,"  \u2588\u2588\u2588 ");
	n = sprintf(X.line3,"  \u2588\u2588\u2588 ");
	n = sprintf(X.line4," \u2588   \u2588");


	//---------------------------------------------------------
	//PRINTING PYRAMID
	//---------------------------------------------------------
	Block pyramid_line0;
	Block pyramid_line1;
	Block pyramid_line2;
	Block pyramid_line3;
	Block pyramid_line4;
	Block pyramid_line5;

	//THE PLAYER BLOCKS:
	Block A1;
	Block A2;
	Block A3;
	Block A4;
	Block A5;
	Block A6;

	Block B1;
	Block B2;
	Block B3;
	Block B4;
	Block B5;

	//SET PLAYER A POSITION BLOCKS:
	if (playerA==1)		setBlock(&A1, PLAYER_A);
	else				setBlock(&A1, BLANK);

	if (playerA==2)		setBlock(&A2, PLAYER_A);
	else				setBlock(&A2, BLANK);

	if (playerA==3)		setBlock(&A3, PLAYER_A);
	else				setBlock(&A3, BLANK);

	if (playerA==4)		setBlock(&A4, PLAYER_A);
	else				setBlock(&A4, BLANK);

	if (playerA==5)		setBlock(&A5, PLAYER_A);
	else				setBlock(&A5, BLANK);

	if (playerA==6)			setBlock(&A6, PLAYER_A);
	else if (playerB==6)	setBlock(&A6, PLAYER_B);
	else				setBlock(&A6, BLANK);

	//SET PLAYER B POSITION BLOCKS:
	if (playerB==1)		setBlock(&B1, PLAYER_B);
	else				setBlock(&B1, BLANK);

	if (playerB==2)		setBlock(&B2, PLAYER_B);
	else				setBlock(&B2, BLANK);

	if (playerB==3)		setBlock(&B3, PLAYER_B);
	else				setBlock(&B3, BLANK);

	if (playerB==4)		setBlock(&B4, PLAYER_B);
	else				setBlock(&B4, BLANK);

	if (playerB==5)		setBlock(&B5, PLAYER_B);
	else				setBlock(&B5, BLANK);




	//SET UP PYRAMID LINE 0:
	sprintf(pyramid_line0.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0, A6.line0
		,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf(pyramid_line0.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1, A6.line1
		,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf(pyramid_line0.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2, A6.line2
		,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf(pyramid_line0.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3, A6.line3
		,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf(pyramid_line0.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4, A6.line4
		,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4);


	//SET UP PYRAMID LINE 1:
	sprintf(pyramid_line1.line0," %s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,A5.line0, PYRAMID_BLOCK.line0
		,B5.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf(pyramid_line1.line1," %s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,A5.line1, PYRAMID_BLOCK.line1
		,B5.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf(pyramid_line1.line2," %s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,A5.line2, PYRAMID_BLOCK.line2
		,B5.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf(pyramid_line1.line3," %s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,A5.line3, PYRAMID_BLOCK.line3
		,B5.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf(pyramid_line1.line4," %s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,A5.line4, PYRAMID_BLOCK.line4
		,B5.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4);


	//SET UP PYRAMID LINE 2:
	sprintf(pyramid_line2.line0,"  %s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,A4.line0,PYRAMID_BLOCK.line0, U.line0
		,PYRAMID_BLOCK.line0,B4.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf(pyramid_line2.line1,"  %s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,A4.line1,PYRAMID_BLOCK.line1, U.line1
		,PYRAMID_BLOCK.line1,B4.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf(pyramid_line2.line2,"  %s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,A4.line2,PYRAMID_BLOCK.line2, U.line2
		,PYRAMID_BLOCK.line2,B4.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf(pyramid_line2.line3,"  %s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,A4.line3,PYRAMID_BLOCK.line3, U.line3
		,PYRAMID_BLOCK.line3,B4.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf(pyramid_line2.line4,"  %s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,A4.line4,PYRAMID_BLOCK.line4, U.line4
		,PYRAMID_BLOCK.line4,B4.line4,BLANK.line4,BLANK.line4,BLANK.line4);

	//SET UP PYRAMID LINE 3:
	sprintf(pyramid_line3.line0,"   %s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,A3.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, N.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B3.line0,BLANK.line0,BLANK.line0);
	sprintf(pyramid_line3.line1,"   %s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,A3.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, N.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B3.line1,BLANK.line1,BLANK.line1);
	sprintf(pyramid_line3.line2,"   %s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,A3.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, N.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B3.line2,BLANK.line2,BLANK.line2);
	sprintf(pyramid_line3.line3,"   %s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,A3.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, N.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B3.line3,BLANK.line3,BLANK.line3);
	sprintf(pyramid_line3.line4,"   %s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,A3.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, N.line4
		,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,B3.line4,BLANK.line4,BLANK.line4);

	//SET UP PYRAMID LINE 4:
	sprintf(pyramid_line4.line0,"    %s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,A2.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, I.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B2.line0,BLANK.line0);
	sprintf(pyramid_line4.line1,"    %s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,A2.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, I.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B2.line1,BLANK.line1);
	sprintf(pyramid_line4.line2,"    %s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,A2.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, I.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B2.line2,BLANK.line2);
	sprintf(pyramid_line4.line3,"    %s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,A2.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, I.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B2.line3,BLANK.line3);
	sprintf(pyramid_line4.line4,"    %s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,A2.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, I.line4
		,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,B2.line4,BLANK.line4);

	//SET UP PYRAMID LINE 5:
	sprintf(pyramid_line5.line0,"     %s%s%s%s%s%s%s%s%s%s%s",A1.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, X.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B1.line0);
	sprintf(pyramid_line5.line1,"     %s%s%s%s%s%s%s%s%s%s%s",A1.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, X.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B1.line1);
	sprintf(pyramid_line5.line2,"     %s%s%s%s%s%s%s%s%s%s%s",A1.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, X.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B1.line2);
	sprintf(pyramid_line5.line3,"     %s%s%s%s%s%s%s%s%s%s%s",A1.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, X.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B1.line3);
	sprintf(pyramid_line5.line4,"     %s%s%s%s%s%s%s%s%s%s%s",A1.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, X.line4
		,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,B1.line4);


	printBlock(pyramid_line0);
	printBlock(pyramid_line1);
	printBlock(pyramid_line2);
	printBlock(pyramid_line3);
	printBlock(pyramid_line4);
	printBlock(pyramid_line5);

	//---------------------------------------------------------
 
}

//FUNCTION TO SET CONTENT OF BLOCK B TO CONTENT OF BLOCK A
void setBlock(Block* A, Block B){
	sprintf(A->line0, "%s", B.line0);
	sprintf(A->line1, "%s", B.line1);
	sprintf(A->line2, "%s", B.line2);
	sprintf(A->line3, "%s", B.line3);
	sprintf(A->line4, "%s", B.line4);
}


//FUNCTION TO PRINT CONTENT OF A BLOCK:
void printBlock( Block A){
	printf("%s", A.line0);
	cout<<endl;
	printf("%s", A.line1);
	cout<<endl;
	printf("%s", A.line2);
	cout<<endl;
	printf("%s", A.line3);
	cout<<endl;
	printf("%s", A.line4);
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

	question[35] = "Which of the following is NOT a valid process state on a Unix system, as reported by the 'ps' command?#5#R#S#T#All of the above";

	return question;
}
