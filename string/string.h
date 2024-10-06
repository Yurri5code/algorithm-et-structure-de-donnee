#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

typedef char* string1;

void initStr(string1 st,unsigned n);
void writeToStr(string1,char* s);
void writeFromStr(char* s,string1 st);
void inputStr(string1 st);
void InitStr(string1 st, unsigned n);
void WriteToStr(string1 st, char *s);
void WriteFromStr(char *s, string1 st);
void InputStr(string1 st);
void OutputStr(string1 st);
int Comp(string1 s1, string1 s2);
void Delete(string1 s, unsigned index, unsigned Count);
void Insert(string1 Subs, string1 s, unsigned Index);
void Concat(string1 s1, string1 s2, string1 srez);
void Copy(string1 s, unsigned Index, unsigned Count,  string1 Subs);
unsigned Length(string1 s);
unsigned Pos(string1 SubS, string1 s);
void DoneStr(string1 s);
int StrError;

#endif // STRING_H_INCLUDED
