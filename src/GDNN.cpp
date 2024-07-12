#include "GDNN.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDNN::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_input_length"), &GDNN::get_input_length);
	ClassDB::bind_method(D_METHOD("get_output_length"), &GDNN::get_output_length);
	ClassDB::bind_method(D_METHOD("set_stateful", "stateful"), &GDNN::set_stateful);
	ClassDB::bind_method(D_METHOD("execute", "input"), &GDNN::execute);
}

GDNN::GDNN(NN n)
{
	this->n = n;
}

size_t GDNN::get_input_length()
{
	return n.get_input_length();
}

size_t GDNN::get_output_length()
{
	return n.get_output_length();
}

void GDNN::set_stateful(bool stateful)
{
	n.stateful = true;
}

data_t* execute(data_t* input)
{
	return n.inference_execute(input);
}
