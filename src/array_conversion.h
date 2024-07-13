#ifndef ARRAY_CONVERSION_H
#define ARRAY_CONVERSION_H

#include <godot_cpp/variant/packed_float32_array.hpp>
namespace godot {

	
	PackedFloat32Array to_packed_array(float* array, size_t value_count);
	float* to_pointer(PackedFloat32Array array);


}
#endif
