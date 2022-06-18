int HUNGRY;
int eat(){
int i=5;
HUNGRY=i;
i--;
}


int main(){

while(HUNGRY){
eat();

}

return 0;
}
