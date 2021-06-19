#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
char buf[50];
int num=0;//poi数量 
int n=0;
typedef struct poi{ 
	char name[60];
}m;
m t[4000];
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
	fp=fopen("test_4.txt","r");
	fp1=fopen("0205_4.txt","r");
	while(fscanf(fp,"%c",&c)!=EOF){
		buf[j]=c;
		if(buf[j]=='\n'){
			buf[j]='\0';
			strcpy(t[num].name,buf);
			num++;
			clearstr();
            j=0;
		}else{
			j++;
		}
	}
	printf("%d\n",num);
	while(fscanf(fp1,"%c",&c)!=EOF){
		buf[j]=c;
		if(buf[j]=='\n'){
			buf[j]='\0';
		    tmp=search();
			if(tmp==num){//没查到 
				n++;
			}
			clearstr();
            j=0;
		}else{
			j++;
		}
	}
	printf("%d\n",n);
	fclose(fp);
	fclose(fp1);
	return 0;
} 
