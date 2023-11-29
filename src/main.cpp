/**
 *@mainpage Постовляемое ПО: Приложение для обмена сообщениями по сети: сетевой асинхронный мультиклиентский чат.
 * ГОСТ Р 51904-2002
 *
 * 5.3.7 Анализ ПО при верификации системы:
 * Скрипт configure осуществляет проверку системы на предмет зависимостей приложения. 
 * 
 * верификация/тестирование ПО: команда make check выполняет тестирование ПО определенной полноты покрытия.
 * 
 * безопасность системы: приложение можен запускаться пользователем, не обладающим правами администратора.
 *
 * Использование:  
 *
 * git clone https://github.com/blueagle-so/chat 
 *
 * cd  chat
 *
 * mkdir build;cd build;../configure --prefix=/usr;make;make install
 *
 * 8.5.1 модульное тестирование ПО.
 * make check
 *
 * chat
 */
//module;
///import message;
//#ifndef main
//#define main
//export module uno;
int main_(void);
//#include "message.h"
#include "client.h"
int main(void){
main_();
}
//#endif
