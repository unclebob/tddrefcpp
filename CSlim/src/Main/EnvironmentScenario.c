#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "SlimList.h"
#include "Fixtures.h"

typedef struct EnvironmentScenario
{
	int minute;

} EnvironmentScenario;

void* EnvironmentScenario_Create(void* errorHandler, SlimList* args)
{
	EnvironmentScenario* self = malloc(sizeof(EnvironmentScenario));
	memset(self, 0, sizeof(EnvironmentScenario));
	return self;
}

void EnvironmentScenario_Destroy(void* void_self)
{
	free(void_self);
}

static char* setMinute(void* void_self, SlimList* args) {
	EnvironmentScenario* self = (EnvironmentScenario*)void_self;
	self->minute = atoi(SlimList_GetStringAt(args, 0));
	return "";
}

static char* setTemp(void* void_self, SlimList* args) {
		return SLIM_EXCEPTION("You have to implement this one.");
}


CREATE_FIXTURE(EnvironmentScenario) 
	FUNCTION(setMinute)
	FUNCTION(setTemp)
END