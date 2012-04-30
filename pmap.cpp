#include <stdio.h>
#include <iostream>


using namespace std;

struct Block{
	char line0[500];
	char line1[500];
	char line2[500];
	char line3[500];
	char line4[500];
	
};

static void setBlock(Block* A, Block B);
static void printBlock(Block A);

void pmap (int playerA, int playerB)
{
	int BLOCK = 219;
	int BLOCK_DOT = 178;
	int n=0;

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
	n = sprintf_s(BLANK.line0,"       ");
	n = sprintf_s(BLANK.line1,"       ");
	n = sprintf_s(BLANK.line2,"       ");
	n = sprintf_s(BLANK.line3,"       ");
	n = sprintf_s(BLANK.line4,"       ");

	//INIT PYRAMID
	n = sprintf_s(PYRAMID_BLOCK.line0,"       ");
	n = sprintf_s(PYRAMID_BLOCK.line1," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);
	n = sprintf_s(PYRAMID_BLOCK.line2," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);
	n = sprintf_s(PYRAMID_BLOCK.line3," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);
	n = sprintf_s(PYRAMID_BLOCK.line4," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);

	//INIT PLAYER_A
	n = sprintf_s(PLAYER_A.line0,"       ");
	n = sprintf_s(PLAYER_A.line1," %c   %c ",BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_A.line2," %c%c%c%c%c ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_A.line3," %c %c %c ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_A.line4,"  %c%c%c  ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	

	//INIT PLAYER_B
	n = sprintf_s(PLAYER_B.line0,"       ");
	n = sprintf_s(PLAYER_B.line1," %c%c%c%c%c ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_B.line2," %c %c %c ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_B.line3,"  %c%c%c  ",BLOCK_DOT,BLOCK_DOT,BLOCK_DOT);
	n = sprintf_s(PLAYER_B.line4,"  %c %c ",BLOCK_DOT,BLOCK_DOT);

	//INIT U
	n = sprintf_s(U.line0,"       ");
	n = sprintf_s(U.line1," %c   %c ",BLOCK,BLOCK);
	n = sprintf_s(U.line2," %c   %c ",BLOCK,BLOCK);
	n = sprintf_s(U.line3," %c   %c ",BLOCK,BLOCK);
	n = sprintf_s(U.line4,"  %c%c%c  ",BLOCK,BLOCK,BLOCK);

	//INIT N
	n = sprintf_s(N.line0,"       ");
	n = sprintf_s(N.line1," %c%c  %c ",BLOCK,BLOCK,BLOCK);
	n = sprintf_s(N.line2," %c %c %c ",BLOCK,BLOCK,BLOCK);
	n = sprintf_s(N.line3," %c  %c%c ",BLOCK,BLOCK,BLOCK);
	n = sprintf_s(N.line4," %c   %c ",BLOCK,BLOCK);

	//INIT I
	n = sprintf_s(I.line0,"       ");
	n = sprintf_s(I.line1," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);
	n = sprintf_s(I.line2,"   %c   ",BLOCK);
	n = sprintf_s(I.line3,"   %c   ",BLOCK);
	n = sprintf_s(I.line4," %c%c%c%c%c ",BLOCK,BLOCK,BLOCK,BLOCK,BLOCK);

	//INIT X
	n = sprintf_s(X.line0,"       ");
	n = sprintf_s(X.line1," %c   %c ",BLOCK,BLOCK);
	n = sprintf_s(X.line2,"  %c%c%c  ",BLOCK,BLOCK,BLOCK);
	n = sprintf_s(X.line3,"  %c%c%c  ",BLOCK,BLOCK,BLOCK);
	n = sprintf_s(X.line4," %c   %c ",BLOCK,BLOCK);
	

	//---------------------------------------------------------

	


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
	Block B6;

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
	sprintf_s(pyramid_line0.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0, A6.line0
		,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf_s(pyramid_line0.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1, A6.line1
		,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf_s(pyramid_line0.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2, A6.line2
		,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf_s(pyramid_line0.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3, A6.line3
		,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf_s(pyramid_line0.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4, A6.line4
		,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4);
	

	//SET UP PYRAMID LINE 1:
	sprintf_s(pyramid_line1.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0,A5.line0, PYRAMID_BLOCK.line0
		,B5.line0,BLANK.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf_s(pyramid_line1.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1,A5.line1, PYRAMID_BLOCK.line1
		,B5.line1,BLANK.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf_s(pyramid_line1.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2,A5.line2, PYRAMID_BLOCK.line2
		,B5.line2,BLANK.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf_s(pyramid_line1.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3,A5.line3, PYRAMID_BLOCK.line3
		,B5.line3,BLANK.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf_s(pyramid_line1.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4,A5.line4, PYRAMID_BLOCK.line4
		,B5.line4,BLANK.line4,BLANK.line4,BLANK.line4,BLANK.line4);
	

	//SET UP PYRAMID LINE 2:
	sprintf_s(pyramid_line2.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,BLANK.line0,A4.line0,PYRAMID_BLOCK.line0, U.line0
		,PYRAMID_BLOCK.line0,B4.line0,BLANK.line0,BLANK.line0,BLANK.line0);
	sprintf_s(pyramid_line2.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,BLANK.line1,A4.line1,PYRAMID_BLOCK.line1, U.line1
		,PYRAMID_BLOCK.line1,B4.line1,BLANK.line1,BLANK.line1,BLANK.line1);
	sprintf_s(pyramid_line2.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,BLANK.line2,A4.line2,PYRAMID_BLOCK.line2, U.line2
		,PYRAMID_BLOCK.line2,B4.line2,BLANK.line2,BLANK.line2,BLANK.line2);
	sprintf_s(pyramid_line2.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,BLANK.line3,A4.line3,PYRAMID_BLOCK.line3, U.line3
		,PYRAMID_BLOCK.line3,B4.line3,BLANK.line3,BLANK.line3,BLANK.line3);
	sprintf_s(pyramid_line2.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,BLANK.line4,A4.line4,PYRAMID_BLOCK.line4, U.line4
		,PYRAMID_BLOCK.line4,B4.line4,BLANK.line4,BLANK.line4,BLANK.line4);

	//SET UP PYRAMID LINE 3:
	sprintf_s(pyramid_line3.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,BLANK.line0,A3.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, N.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B3.line0,BLANK.line0,BLANK.line0);
	sprintf_s(pyramid_line3.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,BLANK.line1,A3.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, N.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B3.line1,BLANK.line1,BLANK.line1);
	sprintf_s(pyramid_line3.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,BLANK.line2,A3.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, N.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B3.line2,BLANK.line2,BLANK.line2);
	sprintf_s(pyramid_line3.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,BLANK.line3,A3.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, N.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B3.line3,BLANK.line3,BLANK.line3);
	sprintf_s(pyramid_line3.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,BLANK.line4,A3.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, N.line4
		,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,B3.line4,BLANK.line4,BLANK.line4);
	
	//SET UP PYRAMID LINE 4:
	sprintf_s(pyramid_line4.line0,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line0,A2.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, I.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B2.line0,BLANK.line0);
	sprintf_s(pyramid_line4.line1,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line1,A2.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, I.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B2.line1,BLANK.line1);
	sprintf_s(pyramid_line4.line2,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line2,A2.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, I.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B2.line2,BLANK.line2);
	sprintf_s(pyramid_line4.line3,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line3,A2.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, I.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B2.line3,BLANK.line3);
	sprintf_s(pyramid_line4.line4,"%s%s%s%s%s%s%s%s%s%s%s",BLANK.line4,A2.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, I.line4
		,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,B2.line4,BLANK.line4);

	//SET UP PYRAMID LINE 5:
	sprintf_s(pyramid_line5.line0,"%s%s%s%s%s%s%s%s%s%s%s",A1.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0, X.line0
		,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,PYRAMID_BLOCK.line0,B1.line0);
	sprintf_s(pyramid_line5.line1,"%s%s%s%s%s%s%s%s%s%s%s",A1.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1, X.line1
		,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,PYRAMID_BLOCK.line1,B1.line1);
	sprintf_s(pyramid_line5.line2,"%s%s%s%s%s%s%s%s%s%s%s",A1.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2, X.line2
		,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,PYRAMID_BLOCK.line2,B1.line2);
	sprintf_s(pyramid_line5.line3,"%s%s%s%s%s%s%s%s%s%s%s",A1.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3, X.line3
		,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,PYRAMID_BLOCK.line3,B1.line3);
	sprintf_s(pyramid_line5.line4,"%s%s%s%s%s%s%s%s%s%s%s",A1.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4,PYRAMID_BLOCK.line4, X.line4
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
	sprintf_s(A->line0, "%s", B.line0);
	sprintf_s(A->line1, "%s", B.line1);
	sprintf_s(A->line2, "%s", B.line2);
	sprintf_s(A->line3, "%s", B.line3);
	sprintf_s(A->line4, "%s", B.line4);
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

