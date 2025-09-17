#include "../philo.h"

uint64_t	get_time(void)
{
	struct	timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

void	example()
{
	uint64_t	start_time;
	uint64_t	now;
	
	start_time = get_time();
	usleep(2000000);
	now = get_time();
	printf("%ld passed since the start\n", now - start_time);
}
