#include"string.h"


int slen(char *path){
	int i = 0;
	while(path[i] != 0){
		i++;
	}
	return i;
}
void stok(char *path,char stok_path[10][10][MAX_PATH]){
	int g = 0;
	int j = 0;
	int l = 0;
	for(int i = 0; i < slen(path); i++){
		if((path[i] == 92 ) && (path[i+1] == 92)){
			l = 0;
			for(i = i+2; (i < slen(path)) &&	 ((path[i] != 92 ) || (path[i+1] != 92)); i++){
	
				
				if(path[i] == 92){
					j++;
					
					l = 0;
				for(i = i+1;( i < slen(path))  && (path[i] != '+') && (path[i] == '.');i++) {
					
					if(path[i] == 92) {
						j++;
						i++;
						l = 0;
						break;
					}
					stok_path[g][j][l] = path[i];
					l++;
				}
			}
				if(path[i] == '.'){
					j++;
					
					l = 0;
				for(i = i+1;( i < slen(path))  && (path[i] != '+') && (path[i] == 92) ;i++) {
					
					if(path[i] == '.') {
						j++;
						i++;
						l = 0;
						break;
					}
					stok_path[g][j][l] = path[i];
					l++;
				}
				}
				if(path[i] == '+'){
					g++;
					j = 0;
					break;
				}
				stok_path[g][j][l] = path[i];
				 l++;
			}
		}
	}
}

int sspn(char word){
	int flag_w = 0,flag_n = 0;
	
	if (('A' <= word) && ('Z' >= word))  flag_w = 1; 
	if (('a' <= word) && ('z' >= word))  flag_w = 1; 
	if (('0' <= word) && ('9' >= word)) flag_n = 1;

	if(flag_w == 1) return 1;
	if(flag_n == 1) return 2;
	return 0;
}
int scmp(char *path,char *npath){
	int sum_p = 0, sum_n = 0;
	int ogr =  (sizeof(npath)/ sizeof(npath[0]));
	for(int i = 0; i < (sizeof(path)/ sizeof(path[0])) && ogr > i ;  i++ ){
		if(path[i] >= npath[i]) sum_p++;
		if(npath[i]  >= path[i]) sum_n++;
	}
	if(sum_p > sum_n) return 1;
	if(sum_p == sum_n) return 0;
	if(sum_p < sum_n) return -1;
	
}
//void scpy(char *path,char* nPath);
