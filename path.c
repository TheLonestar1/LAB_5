#include"path.h"
#include"string.h"

void input(char *path){
	printf("Enter beginner path: ");
	scanf("%s",&path[0]);
}
int  check(char *path){
	int g = 0;
	int j = 0;
	char stok_path[10][10][MAX_PATH] = {0};
	if(slen(path) >= MAX_PATH) return 1;
	stok(path,&stok_path);
	if(stok_path[0][0][0] == 0) return 2;
/*	for(int i = 0; i < 10 ; i++){
		if(stok_path[i][0][0] == 0) break;
		for(int o = 0; o < 10; o++){
			if(stok_path[i][o][0] == 0) break;
			for(int a = 0; a < MAX_PATH; a++){
				if(stok_path[i][o][a] == 0) break;
				printf("%c", stok_path[i][o][a]);
			}
			printf(" ");
			
		}
		printf("\n");
	}*/
	int domen = 0,ip = 1;
//	printf("check on domen or IP adress: ");
	for(int i = 0; i < 4 ; i++){
		if(stok_path[0][i][0] == 0) break;
		for(int a = 0; a < MAX_PATH; a++){
				if(stok_path[0][i][a] == 0) break;
				if(sspn(stok_path[0][i][a]) == 2) {
					domen = 0;
				}
				else{
					domen = 1;
				} 
		}
		if(domen == 1) break;
	}
	int flag_in = 0;
	char ex[] = "com";
	char ex1[] = "fr";
	switch(domen){
		case 1:
			
				if((scmp(stok_path[0][1], ex) == 0) || (scmp(stok_path[0][1], ex1) == 0)) {
				//	printf("OK!!!");
					return 0;
				}
				else{
			//		printf("Invalid domen or Ip-adress");	
					return 1;
				}
		case 0:
			for(int i = 0; i < 4 ; i++){
				if(stok_path[0][i][0] == 0) break;
				for(int a = 0; a < 4; a++){
					if(stok_path[0][i][a] == 0) break;
					if(a == 3){
				//		printf("Invalid Ip many simvol");
						return 1;
					}
					if(flag_in == 1) {
					
					//	printf("Invalid IP in razryad %d 	", i+1);
						return 1;
					}
					if((a == 0) && (stok_path[0][i][a] < '3') && (stok_path[0][i][a] > '0') || ( (a == 0) && (stok_path[0][i][a+1] == 0) && (stok_path[0][i][a+2] == 0) && (stok_path[0][i][a] < '9') && (stok_path[0][i][a] > '0') )) {
						flag_in = 0;
						break;
					}
					else {
						flag_in = 1;
					}
					if((a == 1) && (stok_path[0][i][a] < '6') && (stok_path[0][i][a] > '0') || ((a == 1) && (stok_path[0][i][a+1] == 0) && (stok_path[0][i][a] < '9') && (stok_path[0][i][a] > '0') )) {
						flag_in = 0;
						break;
					}
					else {
						flag_in = 1;
					}
					if((a == 2) && (stok_path[0][i][a] < '6') && (stok_path[0][i][a] > '0') || ( (a == 2) && (stok_path[0][i][a - 2] == '1')  && (stok_path[0][i][a] < '9') && (stok_path[0][i][a] > '0') )){
						flag_in = 0;
						break;
					}
					else {
						flag_in = 1;
					}
					
				}
			}
			if(flag_in == 0);
			else{
		
				return 1;
			}
	}
	
	return 0;
	}
	
void process(char *path,char *npath){
	int i = 0;
	char exap[5] = "http:";
	for(; (i < MAX_PATH) && (npath[i] != 0); i++);
	for(int o = 0; o < 5; o++){
		npath[i] = exap[o];
		i++;
	}
	for(int o = 0;(i < MAX_PATH) && (path[o] != 0); i++ ){
		if(path[o] == 92) npath[i] = '/';
		else npath[i] = path[o];
		o++;
	}
	
	}
	

void output(char *path){
	printf("\nnew paths: " );
	for(int i = 0; (i < MAX_PATH) && (path[i] != 0); i++){
		printf("%c",path[i]);
	}
}
