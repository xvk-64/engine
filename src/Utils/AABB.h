#pragma once

#include <glm/vec3.hpp>
#include <glm/common.hpp>

// Axis-Aligned Bounding Box
struct AABB {
public:
	glm::vec3 Center = glm::vec3(0.0f);
	glm::vec3 HalfWidths = glm::vec3(0.5f);


	// Does the AABB overlap another AABB?
	bool Test(const AABB& other) const {
		return
			this->Center.x - this->HalfWidths.x <= other.Center.x + other.HalfWidths.x &&
			this->Center.x + this->HalfWidths.x >= other.Center.x - other.HalfWidths.x &&
			this->Center.y - this->HalfWidths.y <= other.Center.y + other.HalfWidths.y &&
			this->Center.y + this->HalfWidths.y >= other.Center.y - other.HalfWidths.y &&
			this->Center.z - this->HalfWidths.z <= other.Center.z + other.HalfWidths.z &&
			this->Center.z + this->HalfWidths.z >= other.Center.z - other.HalfWidths.z;
	}

	// Gets collision depth
	glm::vec3 CollisionDepth(const AABB& other) const {
		auto depth = glm::vec3(0.0f);

		for (int axis = 0; axis < 3; ++axis) {
			if (this->Center[axis] < other.Center[axis])
				depth[axis] = this->Center[axis] + this->HalfWidths[axis] - (other.Center[axis] - other.HalfWidths[axis]);
			else
				depth[axis] = other.Center[axis] + other.HalfWidths[axis] - (this->Center[axis] - this->HalfWidths[axis]);

			depth[axis] = glm::max(depth[axis], 0.0f);
		}

		return depth;
	}
};
