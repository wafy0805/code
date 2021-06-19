#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int conut1=0,conut2=0,conut=0;
double max_driver,min_driver,max_poi,min_poi;
int n=0;//迭代次数 
int w1,w2;
double g1,g2;
int tmp1,tmp2;
char buf[60];
void QuickSort(int left,int right);
void swap(int i, int j);
typedef struct driver{ 
	char id[60];
	double weight;
	double hub;
}s;
s t1[500000];
typedef struct poi{ 
	char name[60];
	double weight;
	double authority;
}m;
m t2[6000];
void clearstr(){//清空字符串 
	int i=0;
	while(buf[i++]!='\0'){
		buf[i-1]='\0';
	}
}
void QuickSort(int left,int right){
    int i, last;
    if(left<right){
        last=left; 
        for(i=left+1;i<=right;i++){
        	//time++;
        	if(t2[i].weight<t2[left].weight){
        		swap(++last,i); 
			}        
		}
        swap(left,last);
        QuickSort(left,last-1); 
        QuickSort(last+1,right);   
    }
}
void swap(int i, int j){
        m tmp;
        tmp=t2[i]; 
		t2[i]=t2[j]; 
		t2[j]=tmp;
 }
double search1(){//driver的hub值（发射） 
	int i=0;
	for(i=0;i<conut1;i++){
		if(strcmp(buf,t1[i].id)==0){
			w1=i;
			return t1[i].weight;
		}
	}
	return 0;
}
double search2(){//poi的authority值（接受） 
	int i=0;
	for(i=0;i<conut2;i++){
		if(strcmp(buf,t2[i].name)==0){
			w2=i;
			return t2[i].weight;
		}
	}
	return 0;
}
double max1(){
	int i;
	double M=0;
	for(i=0;i<conut1;i++){
		if(t1[i].weight>=M){
			M=t1[i].weight;
		}
	}
	return M;
}
double max2(){
	int i;
	double M=0;
	for(i=0;i<conut2;i++){
		if(t2[i].weight>=M){
			M=t2[i].weight;
		}
	}
	return M;
}
double min1(){
	int i;
	double M=0;
	for(i=0;i<conut1;i++){
		if(t1[i].weight<=M){
			M=t1[i].weight;
		}
	}
	return M;
}
double min2(){
	int i;
	double M=0;
	for(i=0;i<conut2;i++){
		if(t2[i].weight<=M){
			M=t2[i].weight;
		}
	}
	return M;
}
int find1(){//driver的hub值（发射） 
	int i=0;
	for(i=0;i<conut1;i++){
		if(strcmp(buf,t1[i].id)==0){
			return i;
		}
	}
	return i;
}
int find2(){//driver的hub值（发射） 
	int i=0;
	for(i=0;i<conut2;i++){
		if(strcmp(buf,t2[i].name)==0){
			return i;
		}
	}
	return i;
}

int main(){
	char c;
	int i=0,j=0,k=0;
	FILE *fp,*fp1;
	//存取好所有司机和poi的权值 
	//fp=fopen("driver_weight.txt","r");
	//fp1=fopen("poi_weight.txt","r");
	fp=fopen("splited0105_all_pair.txt","r");
	fp1=fopen("output1.txt","w");
	while(fscanf(fp,"%c",&c)!=EOF){
    	    if(c!='\''&&c!=' '){
	    	    buf[j]=c;
		    }
    	    if(buf[j]==','){
    		    conut++;
    		    buf[j]='\0';
    		    //printf("here\n");
    		    if(conut==1){
    			    //查找司机ID 		    
    			    tmp1=find1();
    			    if(tmp1==conut1){//没查到 
					    strcpy(t1[conut1].id,buf);
					    t1[conut1].weight=1.0;
			            t1[conut1].hub=0;
			            conut1++;
				    }
			    }else if(conut==16){
				    //查找POI的ID 
				    tmp2=find2();
    			    if(tmp2==conut2){//没查到 
					    strcpy(t2[conut2].name,buf);
					    t2[conut2].weight=1.0;
			            t2[conut2].authority=0;
			            conut2++;
				    }	    
			    }
				clearstr();
			    j=0;
		    }else if(buf[j]=='\n'){		
			    buf[j]='\0';
		        conut=0;
			    clearstr();
			    j=0;
		    }else{
			    if(c!='\''&&c!=' '){
				    j++;
			    }
		    }
	    }
	    fseek(fp,0,SEEK_SET);//将文件指针置顶进行迭代
    printf("%d %d\n",conut1,conut2);
	while(n<=20){
		while(fscanf(fp,"%c",&c)!=EOF){
    	    if(c!='\''&&c!=' '){
	    	    buf[j]=c;
		    }
    	    if(buf[j]==','){
    		    conut++;
    		    buf[j]='\0';
    		    if(conut==1){
    			    //查找司机ID 
    			    g1=search1();
			    }else if(conut==16){
				    //查找POI的ID 
				    g2=search2();
			    }
				clearstr();
			    j=0;
		    }else if(buf[j]=='\n'){		
			    buf[j]='\0';
			    t1[w1].hub+=g2;
			    t2[w2].authority+=g1;
		        conut=0;
			    clearstr();
			    j=0;
			    
		    }else{
			    if(c!='\''&&c!=' '){
				    j++;
			    }
		    }
	    }
	    printf("%s %.20lf %.20lf\n",t2[0].name,t2[0].authority,t2[0].weight);
	    for(i=0;i<conut1;i++){
		    t1[i].weight=t1[i].hub;
		    t1[i].hub=0;
	    }
	    for(i=0;i<conut2;i++){
		    t2[i].weight=t2[i].authority;
		    t2[i].authority=0;
	    }
	    //对权值标准化归一 
	    max_driver=max1();
	    max_poi=max2();
	    min_driver=min1();
	    min_poi=min2();
	    for(i=0;i<conut1;i++){
		    t1[i].weight=(t1[i].weight-min_driver)/(max_driver-min_driver);
	    }
	    for(i=0;i<conut2;i++){
		    t2[i].weight=(t2[i].weight-min_poi)/(max_poi-min_poi);
	    }
	    n++;//迭代一次完成 
	    fseek(fp,0,SEEK_SET);//将文件指针置顶进行迭代
	}
	QuickSort(0,conut2-1);
    for(i=0;i<conut2;i++){
    	fprintf(fp1,"%s %.20lf\n",t2[i].name,t2[i].weight);
		//fprintf(fp3,"%s%c%s%c\n",t2[i].lon,',',t2[i].lat,',');
	}
    printf("%s %.30lf %.30lf\n",t2[0].name,t2[0].authority,t2[0].weight);
    
	fclose(fp);
	fclose(fp1);
	//fclose(fp2);
	//fclose(fp3);
	return 0;
}
