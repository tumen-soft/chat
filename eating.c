int eat(int HUNGRY){
return HUNGRY-1;
}
int main(){
int HUNGRY=5;
while(HUNGRY)HUNGRY=eat(HUNGRY);
return 0;
}
