/* rt.cc
   Jeremy Barnes, 11 January 2011
   Copyright (c) 2011 Recoset.  All rights reserved.

   Real-time utilities.
*/

#include "rt.h"

namespace ML {

bool makeThreadRealTime(boost::thread & thread,
                        int priority)
{
    struct sched_param sched;
    sched.sched_priority = priority;

    int res = pthread_setschedparam(thread.native_handle(), SCHED_RR,
                                    &sched);
    if (res != 0) {
        //cerr << "error setting realtime priority for thread: "
        //     << strerror(errno) << endl;
        return false;
    }

    return true;
}

} // namespace ML

