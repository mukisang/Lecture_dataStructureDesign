#include <stdio.h>
#include "ALGraph.h"

int main(void)
{
	srand((int)time(NULL));
	ALGraph graph;
	int num = 5, xline = 100, yline = 100;
	GraphInit(&graph, num, xline, yline);
	Put_Me(&graph, num, xline, yline);
	Choose_wifi(&graph);
	show_wifi_list(&graph);
	Change_My_Position(&graph, num, xline, yline);
	show_wifi_list(&graph);
	return 0;
}