#include <stdio.h>

struct CNode {
  char s;
  CNode* next;
};

void Add(CNode **node, char s) {
  CNode *a = new CNode;
  a->next = *node;
  a->s = s;
  *node = a;
}

void Delete(CNode** l) {
  CNode *a = *l;
  *l = (*l)->next;
  delete a;
}


bool isCorrect(char *str) {
  CNode *list = 0;
  int i = 0;

  while (str[i] != 0) {
    if ((str[i] == '(') || (str[i] == '{') || (str[i] == '[')) {
      Add(&list, str[i]);
    } else {
      if (list == 0)
        return false;
      if ((str[i] == '}') && (list->s != '{'))
        return false;
      if ((str[i] == ')') && (list->s != '('))
        return false;
      if ((str[i] == ']') && (list->s != '['))
        return false;
      Delete(&list);
    }
    i++;
  }
  return (list == 0);
}

void tests(char *str) {
  bool p;
  p = isCorrect(str);
  if (p == true)
    printf("%s true\n", str);
  else
    printf("%s false\n", str);
}

int main() {
  char str1[7] = "({[]})";
  char str2[7] = "{{)){}";       // false
  char str3[9] = "((){}[])";
  char str4[9] = ")){}{}[]";     // false
  char str5[1] = "";
  char str6[6] = "{}[]]";        // false
  char str7[11] = "{}[{(){}}]";
  char str8[8] = "{}{}[{]";      // false
  char str9[11] = "{{[()()]}}";
  char str10[6] = "{(})";        // false
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
