/**
 *\file chat.h
 *\author ИП Вергун Д.Н.
 *\brief Файл содержит описание наследуемого абстрактного класса 
 *\version
 *\date 27-06-2023
 *
 *
 */

#ifndef Node
#define Node
#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
//#include <stdio.h>  //printf()
//#include <unistd.h>  //close(), fread()
#define MAXLINE 1024
#include <vector>


#ifdef DEBUG
#  define Trace(x)  {fprintf x ; fflush(stderr); fflush(stdout);}
#else
#  define Trace(x);
#endif

///Клиент и сервер это узлы т.к. обладают всеми свойствами узлов сетевых соединений линукс:
//сокет
//адрес
// идр.
//namespace абстракция{

class F{//Этот класс абстракция сетевых даннных
	public:
        F(){};
	int sock;
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
        auto _valread() -> int& {return valread;}; 
	private:
	int valread;
        int new_socket, client_socket[30], max_clients=30, activity, i, max_sd, sd;
        std::vector<std::pair<int, char*>> nicknames;       
};

class А{///<Интерфейсный класс
        public:
        А()=default;///<Конструктор без параметров  \param void
        virtual void соединение()=0;
	//virtual void отправка()=0;
	//virtual void прием()=0;
	virtual void создатьСокет()=0;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        //virtual void connectInit(const char* addr)=0;///<Запись в переменную addres и подготовка соединения \param void  \return void
        virtual void connectInit()=0;///\param void  \return void
        virtual void selinit()=0;///<\param void  \return void
        virtual void sel()=0;///<\param void  \return void
        virtual void conn()=0;///<\param void  \return void
        virtual void sendmes()=0;///<\param void  \return void

};

class Тест:А{




};

//}









#endif
