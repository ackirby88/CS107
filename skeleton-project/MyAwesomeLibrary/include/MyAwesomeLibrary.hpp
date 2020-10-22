/**
 * @file MyAwesomeLibrary.h
 * @author Andrew Kirby
 */

#ifndef MYAWESOMELIBRARY_H
#define MYAWESOMELIBRARY_H

/* header files */

/* system header files */
#ifndef DOXYGEN_IGNORE
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

    /* ========= */
    /* operators */
    /* ========= */
    inline const AutoDiff<T> operator+(const AutoDiff<T> &other) const {
        return AutoDiff<T>(v + other.val(), dv + other.dval());
    }

    inline AutoDiff& operator+=(const AutoDiff<T> &other) {
        v += other.val();
        dv += other.dval();
        return *this;
    }

};

//template<typename T>
//inline const AutoDiff<T> operator+(AutoDiff<T> &lhs, const AutoDiff<T> &rhs){
//    return AutoDiff<T>(lhs.v + rhs.v, lhs.dv + rhs.dv);
//}

#endif /* MYAWESOMELIBRARY_H */
