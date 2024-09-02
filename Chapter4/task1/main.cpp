#include "main.hpp"

int	main(void)
{
	int		serviceCompletionTimes[10] = { 3, 6, 4, 5, 2, 7, 8, 1, 9, 10 };
	int		arrivalTime = 4;
	System	sys(serviceCompletionTimes, 10, arrivalTime);

	sys.runCPUQueue();
	return (0);
}
