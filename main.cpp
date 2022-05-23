#include <iostream>
#include "gen/vector3_gen.h"
#include "gen/vectorValue.h"

using namespace std;

void printInstance(Pilot::Reflection::ReflectionInstance& rinstance, void* instance)
{
    Pilot::Reflection::FieldAccessor* fields;
    int fields_count = rinstance.m_meta.getFieldsList(fields);

    for (size_t index = 0; index < fields_count; index++)
    {
        auto fields_count = fields[index];
        cout<< "FieldTypeName:  "  << fields_count.getFieldTypeName() 
            << "    FieldName:  " << fields_count.getFieldName()
            << "    FieldValue:  " << *(int *)(fields_count.get(instance)) << endl;
    }
}

void travelInstance(Pilot::Reflection::ReflectionInstance& rinstance, void* instance)
{
    Pilot::Reflection::ReflectionInstance* reflection_instance;
    int count = rinstance.m_meta.getBaseClassReflectionInstanceList(reflection_instance, rinstance.m_instance);
    for (int index = 0; index < count; index++)
    {
        travelInstance(reflection_instance[index], instance);
    }
    printInstance(rinstance, instance);
}

int main() {
    // register class in Pilot::Reflection
    TypeWrapperRegister_VectorValue(); 
    // "VectorValue" instance ptr
    void* vector_value = new VectorValue;
    Pilot::Reflection::ReflectionInstance vector_value_instance = Pilot::Reflection::ReflectionInstance(Pilot::Reflection::TypeMeta::newMetaFromName("VectorValue"),vector_value);
    printInstance(vector_value_instance, vector_value);

    // TypeWrapperRegister_Vector3();
    // // "Vector3" instance ptr
    // void* vector3 = new Vector3();
    // Pilot::Reflection::ReflectionInstance vector3_instance = Pilot::Reflection::ReflectionInstance(Pilot::Reflection::TypeMeta::newMetaFromName("Vector3"),vector3);
    // travelInstance(vector3_instance, vector3);
    

    // cout << "------------------set--------------------" << endl;
    // float x = 123;
    // object_instance.m_meta.getFieldByName("x").set(v, &x);
    // travelInstance(object_instance, v);
    return 0;
}