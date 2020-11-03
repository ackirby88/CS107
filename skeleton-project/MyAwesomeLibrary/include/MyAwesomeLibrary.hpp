/**
 * @file MyAwesomeLibrary.h
 * @author Andrew Kirby
 */

#ifndef MYAWESOMELIBRARY_H
#define MYAWESOMELIBRARY_H

/* header files */

/* system header files */
#ifndef DOXYGEN_IGNORE
#  include <stdio.h>
#endif


/* =============== */
/* Data Structures */
/* =============== */
template <class T>
class AutoDiff {
  private:
    T v;    /**< value */
    T dv;   /**< derivative value */

  public:

    /* constructors */
    AutoDiff(){};
    AutoDiff(T val,T dval) : v(val),dv(dval) {};

    /* getters */
    T val() const {return v;};
    T dval() const {return dv;};

    /* setters */
    void setval(T val){v = val;}
    void setdval(T dval){dv = dval;}

    void print_hello() const;

    /* ==================== */
    /* overloaded operators */
    /* ==================== */
    const AutoDiff<T> operator+(const AutoDiff<T> &other) const{
        return AutoDiff<T>(v + other.val(), dv + other.dval());
    }

    AutoDiff<T>& operator+=(const AutoDiff<T> &other){
        v += other.val();
        dv += other.dval();
        return *this;
    }
};

#endif /* MYAWESOMELIBRARY_H */
