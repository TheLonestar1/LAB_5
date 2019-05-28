#include"string.h"
#include"path.h"

int main(){
	char path[MAX_PATH] = {0};
	char npath[MAX_PATH] = {0};
	input(path);
	int a = 0;
	int i = 0;
	int j = 0;
	for(int o = 0; o < MAX_PATH; o++) {
		if(path[o] == '+') a++; 
	}
	a++;
	for(int g = 0; g < a; g++){
		char path_cut[MAX_PATH] = {0};
		i++;
		for(; i < MAX_PATH ; i++ ) {
			if(path[i] == '+'){
				i++;
				break;
			}
		}
		int o = 0;
		for(; (j < i) && (path [j] != 0); j++){
			path_cut[o] = path[j];
			printf("%c", path_cut[o] ); 	
			o++;
		}
		if(check(path_cut) == 0){
			printf(" It's correct adress!\n");
			process(path_cut,npath);
		} 
		else printf(" It's incorrect adress!\n"); 
	}
	
	output(npath);
	system("PAUSE");
	return 0;
}
