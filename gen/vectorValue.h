#ifndef REFLECTION_VECTORVALUE_H
#define REFLECTION_VECTORVALUE_H

#include "../core/Vector3.h"
#include "../reflection/reflection.h"

namespace TypeFieldReflectionOperator{
    class TypeVectorValueOperator {
    public:
        static const char* getClassName(){ return "VectorValue";}

        static const char* getFieldName_id(){ return "id";}
        static const char* getFieldTypeName_id(){ return "int";}
        static void* get_id(void* instance){ return static_cast<void*>(&(static_cast<VectorValue*>(instance)->id));}
        static void set_id(void* instance, void* field_value){ static_cast<VectorValue*>(instance)->id = *static_cast<int*>(field_value);}
        static bool isArray_id(){ return 0;}
    };
}
void TypeWrapperRegister_VectorValue(){
    Pilot::filed_function_tuple* f_field_function_tuple=new Pilot::filed_function_tuple(
            &TypeFieldReflectionOperator::TypeVectorValueOperator::set_id,
            &TypeFieldReflectionOperator::TypeVectorValueOperator::get_id,
            &TypeFieldReflectionOperator::TypeVectorValueOperator::getClassName,
            &TypeFieldReflectionOperator::TypeVectorValueOperator::getFieldName_id,
            &TypeFieldReflectionOperator::TypeVectorValueOperator::getFieldTypeName_id,
            &TypeFieldReflectionOperator::TypeVectorValueOperator::isArray_id
            );

    Pilot::Reflection::TypeMetaRegisterinterface::registerToFieldMap("VectorValue", f_field_function_tuple);
}


#endif //REFLECTION_VECTORVALUE_H
