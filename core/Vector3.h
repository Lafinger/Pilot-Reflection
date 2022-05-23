#ifndef CMAKETEST_VECTOR3_H
#define CMAKETEST_VECTOR3_H

class VectorValue
{
public:
    int id = 0;
};

class Vector3 : public VectorValue
{
public:
    float x {0.f};
    float y {0.f};
};


#endif //CMAKETEST_VECTOR3_H
