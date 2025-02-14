#ifndef MANAGER
#define MANAGER

#include <stdbool.h>

#include "../renderer/layer/manager.h"



typedef struct Collision {
	/// @brief The layer which you want to check 
	int layer;

	/// @brief The characters that trigger collision with the layer
	char *target;
} Collision;

typedef struct CollisionList {
	Collision *list;
} CollisionList;

bool collision_collides(LayerManager lm, int subjectlayer);

#endif
