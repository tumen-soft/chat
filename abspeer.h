#ifndef abs
#define abs
#include <arpa/inet.h>  //inet_addr define
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <ext/stdio_filebuf.h>
#include <stdio.h>  //printf()
#include <unistd.h>  //close(), fread()
#define MAXLINE 1024

/**
 *\file abspeer.h
 *\author Денис Вергун
 *\brief Файл содержит описание наследуемого класса 
 *\version
 *\date 27-06-2023
 *
 *
 */






/**
\brief Абстрактный узел связи. 

Создает интерфейс для наследующих классов клиета и сервера.
Содержит виртуальные функции создания сокета, соединения, основного цикла.
*/
class Peer{
        public:
        Peer()=default;///<Конструктор без параметров  \param void
        virtual void createSocket()=0;///<Прообраз функции создания сокета для инициализации клиента/сервера
        virtual void init1()=0;
        virtual void selinit()=0;
        virtual void sel()=0;
        virtual void conn()=0;
        virtual void sendmes()=0;
        /**
	 \brief Конструктор с параметрами
	 
	 \param _sock
	 \param _addres
	 */

	Peer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        int sock;///<Переменная для хранения сокета
	struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообшение
        fd_set read_fd={0};///<Массив дескрапторов

        

};
#endif
