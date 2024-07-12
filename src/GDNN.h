#pragma once

#include <godot_cpp/classes/object.hpp>
#include "NN.h"

namespace godot {
	class GDNN : public Object
	{
		GDCLASS(GDNN, Object)

	private:
		NN n;

	protected:
		static void _bind_methods();

	public:
		GDNN(NN n);
		size_t get_input_length();
		size_t get_output_length();
		void set_stateful(bool stateful);
		
		data_t* execute(data_t* input);
	};
}
