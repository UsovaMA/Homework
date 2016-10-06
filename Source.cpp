#include <stdio.h>

struct CNode {
	char s;
	CNode* next;
};

void Add (CNode **node, char s) {
		CNode *a=new CNode;
		a->next=*node;
		a->s=s;
		*node=a;
}

void Delete(CNode** l) {
	CNode *a=*l;
	CNode *b=0;
	while (a->next!=0) {
		b=a;
		a=a->next;
	};
	if (b==0) 
		*l=0;
	else
		b->next=0;
}


bool isCorrect (char *string) {
	CNode *list=0;
	int i=0;

	while (string[i]!=0) {
		if ((string[i]=='(')||(string[i]=='{')||(string[i]=='[')) 
			Add(&list,string[i]);
		else 
		{
			if (list==0) 
				return false; 
			if (((string[i]=='}')&&(list->s!='{'))||((string[i]==')')&&(list->s!='('))||((string[i]==']')&&(list->s!='[')))
					return false;
			list=list->next;
		};
		i++;
	};
	return (list==0);
}

void tests(char *str)
{
	bool p;
	p=isCorrect(str);
	if (p==true) 
		printf("%s true\n", str);
	else
		printf("%s false\n", str);
}

int main()
{
	char str1[7]="({[]})";
	char str2[7]="{{)){}";       //false
	char str3[9]="((){}[])";
	char str4[9]=")){}{}[]";     //false
	char str5[1]="";
	char str6[6]="{}[]]";        //false
	char str7[11]="{}[{(){}}]"; 
	char str8[8]="{}{}[{]";      //false
	char str9[11]="{{[()()]}}"; 
	char str10[6]="{(})";        //false
	tests(str1);
	tests(str2);
	tests(str3);
	tests(str4);
	tests(str5);
	tests(str6);
	tests(str7);
	tests(str8);
	tests(str9);
	tests(str10);
	return 0;
}
