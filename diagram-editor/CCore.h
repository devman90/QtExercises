#ifndef CCORE_H
#define CCORE_H

class CCorePrivate;

class CCore
{
public:
    CCore();
    ~CCore();

private:
    CCorePrivate* d_ptr;
};

#endif // CCORE_H
