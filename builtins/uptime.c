#include <stdio.h>
#include <sys/sysinfo.h>

#include "uptime.h"

void uptime()
{
	struct sysinfo sinfo;

	sysinfo(&sinfo);

	unsigned int uptime = sinfo.uptime;

	unsigned int hour = uptime / 3600;
	unsigned int min = (uptime % 3600) / 60;

	if (hour == 0)
		printf("Kernel is up about %02d minutes\n", min);
	else
		printf("Kernel is up about %02d:%02d hours\n", hour, min);
}
