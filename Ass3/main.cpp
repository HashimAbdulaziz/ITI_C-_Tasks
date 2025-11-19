#include <iostream>

int str_len(char str[]){
  int cnt = 0;
  for(int i = 0; str[i] != '\0'; i++){
    cnt++;
  }
  return cnt;
}


int str_cmp(char str1[], char str2[]){
    if(str_len(str1) > str_len(str2)){
        return 2;
    }
    else if(str_len(str1) < str_len(str2)){
        return -2;
    }
    else{
        for(int i = 0; str2[i] != '\0'; i++){
            if(str1[i] != str2[i]){
                return 0;
            }
        }
    }

    return 1;

}

void tolower(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
}

void toupper(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
}

int str_concat(char str1[], char str2[], int str1_len){
    int free = str1_len - str_len(str1);
    int n1 = str_len(str1);

    if(free > str_len(str2)){
         for(int i = 0; i < free-1; i++){
            str1[i+n1] = str2[i];
        }
        str1[free-1] = '\0';
        return 0;
    }


    return 1;
}



using namespace std;

int main()
{
    char s[6] = {'a', 'B', 'c', '\0', '\0', '\0'};
    char s2[] = "Hello, World";
    char s3[] = "Hello, World";
    int len = str_len(s2);
    cout << len << endl;
    tolower(s2);
    cout << s2 << endl;
    toupper(s2);
    cout << s2 << endl;
    cout << str_cmp(s3, s2) << endl;

    str_concat(s, s2, 6);
    cout << s << endl;


    //printf("%c", c+32);
    return 0;
}
