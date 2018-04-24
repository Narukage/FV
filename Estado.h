#include <iostream>

class Estado{
public:
    static Estado* Instance();
protected:
    Estado();
    Estado(const Estado &);
    Estado &operator=(const Estado &);
private:
    static Estado* pinstance;
    void update();
    void IAupdate();
};