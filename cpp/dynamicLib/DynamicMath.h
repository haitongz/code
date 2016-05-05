#pragma once
class StaticMath
{
  public:
    StaticMath(void);
    ~StaticMath(void);

    static double add(double a, double b);//加法
    static double sub(double a, double b);//减法

    void print();
};
