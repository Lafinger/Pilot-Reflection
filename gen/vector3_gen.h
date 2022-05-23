#ifndef CMAKETEST_VECTOR3_GEN_H
#define CMAKETEST_VECTOR3_GEN_H

#include "../core/Vector3.h"
#include "../reflection/reflection.h"

namespace TypeFieldReflectionOperator{
    class TypeVector3Operator {
    public:
        static const char* getClassName(){ return "Vector3";}

        static const char* getFieldName_x(){ return "x";}
        static const char* getFieldTypeName_x(){ return "float";}
        static void set_x(void* instance, void* field_value){ static_cast<Vector3*>(instance)->x = *static_cast<float*>(field_value);}
        static void* get_x(void* instance){ return static_cast<void*>(&(static_cast<Vector3*>(instance)->x));}
        static bool isArray_x(){ return 0;}

        static const char* getFieldName_y(){ return "y";}
        static const char* getFieldTypeName_y(){ return "float";}
        static void set_y(void* instance, void* field_value){ static_cast<Vector3*>(instance)->y = *static_cast<float*>(field_value);}
        static void* get_y(void* instance){ return static_cast<void*>(&(static_cast<Vector3*>(instance)->y));}
        static bool isArray_y(){ return 0;}

        static int getVector3BaseClassReflectionInstanceList(Pilot::Reflection::ReflectionInstance* &out_list, void* instance){
            int count = 1;
            out_list = new Pilot::Reflection::ReflectionInstance[count];
            for (int i=0;i<count;++i){
                out_list[i] = TypeMetaDef(VectorValue, static_cast<Vector3*>(instance));
            }
            return count;
        }
    };
}

void TypeWrapperRegister_Vector3(){
    Pilot::filed_function_tuple* f_field_function_tuple_x=new Pilot::filed_function_tuple(
            &TypeFieldReflectionOperator::TypeVector3Operator::set_x,
            &TypeFieldReflectionOperator::TypeVector3Operator::get_x,
            &TypeFieldReflectionOperator::TypeVector3Operator::getClassName,
            &TypeFieldReflectionOperator::TypeVector3Operator::getFieldName_x,
            &TypeFieldReflectionOperator::TypeVector3Operator::getFieldTypeName_x,
            &TypeFieldReflectionOperator::TypeVector3Operator::isArray_x);
    Pilot::Reflection::TypeMetaRegisterinterface::registerToFieldMap("Vector3", f_field_function_tuple_x);

    Pilot::filed_function_tuple* f_field_function_tuple_y=new Pilot::filed_function_tuple(
            &TypeFieldReflectionOperator::TypeVector3Operator::set_y,
            &TypeFieldReflectionOperator::TypeVector3Operator::get_y,
            &TypeFieldReflectionOperator::TypeVector3Operator::getClassName,
            &TypeFieldReflectionOperator::TypeVector3Operator::getFieldName_y,
            &TypeFieldReflectionOperator::TypeVector3Operator::getFieldTypeName_y,
            &TypeFieldReflectionOperator::TypeVector3Operator::isArray_y);
    Pilot::Reflection::TypeMetaRegisterinterface::registerToFieldMap("Vector3", f_field_function_tuple_y);

    Pilot::class_function_tuple* f_class_function_tuple_Vector_Parameter=new Pilot::class_function_tuple(
            &TypeFieldReflectionOperator::TypeVector3Operator::getVector3BaseClassReflectionInstanceList);
    Pilot::Reflection::TypeMetaRegisterinterface::registerToClassMap("Vector3", f_class_function_tuple_Vector_Parameter);
}


#endif //CMAKETEST_VECTOR3_GEN_H
