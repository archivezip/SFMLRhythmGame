#include "../Chart.h"

Chart::Chart(const char* filename)
{
	if (!openFromFile(filename)) {}
}