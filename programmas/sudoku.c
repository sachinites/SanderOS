#include <system.h>

unsigned char rA[9];
unsigned char rB[9];
unsigned char rC[9];
unsigned char rD[9];
unsigned char rE[9];
unsigned char rF[9];
unsigned char rG[9];
unsigned char rH[9];
unsigned char rI[9];
void main(){
	int selx = 0;
	int sely = 5;
	//again:
		cls();
		printf("\[47m\[30mSudoku                         SanderOS\[40m\[37m\n");
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==1?'>':' '),rA[0],rA[1],rA[2],rA[3],rA[4],rA[5],rA[6],rA[7],rA[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==2?'>':' '),rB[0],rB[1],rB[2],rB[3],rB[4],rB[5],rB[6],rB[7],rB[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==3?'>':' '),rC[0],rC[1],rC[2],rC[3],rC[4],rC[5],rC[6],rC[7],rC[8]);
		printf(" +===+===+===++===+===+===++===+===+===+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==4?'>':' '),rD[0],rD[1],rD[2],rD[3],rD[4],rD[5],rD[6],rD[7],rD[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==5?'>':' '),rE[0],rE[1],rE[2],rE[3],rE[4],rE[5],rE[6],rE[7],rE[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==6?'>':' '),rF[0],rF[1],rF[2],rF[3],rF[4],rF[5],rF[6],rF[7],rF[8]);
		printf(" +===+===+===++===+===+===++===+===+===+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==7?'>':' '),rG[0],rG[1],rG[2],rG[3],rG[4],rG[5],rG[6],rG[7],rG[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==8?'>':' '),rH[0],rH[1],rH[2],rH[3],rH[4],rH[5],rH[6],rH[7],rH[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		printf("%c|%x|%x|%x||%x|%x|%x||%x|%x|%x|\n",(sely==9?'>':' '),rI[0],rI[1],rI[2],rI[3],rI[4],rI[5],rI[6],rI[7],rI[8]);
		printf(" +---+---+---++---+---+---++---+---+---+\n");
		unsigned volatile char watnu = getc();
		if(watnu=='+'){
			sely--;
		}else if(watnu=='-'){
			sely++;
		}
		//goto again;
	while(1){};
}
