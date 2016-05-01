/*
 * log.c
 *
 *  Created on: 25/4/2016
 *      Author: utnso
 */

#include <stdio.h>
#include <stdlib.h>
#include <commons/string.h>
#include <commons/log.h>
#include "log.h"

void iniciarLog()
{
	log_info(bgLogger,"\n\n***** Log de %s *****\n\n",bgLogger->program_name);
}

void crearLogs(char* logname, char* procName)
{
	activeLogger = log_create(string_from_format("%s.log",logname),procName,true,LOG_LEVEL_INFO);
	bgLogger = log_create(string_from_format("%s.log",logname),procName,false,LOG_LEVEL_DEBUG);
	iniciarLog();
}

void destruirLogs()
{
	log_destroy(activeLogger);
	log_destroy(bgLogger);
}