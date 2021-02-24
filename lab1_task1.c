/*
* 19/02/21
* Artyom Zamoyskiy
* Task:
* RU: 1. Найти и вывести 2 старших бита беззнакового числа.
*/

struct byte { //поле бит
    unsigned a0: 1;
    unsigned a1: 1;
    unsigned a2: 1;
    unsigned a3: 1;
    unsigned a4: 1;
    unsigned a5: 1;
    unsigned a6: 1;
    unsigned a7: 1;
};
 
union Byte {
    unsigned char value; //связываем число value с битовым полем 
    struct byte bitfield;
};
 
void main() {
    union Byte x;
    printf("Type number - ");
    scanf("%s", &x.value);
    printf("%d %d", x.bitfield.a0, x.bitfield.a1);
}