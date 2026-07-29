#include <stdio.h>

#include "logger.h"

/* Logs are written to app.log instead of stdout so the
   console output (menus, routes) stays clean. */

static void writeLog(const char *level, const char *msg)
{
    FILE *fp = fopen("app.log", "a");

    if(fp == NULL)
    {
        return;
    }

    fprintf(fp, "[%s] %s\n", level, msg);

    fclose(fp);
}

void logInfo(const char *msg)
{
    writeLog("INFO", msg);
}

void logWarning(const char *msg)
{
    writeLog("WARNING", msg);
}

void logError(const char *msg)
{
    writeLog("ERROR", msg);
}
