#include <system.h>

void kernel_main(){
	if(0){
		printf("\n                                                                       ");
		printf("\n                _/ _/ _/         _/ _/ _/          _/ _/ _/                 ");
		printf("\n             _/               _/         _/     _/                          ");
		printf("\n               _/                                 _/                        ");
		printf("\n                  _/        _/          _/           _/                     ");
		printf("\n                     _/                                 _/                  ");
		printf("\n                     _/    _/         _/                _/                  ");
		printf("\n                  _/        _/     _/                _/                     ");
		printf("\n           _/ _/               _/             _/ _/                         ");
		printf("\n                                                                       ");
		printf("                  S A N D E R S L A N D O  O P E R A T I N G   S Y S T E M   \n");
		printf("             An 32 bit operatingsystem created by Alexandros de Regt\n");
		printf("             Loading services ...\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	}
	setupIDT();
	detectDevices();
	initialiseKeyboard();
	cls();
	initTasking();
	createTask( 1,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
	createTask( 2,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 3,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 4,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 5,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 6,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 7,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 8,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask( 9,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask(10,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	createTask(11,loadExecutable((unsigned char*)"/PROGRAMS/INIT.SEF"));
//	yield(1);
	mouselib_install_driver();
	for(;;);
}

