/**
 *@mainpage сетевой асинхронный мультиклиентский чат.
 * сделано по ГОСТ Р 51904-2002
 *
 * пункт 5.3.7 Анализ при верификации системы:
 * Скрипт configure осуществляет проверку системы на предмет зависимостей приложения. 
 * 
 *
 * Использование:  
 *
 * git clone https://github.com/inc-rement/chat 
 *
 * cd  chat
 *
 * mkdir build;cd build;../configure --prefix=/usr;make;make install
 *
 * пункт 8.5.1 модульное тестирование.
 * make check
 *
 * chat
 */
int main_(void);
#include "client.h"
int main(void){
#ifdef DEBUG
std::cout<<"\033[1;34mtest\033[0m"<<std::endl;
#endif
	
main_();
}
