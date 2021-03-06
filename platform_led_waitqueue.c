#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/* firstdrvtest on
  * firstdrvtest off
  */
int main(int argc, char **argv)
{
	int fd;
	int state;
	int val = 1;
	fd = open("/dev/platform_led", O_RDWR);
	if (fd < 0)
	{
		printf("can't open!\n");
	}
	if (argc != 2)
	{
		printf("Usage :\n");
		printf("%s <on|off>\n", argv[0]);
		return 0;
	}

	if (strcmp(argv[1], "on") == 0)
	{
		val  = 1;
		write(fd, &val, 4);
	}
	else if (strcmp(argv[1], "off") == 0)
	{
		val = 0;
		write(fd, &val, 4);
	}
	else if (strcmp(argv[1], "read") == 0)
	{
		read(fd, &state, 4);
		if (state == 1)
			printf("platform_led is on, state = %d\n",state);
		else
			printf("platform_led is off, state = %d\n", state);
	}
	
	return 0;
}
