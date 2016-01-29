/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#include "zproto_example.h"
#include <iostream>

int main()
{
    MsgLog log;
    std::cout << log.version() << log.host().data() << log.const_host().data() << std::endl;
    frames f;
    f << log;
    return 0;
}
