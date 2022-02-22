class octopus
{
    virtual double module() = 0;
};

class cuttlefish
{
    virtual int test() = 0;
};

class vector: public octopus, public cuttlefish
{
    double x;
    double y;
    
    double module ()
    {
        return sqrt (x * x + y * y);
    }
    
    int test ()
    {
        if (x > y) return 1;
        else return 0;
    }
}