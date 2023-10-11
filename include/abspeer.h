#ifndef absp
#define absp
#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
//#include <stdio.h>  //printf()
//#include <unistd.h>  //close(), fread()
#include "client.h"
#include "server.h"
#define MAXLINE 1024

/**
 *\file abspeer.h
 *\author Денис Вергун
 *\brief Файл содержит описание наследуемого абстрактного класса 
 *\version
 *\date 27-06-2023
 *
 *
 */






///\brief Абстрактный узел связи. 
/**
Вводим определение узла связи Peer.
Создает интерфейс для наследующих классов клиета и сервера.
Содержит виртуальные функции создания сокета, соединения, основного цикла.
*/
class Peer{
        public:
        Peer()=default;///<Конструктор без параметров  \param void
	virtual void createSocket_()=0;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        virtual void connectInit_(const char* addr)=0;///<Запись в переменную addres и подготовка соединения \param void  \return void
        //void selinit();///<\param void  \return void
        //void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void
        /**
	 \brief Конструктор с параметрами
	 
	 \param _sock
	 \param _addres
	 \return конструкторы ничего не возвращают
	 */

	//Peer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        //int sock;///<Переменная для хранения сокета
	//struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        //char buffer[MAXLINE]={0};///<Хранит сообщение
        //fd_set read_fd={0};///<Массив дескрапторов для храненния сокета

        

};

class Client_:public Peer, public Client{
        public:  
        Client_(){};
        void createSocket_()override{createSocket();};
        void connectInit_(const char* addr)override{connectInit(addr);};
        void selinit();///<\param void  \return void
        void sel();///<\param void  \return void
        void conn();///<\param void  \return void
        void sendmes();///<\param void  \return void



};

class Server_:public Peer, public Server{
        public:  
        Server_(){};
        void createSocket_()override{createSocket();};
	void connectInit_(const char* addr)override{connectInit(addr);};
        void selinit();///<\param void  \return void
        void sel();///<\param void  \return void
        void conn();///<\param void  \return void
        void sendmes();///<\param void  \return void



};





#endif
