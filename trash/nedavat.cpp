#define вывод std::cout
#define конец std::endl
#define синий "\033[1;34m"
#define синийконец "\033[0m"
#include <iostream>
#include "include/room.h"

int main(){



User us;
us.name="test";
Room rm;
rm.name="all";
rm.users.push(us);

вывод<<"user "<<синий<<rm.users.top().name<<синийконец<<" in "<<rm.name<<конец;

return 0;

}
