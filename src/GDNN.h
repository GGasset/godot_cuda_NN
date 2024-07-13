#pragma once

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>

#include "array_conversion.h"
#include "NN.h"

namespace godot {
	/*enum CostFunctions : size_t;
	enum ActivationFunctions : size_t;
	enum NeuronTypes : size_t;
	enum ConnectionTypes : size_t;*/

	class GDNN : public Object
	{
		GDCLASS(GDNN, Object)

	private:
		NN n;

	protected:
		static void _bind_methods();

	public:
		GDNN();
		GDNN(NN n);
		size_t get_input_length();
		size_t get_output_length();
		void set_stateful(bool stateful);
		
		PackedFloat32Array execute(PackedFloat32Array input);
	};


}


/*VARIANT_ENUM_CAST(CostFunctions)
VARIANT_ENUM_CAST(ActivationFunctions)
VARIANT_ENUM_CAST(NN::ConnectionTypes)
VARIANT_ENUM_CAST(NN::NeuronTypes)*/
