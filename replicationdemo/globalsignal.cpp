#include "globalsignal.h"

GlobalSignal* GlobalSignal::instance()
{
    static GlobalSignal s_inst;
    return &s_inst;
}
