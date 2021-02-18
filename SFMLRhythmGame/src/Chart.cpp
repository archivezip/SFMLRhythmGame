#include "../Chart.h"
#include "../Log.h"

Chart::Chart(const char* filename)
{
	if (!openFromFile(filename)) { LOG_ERROR("Chart not found under filename: {0}", filename); }
}