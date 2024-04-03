#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i; 
char plain_text[100]; 
int primality(long int); 
void choose_e(); 
long int mul_inverse(long int); 
void encrypt(); 
void decrypt(); 
void main() { 
printf("\nEnter First Prime Number : "); 
scanf("%d",&p); 
flag=primality(p); 
if(flag==0) { 
printf("\nNumber is not Prime....\n"); 
getch(); 
exit(1); 
} 
printf("\nEnter Second Prime Number : "); 
scanf("%d",&q); 
flag=primality(q); 
if(flag==0||p==q) { 
printf("\nEither number is not prime or both are equal....\n"); 
getch(); 
exit(1); 
} 
printf("\nEnter Plain Text : "); 
fflush(stdin); 
scanf("%[^\n]s",plain_text); 
for (i=0;plain_text[i]!=’\0’;i++) 
m[i]=plain_text[i]; 
n=p*q; 
t=(p-1)*(q-1); 
choose_e(); 
printf("\nPossible E and D values are \n"); 
for (i=0;i<j-1;i++) 
printf("\n%ld\t%ld",e[i],d[i]); 
encrypt(); 
decrypt(); 
getch(); 
} 
int primality(long int pr) { 
int i; 
j=sqrt(pr); 
for (i=2;i<=j;i++) { 
if(pr%i==0) 
return 0; 
} 
return 1; 
} 
void choose_e() { 
int k=0; 
for (i=2;i<t;i++) { 
if(t%i==0) 
continue; 
flag=primality(i); 
if(flag==1 && i!=p && i!=q) { 
e[k]=i; 
flag=mul_inverse(e[k]); 
if(flag>0) { 
d[k]=flag; 
k++; 
} 
if(k==99) 
break; 
} 
} 
} 
long int mul_inverse(long int x) { 
long int k=1; 
while(1) { 
k=k+t; 
if(k%x==0) 
return(k/x); 
} 
} 
void encrypt() { 
long int pt,ct,key=e[0],k,len; 
i=0; 
len=strlen(plain_text); 
while(i!=len) { 
pt=m[i]; 
pt=pt-96; 
k=1; 
for (j=0;j<key;j++) { 
k=k*pt; 
k=k%n; 
} 
temp[i]=k; 
ct=k+96; 
en[i]=ct; 
i++; 
} 
en[i]=-1; 
printf("\nEncrypted Message is \n"); 
for (i=0;en[i]!=-1;i++) 
printf("%c",en[i]); 
} 
void decrypt() { 
long int pt,ct,key=d[0],k; 
i=0; 
while(en[i]!=-1) { 
ct=temp[i]; 
k=1; 
for (j=0;j<key;j++) { 
k=k*ct; 
k=k%n; 
} 
pt=k+96; 
m[i]=pt; 
i++; 
} 
m[i]=-1; 
printf("\nDecrypted Message is \n"); 
for (i=0;m[i]!=-1;i++) 
printf("%c",m[i]); 
}