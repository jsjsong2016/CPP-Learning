class CType {
public:
    int value;
    CType():value(0) {};
    void setvalue(int n) {
        value = n;
    }
    //必须使用static变量
    CType &operator++(int) {
        static CType tmp = CType();
        tmp.value = value;
        value *= value;
        return tmp;
    }

    friend ostream & operator<<(ostream &o, CType &cType) {
        o<<cType.value;
        return o;
    }

};
