#ifndef _BUCHE_H_
#define _BUCHE_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define BUCHE_BUFFER_SIZE (1<<5)
//This function is based on lttng-tools debugging macros
// http://git.lttng.org/?p=lttng-tools.git;a=blob;f=src/common/error.c
static inline
void stringify_time(char *buff)
{
	struct tm tm;
	struct timespec tp;
	time_t now;
	clock_gettime(CLOCK_REALTIME, &tp);

	now = (time_t) tp.tv_sec;

	localtime_r(&now, &tm);

	snprintf(buff, BUCHE_BUFFER_SIZE, "%02d:%02d:%02d.%09ld",
			tm.tm_hour, tm.tm_min, tm.tm_sec, tp.tv_nsec);
}
#define BUCHE(fmt, args...) \
    do{ 				\
	char buff[BUCHE_BUFFER_SIZE]; \
    	stringify_time(buff);	\
	fprintf(stderr,"%s - " fmt " - [%s() %s +%d]\n",buff,## args,__func__, __FILE__, __LINE__);	\
    } while (0);

#endif // _BUCHE_H_
