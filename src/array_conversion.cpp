#include "array_conversion.h"
using namespace godot;

PackedFloat32Array to_packed_array(float* array, size_t value_count)
{
	PackedFloat32Array output = PackedFloat32Array();
	for (size_t i = 0; i < value_count; i++)
		output.append(array[i]);
	return output;
}

float* to_pointer(PackedFloat32Array array)
{
	size_t value_count = array.size();
	float* output = new float[value_count];
	for (size_t i = 0; i < value_count; i++)
		output[i] = array[i];
	return output;
}
