#ifndef _BUCHE_H_
#define _BUCHE_H_

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//This function is based on lttng-tools debugging macros
// http://git.lttng.org/?p=lttng-tools.git;a=blob;f=src/common/error.c
static
void stringify_time(char *buff)
{
	struct tm tm;
	struct timespec tp;
	time_t now;
	clock_gettime(CLOCK_REALTIME, &tp);

	now = (time_t) tp.tv_sec;

	localtime_r(&now, &tm);

	snprintf(buff, 512,"%02d:%02d:%02d.%06ld",
			tm.tm_hour, tm.tm_min, tm.tm_sec, tp.tv_nsec);
}
#define BUCHE(fmt, args...) \
    do{ 				\
	char* buff = malloc(sizeof(char)*512); \
    	stringify_time(buff);	\
	fprintf(stderr, "%s",buff); 		\
	fprintf(stderr, " - "); 	\
	fprintf(stderr, fmt,## args);	\
	fprintf(stderr," - [%s() %s +%d]\n",__func__, __FILE__,__LINE__);	\
	free(buff);			\
    } while (0);


#endif // _BUCHE_H_
