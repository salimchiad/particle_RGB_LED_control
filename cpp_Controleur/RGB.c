#include <stdlib.h>
#include <stdio.h>

void color(char *color)
{
	char *URL = "curl https://api.particle.io/v1/devices/<YOUR_DEVICE_ID>/led -d access_token=<ACCESS_GIVEN> -d params=";
	char *output;
	output = (char*)malloc(sizeof(char) * 1000);
	sprintf (output, "%s%s", URL, color);
	system (output);
	free (output);
}

int main (int argc, char **argv)
{
	int i;
	int cpm;
	cpm = 1;
	if (argc > 1)
	{
		cpm = atoi(argv[1]);
	}

	for (i = 0; i < cpm; i++)
	{
		color("RED");
		color("GREEN");
		color("BLUE");
		color("YELLOW");
		color("CYAN");
		color("VIOLET");
		color("WHITE");
	}
	color("OFF");
	return (0);
}
