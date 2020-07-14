#include "butterfly.h"

Butterfly::Butterfly()
{
    up=true;
    pix_up.load("");
    pix_down.load("");

    startTimer(100);
}
