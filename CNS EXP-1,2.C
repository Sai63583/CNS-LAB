#include<stdio.h>
char *Xorwith0(char *str){
int i=0;
while(*(str+i)){
	*(str+i)=*(str+i)^0;
	i++;
}
return str;
}
char *Andwith0(char *str){
int i=0;
while(*(str+i)){
	*(str+i)=*(str+i)&0;
	i++;
}
return str;
}
int main(){
	char pt[100];
	printf("enter a string:");
	scanf("%[^\n]",pt);
	printf("\n After xor ed ,the encoded data is");
	puts(Xorwith0(pt));
	printf("\n After and ed,the encoded data is:");
	puts(Andwith0(pt));
	return 0;
}