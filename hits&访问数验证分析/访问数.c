#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
char buf[50];
int conut=0;
int num=0;//poi数量 
typedef struct poi{ 
	char name[60];
	int time;
}m;
m t[5000];
void clearstr(){//清空字符串 
	int i=0;
	while(buf[i++]!='\0'){
		buf[i-1]='\0';
	}
}
int search(){//driver的hub值（发射） 
	int i=0;
	for(i=0;i<num;i++){
		if(strcmp(buf,t[i].name)==0){
			return i;
		}
	}
	return i;
}

int main(){
	char c;
	int i=0,j=0,k=0;
	int tmp;
	FILE *fp,*fp1;
	fp=fopen("splited0205_all_pair.txt","r");
	fp1=fopen("output1.txt","w");
	while(fscanf(fp,"%c",&c)!=EOF){
		if(c!='\''&&c!=' '){
	    	buf[j]=c;
		}
		if(buf[j]==','){
			conut++;
			buf[j]='\0';
		    if(conut==16){
				tmp=search();
				if(tmp==num){//没查到 
					strcpy(t[tmp].name,buf);
					t[tmp].time=1;
					num++;
				}else{//查到了 
					t[tmp].time++;
				}
			}
			clearstr();
            j=0;
		}else if(buf[j]=='\n'){
			conut=0;
			buf[j]='\0';
			clearstr();
			j=0;
		}else{
			if(c!='\''&&c!=' '){
				j++;
			}
		}
	}
	printf("%d\n",num);
	for(i=0;i<num;i++){
		fprintf(fp1,"%s %d\n",t[i].name,t[i].time);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}
